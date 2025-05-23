﻿#pragma once
#include "Config.hpp"
#include "ModelInfo.h"
#include <string>
#include <map>
#include <SDL.h>
#include <SDL_image.h>

#include <mutex>
#include <thread>
#include <condition_variable>
#include <queue>

namespace casioemu
{
	class Chipset;
	class CPU;
	class MMU;

	/**
	 * A mutex that ensures that a thread cannot get the mutex right after it's released if there are another waiting thread.
	 */
	class FairRecursiveMutex
	{
		std::mutex m;
		std::thread::id holding;
		int recursive_count;
		std::queue<std::condition_variable> waiting;

	public:
		FairRecursiveMutex();
		~FairRecursiveMutex();
		void lock();
		void unlock();
	};

	class Emulator
	{
    public:
		SDL_Renderer *renderer;
		SDL_Surface* interface_surface;
		SDL_Texture *interface_texture;
		unsigned int cycles_per_second;
		unsigned int timer_interval;
		bool running, paused;
		unsigned int last_frame_tick_count;
		std::string model_path;
		bool pause_on_mem_error;

		std::thread *tick_thread;

		SpriteInfo interface_background;
		SDL_Rect emu_rect{};

		/**
		 * A bunch of internally used methods for encapsulation purposes.
		 */
		void LoadModelDefition();
		void TimerCallback();
		void SetupLuaAPI();
		void SetupInternals();
		void RunStartupScript();

	public:
		ModelInfo modeldef{};
		SDL_Window *window;
		Emulator(std::map<std::string, std::string> &argv_map, bool paused = false);
		~Emulator();

		FairRecursiveMutex access_mx;
		HardwareId hardware_id;
		std::map<std::string, std::string> &argv_map;

	// private:
	public:
		/**
		 * The cycle manager structure. This structure is reset every time the
		 * emulator starts emulating CPU cycles and in every timer callback
		 * it's queried for the number of cycles that need to be emulated in the
		 * callback. This ensures that only as many cycles are emulated in a period
		 * of time as many would be in real life.
		 *
		 * Note that it's assumed that the GetDelta function is called once every
		 * timer_interval milliseconds. It's up to the timer to make sure that
		 * there's no drift.
		 */
		struct Cycles
		{
			void Setup(Uint64 cycles_per_second, unsigned int timer_interval);
			void Reset();
			Uint64 GetDelta();
			Uint64 ticks_now, cycles_emulated, cycles_per_second;
			unsigned int timer_interval;
		} cycles;
		/**
		 * A reference to the emulator chipset. This object holds all CPU, MMU, memory and
		 * peripheral state. The emulator interfaces with the chipset by issuing interrupts
		 * and rendering the screen buffer. It may also read internal state for testing purposes.
		 */
		Chipset &chipset;

		float BatteryVoltage, SolarPanelVoltage;

		bool Running();
		void HandleMemoryError();
		void Shutdown();
		void Tick();
		/**
		 * Called when SDL_WINDOWEVENT_EXPOSED event is received. Does not re-frame.
		 */
		void Repaint();
		void Frame();
		void WindowResize(int width, int height);
		void ExecuteCommand(std::string command);
		unsigned int GetCyclesPerSecond();
		void SetClockSpeed(float speed);
		bool GetPaused();
		void SetPaused(bool paused);
		void UIEvent(SDL_Event &event);
		SDL_Renderer *GetRenderer();
		SDL_Texture *GetInterfaceTexture();
		std::string GetModelFilePath(std::string relative_path);

		friend class CPU;
		friend class MMU;
	};
}
