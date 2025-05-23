﻿#pragma once
#include <vector>
#include "Gui/hex.hpp"
#include "ModelInfo.h"

namespace casioemu {
	inline constexpr size_t GetRamBaseAddr(HardwareId hid) {
		return hid == HW_ES_PLUS ? 0x8000 : hid == HW_CLASSWIZ ? 0xD000
										: hid == HW_FX_5800P	   ? 0x8000
															   : 0x9000;
	}
	inline constexpr size_t GetRamSize(HardwareId hid) {
		return hid == HW_ES_PLUS ? 0x0E00 : hid == HW_CLASSWIZ ? 0x2000
										: hid == HW_FX_5800P	   ? 0xf000 - 0x8000
															   : 0x6000;
	}
	inline std::vector<MemoryEditor::MarkedSpan> GetCommonMemLabels(HardwareId hid) {
		int i = 0;
#define SColor \
	i++ % 2 ? ImColor{ 40, 120, 40, 255 } : ImColor { 40, 40, 120, 255 }
		switch (hid) {
		case HardwareId::HW_CLASSWIZ_II: {
			size_t v = 0x9188;
#if LANGUAGE == 2
			return {
				MemoryEditor::MarkedSpan{ v, 0x2, SColor, "VctA(a*b)" },
				MemoryEditor::MarkedSpan{ v += 2, 0x2, SColor, "VctB(a*b)" },
				MemoryEditor::MarkedSpan{ v += 2, 0x2, SColor, "VctC(a*b)" },
				MemoryEditor::MarkedSpan{ v += 2, 0x2, SColor, "VctD(a*b)" },
				MemoryEditor::MarkedSpan{ v += 2, 0x2, SColor, "MatAns(a*b)" },
				MemoryEditor::MarkedSpan{ v += 2, 0x2, SColor, "MatAns虚数部分/FB2A(a*b)" },
				MemoryEditor::MarkedSpan{ v += 2, 0x2, SColor, "FB2B(a*b)" },
				MemoryEditor::MarkedSpan{ v += 2, 0x2, SColor, "FB2C(a*b)" },
				MemoryEditor::MarkedSpan{ v += 2, 0x2, SColor, "FB2D(a*b)" },
				MemoryEditor::MarkedSpan{ v += 2, 0x2, SColor, "FB2E(a*b)" },
				MemoryEditor::MarkedSpan{ v += 2, 0x2, SColor, "FB2F(a*b)" },
				MemoryEditor::MarkedSpan{ 0x919E, 0x2, SColor, " 输入的字符(小端) " },
				MemoryEditor::MarkedSpan{ 0x91EE, 0x2, SColor, " 输入的字符(小端)(2) " },
				MemoryEditor::MarkedSpan{ 0x91F0, 0x1, SColor, " 光标字符位置备份 " },
				MemoryEditor::MarkedSpan{ 0xF800, 0x800, SColor, " 屏幕缓冲区 " },
				MemoryEditor::MarkedSpan{ 0xCA54, 0x1800, SColor, " 屏幕缓冲区2 " },
				MemoryEditor::MarkedSpan{ 0xE254, 0xF000 - 0xE254, SColor, " 栈 " },
				MemoryEditor::MarkedSpan{ 0x91A0, 0x1, SColor, " 按键修饰符 " },
				MemoryEditor::MarkedSpan{ 0x91A1, 0x1, SColor, " 模式 " },
				MemoryEditor::MarkedSpan{ 0x91A2, 0x1, SColor, " 子模式 " },
				MemoryEditor::MarkedSpan{ 0x91A3, 0x1, SColor, " 屏幕状态(0:输入公式,1:主屏幕,3:其他菜单) " },
				MemoryEditor::MarkedSpan{ 0x91A4, 0x1, SColor, " 界面?反正和屏幕有关就对了 " },
				MemoryEditor::MarkedSpan{ 0x91A6, 0x1, SColor, " 是否闪烁光标 " },
				MemoryEditor::MarkedSpan{ 0x91AA, 0x1, SColor, " 数字格式设置 " },
				MemoryEditor::MarkedSpan{ 0x91AB, 0x1, SColor, " 数字格式设置2 " },
				MemoryEditor::MarkedSpan{ 0x91AC, 0x1, SColor, " 小数点类型 " },
				MemoryEditor::MarkedSpan{ 0x91AD, 0x1, SColor, " 角度单位设置 " },
				MemoryEditor::MarkedSpan{ 0x91AE, 0x1, SColor, " 数学模式开关 " },
				MemoryEditor::MarkedSpan{ 0x91AF, 0x1, SColor, " 分数类型 " },
				MemoryEditor::MarkedSpan{ 0x91B0, 0x1, SColor, " 复数类型 " },
				MemoryEditor::MarkedSpan{ 0x91B1, 0x1, SColor, " 频数 " },
				MemoryEditor::MarkedSpan{ 0x91B2, 0x1, SColor, " 10的幂的类型 " },
				MemoryEditor::MarkedSpan{ 0x91B3, 0x1, SColor, " 自动化简 " },
				MemoryEditor::MarkedSpan{ 0x91B4, 0x1, SColor, " 小数输出开关 " },
				MemoryEditor::MarkedSpan{ 0x91B5, 0x1, SColor, " 自动关机时长(1=60min) " },
				MemoryEditor::MarkedSpan{ 0x91B6, 0x1, SColor, " 函数表格类型 " },
				MemoryEditor::MarkedSpan{ 0x91B7, 0x1, SColor, " 工程符号 " },
				MemoryEditor::MarkedSpan{ 0x91B8, 0x1, SColor, " 数字分隔符 " },
				MemoryEditor::MarkedSpan{ 0x91B9, 0x1, SColor, " 字体设置(真) " },
				MemoryEditor::MarkedSpan{ 0x91BA, 0x1, SColor, " 解方程复数根 " },
				MemoryEditor::MarkedSpan{ 0x91BB, 0x1, SColor, " 语言设置 " },
				MemoryEditor::MarkedSpan{ 0x91BC, 0x1, SColor, " 自动计算 " },
				MemoryEditor::MarkedSpan{ 0x91BD, 0x1, SColor, " 数据表格显示 " },
				MemoryEditor::MarkedSpan{ 0x91BE, 0x1, SColor, " 二维码类型(3或11) " },
				MemoryEditor::MarkedSpan{ 0x91BF, 0x1, SColor, " 算法背景 " },
				MemoryEditor::MarkedSpan{ 0x91C0, 0x1, SColor, " 算法单位 " },
				MemoryEditor::MarkedSpan{ 0x91C2, 0x1, SColor, " 光标图形 " },
				MemoryEditor::MarkedSpan{ 0x91C3, 0x1, SColor, " 光标大小 " },
				MemoryEditor::MarkedSpan{ 0x91C4, 0x1, SColor, " 表格滚动开始 " },
				MemoryEditor::MarkedSpan{ 0x91C5, 0x1, SColor, " 表格光标行位置 " },
				MemoryEditor::MarkedSpan{ 0x91C6, 0x1, SColor, " 表格光标列位置" },
				MemoryEditor::MarkedSpan{ 0x91C7, 0x1, SColor, " 光标大小(?) " },
				MemoryEditor::MarkedSpan{ 0x91D0, 0x1, SColor, " 滚动Y轴 " },
				MemoryEditor::MarkedSpan{ 0x91D4, 0x2, SColor, " 显示指针 " },
				MemoryEditor::MarkedSpan{ 0x91E0, 0x2, SColor, " 上一次的KI和KO " },
				MemoryEditor::MarkedSpan{ 0x91E3, 0x1, SColor, " 对比度 " },
				MemoryEditor::MarkedSpan{ 0x91E5, 0x1, SColor, " 光标字符位置 " },
				MemoryEditor::MarkedSpan{ 0x91E8, 0x1, SColor, " 光标X轴 " },
				MemoryEditor::MarkedSpan{ 0x91E9, 0x1, SColor, " 光标Y轴 " },
				MemoryEditor::MarkedSpan{ 0x91EA, 0x1, SColor, " 线性滚动开始值（数学模式不使用） " },
				MemoryEditor::MarkedSpan{ 0x91F1, 0x1, SColor, " 菜单图标 " },
				MemoryEditor::MarkedSpan{ 0x91F8, 0x1, SColor, " 光标大小 " },
				MemoryEditor::MarkedSpan{ 0x91FD, 0x1, SColor, " 函数界面 " },
				MemoryEditor::MarkedSpan{ 0x91FF, 0x1, SColor, " 变量设置界面(大于1启用) " },
				MemoryEditor::MarkedSpan{ 0x9200, 0x1, SColor, " 变量设置界面(变量编号) " },
				MemoryEditor::MarkedSpan{ 0x9201, 0x1, SColor, " 验算模式 " },
				MemoryEditor::MarkedSpan{ 0x9207, 0x1, SColor, " 阻止进入自检 " },
				MemoryEditor::MarkedSpan{ 0x9206, 0x1, SColor, " 自检正确次数 " },
				MemoryEditor::MarkedSpan{ 0x9205, 0x1, SColor, " 自检次数 " },
				MemoryEditor::MarkedSpan{ 0x924C, 0xE, SColor, "Ans" },
				MemoryEditor::MarkedSpan{ 0x925A, 0xE, SColor, "Ans i" },
				MemoryEditor::MarkedSpan{ 0x9268, 200, SColor, "输入区" },
				MemoryEditor::MarkedSpan{ 0x9268 + 200, 200, SColor, "缓冲区" },
				MemoryEditor::MarkedSpan{ 0x9268 + 400, 400, SColor, "历史记录" },
				MemoryEditor::MarkedSpan{ 0x9268 + 800, 200, SColor, "结果区/分析区" },
				MemoryEditor::MarkedSpan{ 0x9650, 0xC, SColor, "随机数种子" },
				MemoryEditor::MarkedSpan{ 0x965C, 0x2, SColor, "不稳定字节" },
				MemoryEditor::MarkedSpan{ 0x965E, 0xE, SColor, "Ans" },
				MemoryEditor::MarkedSpan{ 0x966C, 0xE, SColor, "A" },
				MemoryEditor::MarkedSpan{ 0x967A, 0xE, SColor, "B" },
				MemoryEditor::MarkedSpan{ 0x9688, 0xE, SColor, "C" },
				MemoryEditor::MarkedSpan{ 0x9696, 0xE, SColor, "D" },
				MemoryEditor::MarkedSpan{ 0x96A4, 0xE, SColor, "E" },
				MemoryEditor::MarkedSpan{ 0x96B2, 0xE, SColor, "F" },
				MemoryEditor::MarkedSpan{ 0x96C0, 0xE, SColor, "x" },
				MemoryEditor::MarkedSpan{ 0x96CE, 0xE, SColor, "y" },
				MemoryEditor::MarkedSpan{ 0x96DC, 0xE, SColor, "z" },
				MemoryEditor::MarkedSpan{ 0x96EA, 0xE, SColor, "PreAns" },
				MemoryEditor::MarkedSpan{ 0x965E + 0xE * 11, 0xE, SColor, "Ans i" },
				MemoryEditor::MarkedSpan{ 0x966C + 0xE * 11, 0xE, SColor, "A i" },
				MemoryEditor::MarkedSpan{ 0x967A + 0xE * 11, 0xE, SColor, "B i" },
				MemoryEditor::MarkedSpan{ 0x9688 + 0xE * 11, 0xE, SColor, "C i" },
				MemoryEditor::MarkedSpan{ 0x9696 + 0xE * 11, 0xE, SColor, "D i" },
				MemoryEditor::MarkedSpan{ 0x96A4 + 0xE * 11, 0xE, SColor, "E i" },
				MemoryEditor::MarkedSpan{ 0x96B2 + 0xE * 11, 0xE, SColor, "F i" },
				MemoryEditor::MarkedSpan{ 0x96C0 + 0xE * 11, 0xE, SColor, "x i" },
				MemoryEditor::MarkedSpan{ 0x96CE + 0xE * 11, 0xE, SColor, "y i" },
				MemoryEditor::MarkedSpan{ 0x96DC + 0xE * 11, 0xE, SColor, "z i" },
				MemoryEditor::MarkedSpan{ 0x96EA + 0xE * 11, 0xE, SColor, "PreAns i" },
				MemoryEditor::MarkedSpan{ 0x97A2, 200, SColor, "f(x)" },
				MemoryEditor::MarkedSpan{ 0x986A, 200, SColor, "g(x)" },
				MemoryEditor::MarkedSpan{ 0x9932, 0xE * 80 * 2, SColor, "统计数据" },
				MemoryEditor::MarkedSpan{ 0xA1F2, 0x1, SColor, "统计数据模式(非0就是双数据统计)" },
				MemoryEditor::MarkedSpan{ 0xA1F4, 0x1, SColor, "统计数据条数" },
				MemoryEditor::MarkedSpan{ 0xA1F6, 0xE * 16, SColor, "MatA(数据)" },
				MemoryEditor::MarkedSpan{ 0xA1F6 + 0xE * 16 * 1, 0xE * 16, SColor, "MatB(数据)" },
				MemoryEditor::MarkedSpan{ 0xA1F6 + 0xE * 16 * 2, 0xE * 16, SColor, "MatC(数据)" },
				MemoryEditor::MarkedSpan{ 0xA1F6 + 0xE * 16 * 3, 0xE * 16, SColor, "MatD(数据)" },
				MemoryEditor::MarkedSpan{ 0xA576, 0x2, SColor, "MatA(a*b)" },
				MemoryEditor::MarkedSpan{ 0xA576 + 2, 0x2, SColor, "MatB(a*b)" },
				MemoryEditor::MarkedSpan{ 0xA576 + 2 * 2, 0x2, SColor, "MatC(a*b)" },
				MemoryEditor::MarkedSpan{ 0xA576 + 2 * 3, 0x2, SColor, "MatD(a*b)" },
				MemoryEditor::MarkedSpan{ 0xA57E, 0xE * 3, SColor, "VctA(数据)" },
				MemoryEditor::MarkedSpan{ 0xA57E + 0xE * 3 * 1, 0xE * 3, SColor, "VctB(数据)" },
				MemoryEditor::MarkedSpan{ 0xA57E + 0xE * 3 * 2, 0xE * 3, SColor, "VctC(数据)" },
				MemoryEditor::MarkedSpan{ 0xA57E + 0xE * 3 * 3, 0xE * 3, SColor, "VctD(数据)" },
				MemoryEditor::MarkedSpan{ 0xA626, 0x2, SColor, "VctA(a*b)" },
				MemoryEditor::MarkedSpan{ 0xA626 + 2, 0x2, SColor, "VctB(a*b)" },
				MemoryEditor::MarkedSpan{ 0xA626 + 2 * 2, 0x2, SColor, "VctC(a*b)" },
				MemoryEditor::MarkedSpan{ 0xA626 + 2 * 3, 0x2, SColor, "VctD(a*b)" },
				MemoryEditor::MarkedSpan{ 0xA62E, 0xE * 9, SColor, "分布模式变量" },
				MemoryEditor::MarkedSpan{ 0xB1CE, 900, SColor, "算法模式程序" },
				MemoryEditor::MarkedSpan{ 0xB552, 0xE * 7 + 2 * 6, SColor, "绘图模式变量" },
				MemoryEditor::MarkedSpan{ 0xA6AC, 2380, SColor, "数据表格数据" },
				MemoryEditor::MarkedSpan{ 0xA6AC + 2380, 2 * 45 * 5, SColor, "数据表格数据(标记，第一个字节是尾随字符串长度，第二个字节:D0==公式 80==数值 00==不存在)" },
				MemoryEditor::MarkedSpan{ 0xB1BA, 2, SColor, "数据表格数值大小" },
				MemoryEditor::MarkedSpan{ 0xB1BA + 2, 2, SColor, "数据表格公式大小" },
				MemoryEditor::MarkedSpan{ 0xB1BA + 4, 2, SColor, "数据表格总大小" },
				MemoryEditor::MarkedSpan{ 0xB1C2, 1, SColor, "数据表格存在" },
				MemoryEditor::MarkedSpan{ 0xB1C3, 1, SColor, "数据表格类型(1==纯数值 2==有公式)" },
				MemoryEditor::MarkedSpan{ 0xBDEC, 0xE, SColor, "Theta变量" },
				MemoryEditor::MarkedSpan{ 0xBA68, 3000, SColor, "激活的应用数据" },
				MemoryEditor::MarkedSpan{ 0x9186, 0x1, SColor, "激活的应用条目数量(统计/函数表格)" },
				MemoryEditor::MarkedSpan{ 0xC620, 0x10, SColor, "内存完整性检查(魔法字符串/Magic string)" },
				MemoryEditor::MarkedSpan{ 0xC860, 0x1F4, SColor, "寄存器备份(只在数学输入中使用)" },
			};
#else
			return {
				MemoryEditor::MarkedSpan{ v, 0x2, SColor, "Vct/MatA(ab)" },
				MemoryEditor::MarkedSpan{ v += 2, 0x2, SColor, "Vct/MatB(a*b)" },
				MemoryEditor::MarkedSpan{ v += 2, 0x2, SColor, "Vct/MatC(a*b)" },
				MemoryEditor::MarkedSpan{ v += 2, 0x2, SColor, "Vct/MatD(a*b)" },
				MemoryEditor::MarkedSpan{ v += 2, 0x2, SColor, "MatAns(a*b)" },
				MemoryEditor::MarkedSpan{ v += 2, 0x2, SColor, "MatAns Imaginary Part/FB1A(a*b)" },
				MemoryEditor::MarkedSpan{ v += 2, 0x2, SColor, "FB1B(a*b)" },
				MemoryEditor::MarkedSpan{ v += 2, 0x2, SColor, "FB1C(a*b)" },
				MemoryEditor::MarkedSpan{ v += 2, 0x2, SColor, "FB1D(a*b)" },
				MemoryEditor::MarkedSpan{ v += 2, 0x2, SColor, "FB1E(a*b)" },
				MemoryEditor::MarkedSpan{ v += 2, 0x2, SColor, "FB1F(a*b)" },
				MemoryEditor::MarkedSpan{ 0x919E, 0x2, SColor, " Input characters (little-endian) " },
				MemoryEditor::MarkedSpan{ 0x91EE, 0x2, SColor, " Input characters (little-endian)(2) " },
				MemoryEditor::MarkedSpan{ 0x91F0, 0x1, SColor, " Cursor character position backup " },
				MemoryEditor::MarkedSpan{ 0xF800, 0x800, SColor, " Screen buffer " },
				MemoryEditor::MarkedSpan{ 0xCA54, 0x1800, SColor, " Screen buffer2 " },
				MemoryEditor::MarkedSpan{ 0xE254, 0xF000 - 0xE254, SColor, " Stack " },
				MemoryEditor::MarkedSpan{ 0x91A0, 0x1, SColor, " Key modifiers " },
				MemoryEditor::MarkedSpan{ 0x91A1, 0x1, SColor, " Mode " },
				MemoryEditor::MarkedSpan{ 0x91A2, 0x1, SColor, " Submode " },
				MemoryEditor::MarkedSpan{ 0x91A3, 0x1, SColor, " Screen state (0:input formula, 1:main screen, 3:other menus) " },
				MemoryEditor::MarkedSpan{ 0x91A4, 0x1, SColor, " Interface? Anyway it's related to screen" },
				MemoryEditor::MarkedSpan{ 0x91A6, 0x1, SColor, " Whether to blink the cursor " },
				MemoryEditor::MarkedSpan{ 0x91AA, 0x1, SColor, " Numeric format settings " },
				MemoryEditor::MarkedSpan{ 0x91AB, 0x1, SColor, " Numeric format settings 2 " },
				MemoryEditor::MarkedSpan{ 0x91AC, 0x1, SColor, " Decimal type " },
				MemoryEditor::MarkedSpan{ 0x91AD, 0x1, SColor, " Angle unit setting " },
				MemoryEditor::MarkedSpan{ 0x91AE, 0x1, SColor, " Math mode switch " },
				MemoryEditor::MarkedSpan{ 0x91AF, 0x1, SColor, " Fraction type " },
				MemoryEditor::MarkedSpan{ 0x91B0, 0x1, SColor, " Complex number type " },
				MemoryEditor::MarkedSpan{ 0x91B1, 0x1, SColor, " Frequency " },
				MemoryEditor::MarkedSpan{ 0x91B2, 0x1, SColor, " Type of 10's exponent " },
				MemoryEditor::MarkedSpan{ 0x91B3, 0x1, SColor, " Automatic simplification " },
				MemoryEditor::MarkedSpan{ 0x91B4, 0x1, SColor, " Decimal output switch " },
				MemoryEditor::MarkedSpan{ 0x91B5, 0x1, SColor, " Automatic power-off duration (1=60min) " },
				MemoryEditor::MarkedSpan{ 0x91B6, 0x1, SColor, " Function table type " },
				MemoryEditor::MarkedSpan{ 0x91B7, 0x1, SColor, " Engineering symbols " },
				MemoryEditor::MarkedSpan{ 0x91B8, 0x1, SColor, " Numeric separator " },
				MemoryEditor::MarkedSpan{ 0x91B9, 0x1, SColor, " Font setting (true) " },
				MemoryEditor::MarkedSpan{ 0x91BA, 0x1, SColor, " Solve equation complex roots " },
				MemoryEditor::MarkedSpan{ 0x91BB, 0x1, SColor, " Language setting" },
				MemoryEditor::MarkedSpan{ 0x91BC, 0x1, SColor, " Automatic calculation " },
				MemoryEditor::MarkedSpan{ 0x91BD, 0x1, SColor, " Data table display " },
				MemoryEditor::MarkedSpan{ 0x91BE, 0x1, SColor, " Two-dimensional code type (3 or 11) " },
				MemoryEditor::MarkedSpan{ 0x91BF, 0x1, SColor, " Algorithm background " },
				MemoryEditor::MarkedSpan{ 0x91C0, 0x1, SColor, " Algorithm unit" },
				MemoryEditor::MarkedSpan{ 0x91C2, 0x1, SColor, " Cursor shape " },
				MemoryEditor::MarkedSpan{ 0x91C3, 0x1, SColor, " Cursor size " },
				MemoryEditor::MarkedSpan{ 0x91C4, 0x1, SColor, " Table scrolling start " },
				MemoryEditor::MarkedSpan{ 0x91C5, 0x1, SColor, " Table cursor row position " },
				MemoryEditor::MarkedSpan{ 0x91C6, 0x1, SColor, " Table cursor column position" },
				MemoryEditor::MarkedSpan{ 0x91C7, 0x1, SColor, " Cursor size(?) " },
				MemoryEditor::MarkedSpan{ 0x91D0, 0x1, SColor, " Scroll Y-axis " },
				MemoryEditor::MarkedSpan{ 0x91D4, 0x2, SColor, " Viewport Pointer " },
				MemoryEditor::MarkedSpan{ 0x91E0, 0x2, SColor, " Previous KI and KO " },
				MemoryEditor::MarkedSpan{ 0x91E3, 0x1, SColor, " Contrast " },
				MemoryEditor::MarkedSpan{ 0x91E5, 0x1, SColor, " Cursor character position " },
				MemoryEditor::MarkedSpan{ 0x91E8, 0x1, SColor, " Cursor X-axis " },
				MemoryEditor::MarkedSpan{ 0x91E9, 0x1, SColor, " Cursor Y-axis " },
				MemoryEditor::MarkedSpan{ 0x91EA, 0x1, SColor, " Linear scroll start value (not used in math mode) " },
				MemoryEditor::MarkedSpan{ 0x91F1, 0x1, SColor, " Menu icon " },
				MemoryEditor::MarkedSpan{ 0x91F8, 0x1, SColor, " Cursor size " },
				MemoryEditor::MarkedSpan{ 0x91FD, 0x1, SColor, " Function interface " },
				MemoryEditor::MarkedSpan{ 0x91FF, 0x1, SColor, " Variable settings interface (enable if > 1) " },
				MemoryEditor::MarkedSpan{ 0x9200, 0x1, SColor, " Variable settings interface (variable number) " },
				MemoryEditor::MarkedSpan{ 0x9201, 0x1, SColor, " Verification mode " },
				MemoryEditor::MarkedSpan{ 0x9207, 0x1, SColor, " Prevent entering self-test " },
				MemoryEditor::MarkedSpan{ 0x9206, 0x1, SColor, " Self-test correct count " },
				MemoryEditor::MarkedSpan{ 0x9205, 0x1, SColor, " Self-test count " },
				MemoryEditor::MarkedSpan{ 0x924C, 0xE, SColor, "Ans" },
				MemoryEditor::MarkedSpan{ 0x925A, 0xE, SColor, "Ans Imaginary Part/2nd Result" },
				MemoryEditor::MarkedSpan{ 0x9268, 200, SColor, "Input area" },
				MemoryEditor::MarkedSpan{ 0x9268 + 200, 200, SColor, "Buffer area" },
				MemoryEditor::MarkedSpan{ 0x9268 + 400, 400, SColor, "History area" },
				MemoryEditor::MarkedSpan{ 0x9268 + 800, 200, SColor, "Result area/Analysis area" },
				MemoryEditor::MarkedSpan{ 0x9650, 0xC, SColor, "Random number seed" },
				MemoryEditor::MarkedSpan{ 0x965C, 0x2, SColor, "Unstable bytes" },
				MemoryEditor::MarkedSpan{ 0x965E, 0xE, SColor, "Ans" },
				MemoryEditor::MarkedSpan{ 0x966C, 0xE, SColor, "A" },
				MemoryEditor::MarkedSpan{ 0x967A, 0xE, SColor, "B" },
				MemoryEditor::MarkedSpan{ 0x9688, 0xE, SColor, "C" },
				MemoryEditor::MarkedSpan{ 0x9696, 0xE, SColor, "D" },
				MemoryEditor::MarkedSpan{ 0x96A4, 0xE, SColor, "E" },
				MemoryEditor::MarkedSpan{ 0x96B2, 0xE, SColor, "F" },
				MemoryEditor::MarkedSpan{ 0x96C0, 0xE, SColor, "x" },
				MemoryEditor::MarkedSpan{ 0x96CE, 0xE, SColor, "y" },
				MemoryEditor::MarkedSpan{ 0x96DC, 0xE, SColor, "z" },
				MemoryEditor::MarkedSpan{ 0x96EA, 0xE, SColor, "PreAns" },
				MemoryEditor::MarkedSpan{ 0x965E + 0xE * 11, 0xE, SColor, "Ans Imaginary Part" },
				MemoryEditor::MarkedSpan{ 0x966C + 0xE * 11, 0xE, SColor, "A Imaginary Part" },
				MemoryEditor::MarkedSpan{ 0x967A + 0xE * 11, 0xE, SColor, "B Imaginary Part" },
				MemoryEditor::MarkedSpan{ 0x9688 + 0xE * 11, 0xE, SColor, "C Imaginary Part" },
				MemoryEditor::MarkedSpan{ 0x9696 + 0xE * 11, 0xE, SColor, "D Imaginary Part" },
				MemoryEditor::MarkedSpan{ 0x96A4 + 0xE * 11, 0xE, SColor, "E Imaginary Part" },
				MemoryEditor::MarkedSpan{ 0x96B2 + 0xE * 11, 0xE, SColor, "F Imaginary Part" },
				MemoryEditor::MarkedSpan{ 0x96C0 + 0xE * 11, 0xE, SColor, "x Imaginary Part" },
				MemoryEditor::MarkedSpan{ 0x96CE + 0xE * 11, 0xE, SColor, "y Imaginary Part" },
				MemoryEditor::MarkedSpan{ 0x96DC + 0xE * 11, 0xE, SColor, "z Imaginary Part" },
				MemoryEditor::MarkedSpan{ 0x96EA + 0xE * 11, 0xE, SColor, "PreAns Imaginary Part" },
				MemoryEditor::MarkedSpan{ 0x97A2, 200, SColor, "f(x)" },
				MemoryEditor::MarkedSpan{ 0x986A, 200, SColor, "g(x)" },
				MemoryEditor::MarkedSpan{ 0x9932, 0xE * 80 * 2, SColor, "Statistics mode data" },
				MemoryEditor::MarkedSpan{ 0xA1F2, 0x1, SColor, "Statistics mode data mode (non-0 is 2-var stat)" },
				MemoryEditor::MarkedSpan{ 0xA1F4, 0x1, SColor, "Statistics mode data count" },
				MemoryEditor::MarkedSpan{ 0xA1F6, 0xE * 16, SColor, "MatA(data)" },
				MemoryEditor::MarkedSpan{ 0xA1F6 + 0xE * 16 * 1, 0xE * 16, SColor, "MatB(data)" },
				MemoryEditor::MarkedSpan{ 0xA1F6 + 0xE * 16 * 2, 0xE * 16, SColor, "MatC(data)" },
				MemoryEditor::MarkedSpan{ 0xA1F6 + 0xE * 16 * 3, 0xE * 16, SColor, "MatD(data)" },
				MemoryEditor::MarkedSpan{ 0xA576, 0x2, SColor, "MatA(a*b)" },
				MemoryEditor::MarkedSpan{ 0xA576 + 2, 0x2, SColor, "MatB(a*b)" },
				MemoryEditor::MarkedSpan{ 0xA576 + 2 * 2, 0x2, SColor, "MatC(a*b)" },
				MemoryEditor::MarkedSpan{ 0xA576 + 2 * 3, 0x2, SColor, "MatD(a*b)" },
				MemoryEditor::MarkedSpan{ 0xA57E, 0xE * 3, SColor, "VctA(data)" },
				MemoryEditor::MarkedSpan{ 0xA57E + 0xE * 3 * 1, 0xE * 3, SColor, "VctB(data)" },
				MemoryEditor::MarkedSpan{ 0xA57E + 0xE * 3 * 2, 0xE * 3, SColor, "VctC(data)" },
				MemoryEditor::MarkedSpan{ 0xA57E + 0xE * 3 * 3, 0xE * 3, SColor, "VctD(data)" },
				MemoryEditor::MarkedSpan{ 0xA626, 0x2, SColor, "VctA(a*b)" },
				MemoryEditor::MarkedSpan{ 0xA626 + 2, 0x2, SColor, "VctB(a*b)" },
				MemoryEditor::MarkedSpan{ 0xA626 + 2 * 2, 0x2, SColor, "VctC(a*b)" },
				MemoryEditor::MarkedSpan{ 0xA626 + 2 * 3, 0x2, SColor, "VctD(a*b)" },
				MemoryEditor::MarkedSpan{ 0xA62E, 0xE * 9, SColor, "Distribution mode variable" },
				MemoryEditor::MarkedSpan{ 0xB1CE, 900, SColor, "Algorithm mode program" },
				MemoryEditor::MarkedSpan{ 0xB552, 0xE * 7 + 2 * 6, SColor, "Plotting mode variable" },
				MemoryEditor::MarkedSpan{ 0xA6AC, 2380, SColor, "Data table data" },
				MemoryEditor::MarkedSpan{ 0xA6AC + 2380, 2 * 45 * 5, SColor, "Data table data (markers, first byte is tail string length, second byte: D0=formula 80=value 00=nonexistent)" },
				MemoryEditor::MarkedSpan{ 0xB1BA, 2, SColor, "Data table value size" },
				MemoryEditor::MarkedSpan{ 0xB1BA + 2, 2, SColor, "Data table formula size" },
				MemoryEditor::MarkedSpan{ 0xB1BA + 4, 2, SColor, "Data table total size" },
				MemoryEditor::MarkedSpan{ 0xB1C2, 1, SColor, "Data table existence" },
				MemoryEditor::MarkedSpan{ 0xB1C3, 1, SColor, "Data table type (1==value only 2==with formula)" },
				MemoryEditor::MarkedSpan{ 0xBDEC, 0xE, SColor, "Theta variable" },
				MemoryEditor::MarkedSpan{ 0xBA68, 3000, SColor, "Activated application data" },
				MemoryEditor::MarkedSpan{ 0x9186, 0x1, SColor, "Activated application entry count (statistics/function table)" },
				MemoryEditor::MarkedSpan{ 0xC620, 0x10, SColor, "Memory integrity check (magic string)" },
				MemoryEditor::MarkedSpan{ 0xC860, 0x1F4, SColor, "Registers backup(used in math input)" },
			};
#endif
		}
		case HardwareId::HW_CLASSWIZ: {
#if LANGUAGE == 2
			return {
				MemoryEditor::MarkedSpan{ 0xD16C, 0xA, SColor, "Ans" },
				MemoryEditor::MarkedSpan{ 0xD176, 0xA, SColor, "Ans i" },
				MemoryEditor::MarkedSpan{ 0xD180, 200, SColor, " 输入区 " },
				MemoryEditor::MarkedSpan{ 0xD180 + 200, 200, SColor, "缓冲区" },
				MemoryEditor::MarkedSpan{ 0xD310, 0x8, SColor, "随机数种子" },
				MemoryEditor::MarkedSpan{ 0xD318, 0x2, SColor, "不稳定字节" },
				MemoryEditor::MarkedSpan{ 0xD324 + 0xA * -1, 0xA, SColor, "M" },
				MemoryEditor::MarkedSpan{ 0xD324 + 0xA * 0, 0xA, SColor, "Ans" },
				MemoryEditor::MarkedSpan{ 0xD324 + 0xA * 1, 0xA, SColor, "A" },
				MemoryEditor::MarkedSpan{ 0xD324 + 0xA * 2, 0xA, SColor, "B" },
				MemoryEditor::MarkedSpan{ 0xD324 + 0xA * 3, 0xA, SColor, "C" },
				MemoryEditor::MarkedSpan{ 0xD324 + 0xA * 4, 0xA, SColor, "D" },
				MemoryEditor::MarkedSpan{ 0xD324 + 0xA * 5, 0xA, SColor, "E" },
				MemoryEditor::MarkedSpan{ 0xD324 + 0xA * 6, 0xA, SColor, "F" },
				MemoryEditor::MarkedSpan{ 0xD324 + 0xA * 7, 0xA, SColor, "x" },
				MemoryEditor::MarkedSpan{ 0xD324 + 0xA * 8, 0xA, SColor, "y" },
				MemoryEditor::MarkedSpan{ 0xD324 + 0xA * 9, 0xA, SColor, "PreAns" },
				MemoryEditor::MarkedSpan{ 0xD324 + 0xA * 10, 0xA, SColor, "z" },
				MemoryEditor::MarkedSpan{ 0xD392, 400, SColor, "历史记录" },
				MemoryEditor::MarkedSpan{ 0xD522, 200, SColor, "结果区/分析区" },
				MemoryEditor::MarkedSpan{ 0xD61C + 0xA * -1, 0xA, SColor, "M 虚数部分" },
				MemoryEditor::MarkedSpan{ 0xD61C + 0xA * 0, 0xA, SColor, "Ans 虚数部分" },
				MemoryEditor::MarkedSpan{ 0xD61C + 0xA * 1, 0xA, SColor, "A 虚数部分" },
				MemoryEditor::MarkedSpan{ 0xD61C + 0xA * 2, 0xA, SColor, "B 虚数部分" },
				MemoryEditor::MarkedSpan{ 0xD61C + 0xA * 3, 0xA, SColor, "C 虚数部分" },
				MemoryEditor::MarkedSpan{ 0xD61C + 0xA * 4, 0xA, SColor, "D 虚数部分" },
				MemoryEditor::MarkedSpan{ 0xD61C + 0xA * 5, 0xA, SColor, "E 虚数部分" },
				MemoryEditor::MarkedSpan{ 0xD61C + 0xA * 6, 0xA, SColor, "F 虚数部分" },
				MemoryEditor::MarkedSpan{ 0xD61C + 0xA * 7, 0xA, SColor, "x 虚数部分" },
				MemoryEditor::MarkedSpan{ 0xD61C + 0xA * 8, 0xA, SColor, "y 虚数部分" },
				MemoryEditor::MarkedSpan{ 0xD61C + 0xA * 9, 0xA, SColor, "PreAns 虚数部分" },
				MemoryEditor::MarkedSpan{ 0xD61C + 0xA * 10, 0xA, SColor, "z 虚数部分" },
				MemoryEditor::MarkedSpan{ 0xD784, 200, SColor, "f(x)" },
				MemoryEditor::MarkedSpan{ 0xD84C, 200, SColor, "g(x)" },
				MemoryEditor::MarkedSpan{ 0xDBD0, 0x10, SColor, " 内存完整性(Magic string) " },
				MemoryEditor::MarkedSpan{ 0xDBE0, 0xDDD3 - 0xDBE0, SColor, " MathI 垃圾 " },
				MemoryEditor::MarkedSpan{ 0xDDD3, 0x800, SColor, " 屏幕缓冲区2 " },
				MemoryEditor::MarkedSpan{ 0xE5D3, 0xF000 - 0xE5D3, SColor, " 栈 " },
				MemoryEditor::MarkedSpan{ 0xF800, 0x800, SColor, " 屏幕缓冲区 " },
			};
#else
			return {
				MemoryEditor::MarkedSpan{ 0xD16C, 0xA, SColor, "Ans 1st result" },
				MemoryEditor::MarkedSpan{ 0xD176, 0xA, SColor, "Ans 2nd result" },
				MemoryEditor::MarkedSpan{ 0xD180, 200, SColor, " Input area " },
				MemoryEditor::MarkedSpan{ 0xD180 + 200, 200, SColor, "Buffer area" },
				MemoryEditor::MarkedSpan{ 0xD310, 0x8, SColor, "Random seed" },
				MemoryEditor::MarkedSpan{ 0xD318, 0x2, SColor, "Unstable bytes" },
				MemoryEditor::MarkedSpan{ 0xD324 + 0xA * -1, 0xA, SColor, "M" },
				MemoryEditor::MarkedSpan{ 0xD324 + 0xA * 0, 0xA, SColor, "Ans" },
				MemoryEditor::MarkedSpan{ 0xD324 + 0xA * 1, 0xA, SColor, "A" },
				MemoryEditor::MarkedSpan{ 0xD324 + 0xA * 2, 0xA, SColor, "B" },
				MemoryEditor::MarkedSpan{ 0xD324 + 0xA * 3, 0xA, SColor, "C" },
				MemoryEditor::MarkedSpan{ 0xD324 + 0xA * 4, 0xA, SColor, "D" },
				MemoryEditor::MarkedSpan{ 0xD324 + 0xA * 5, 0xA, SColor, "E" },
				MemoryEditor::MarkedSpan{ 0xD324 + 0xA * 6, 0xA, SColor, "F" },
				MemoryEditor::MarkedSpan{ 0xD324 + 0xA * 7, 0xA, SColor, "x" },
				MemoryEditor::MarkedSpan{ 0xD324 + 0xA * 8, 0xA, SColor, "y" },
				MemoryEditor::MarkedSpan{ 0xD324 + 0xA * 9, 0xA, SColor, "PreAns" },
				MemoryEditor::MarkedSpan{ 0xD324 + 0xA * 10, 0xA, SColor, "z" },
				MemoryEditor::MarkedSpan{ 0xD392, 400, SColor, "History" },
				MemoryEditor::MarkedSpan{ 0xD522, 200, SColor, "Result area/Analysis area" },
				MemoryEditor::MarkedSpan{ 0xD61C + 0xA * -1, 0xA, SColor, "M Imaginary part" },
				MemoryEditor::MarkedSpan{ 0xD61C + 0xA * 0, 0xA, SColor, "Ans Imaginary part" },
				MemoryEditor::MarkedSpan{ 0xD61C + 0xA * 1, 0xA, SColor, "A Imaginary part" },
				MemoryEditor::MarkedSpan{ 0xD61C + 0xA * 2, 0xA, SColor, "B Imaginary part" },
				MemoryEditor::MarkedSpan{ 0xD61C + 0xA * 3, 0xA, SColor, "C Imaginary part" },
				MemoryEditor::MarkedSpan{ 0xD61C + 0xA * 4, 0xA, SColor, "D Imaginary part" },
				MemoryEditor::MarkedSpan{ 0xD61C + 0xA * 5, 0xA, SColor, "E Imaginary part" },
				MemoryEditor::MarkedSpan{ 0xD61C + 0xA * 6, 0xA, SColor, "F Imaginary part" },
				MemoryEditor::MarkedSpan{ 0xD61C + 0xA * 7, 0xA, SColor, "x Imaginary part" },
				MemoryEditor::MarkedSpan{ 0xD61C + 0xA * 8, 0xA, SColor, "y Imaginary part" },
				MemoryEditor::MarkedSpan{ 0xD61C + 0xA * 9, 0xA, SColor, "PreAns Imaginary part" },
				MemoryEditor::MarkedSpan{ 0xD61C + 0xA * 10, 0xA, SColor, "z Imaginary part" },
				MemoryEditor::MarkedSpan{ 0xD784, 200, SColor, "f(x)" },
				MemoryEditor::MarkedSpan{ 0xD84C, 200, SColor, "g(x)" },
				MemoryEditor::MarkedSpan{ 0xDBD0, 0x10, SColor, " Memory Integrity (Magic string) " },
				MemoryEditor::MarkedSpan{ 0xDBE0, 0xDDD3 - 0xDBE0, SColor, " MathI Garbage " },
				MemoryEditor::MarkedSpan{ 0xDDD3, 0x800, SColor, " Screen Buffer 2 " },
				MemoryEditor::MarkedSpan{ 0xE5D3, 0xF000 - 0xE5D3, SColor, " Stack " },
				MemoryEditor::MarkedSpan{ 0xF800, 0x800, SColor, " Screen Buffer " },
			};
#endif
		}
		case HardwareId::HW_ES_PLUS: {
			size_t v = 0x80E0;
#if LANGUAGE == 2
			return {
				MemoryEditor::MarkedSpan{ v, 0x2, SColor, "Mat/VctA(a*b)" },
				MemoryEditor::MarkedSpan{ v += 2, 0x2, SColor, "Mat/VctB(a*b)" },
				MemoryEditor::MarkedSpan{ v += 2, 0x2, SColor, "Mat/VctC(a*b)" },
				MemoryEditor::MarkedSpan{ v += 2, 0x2, SColor, "Mat/VctAns(a*b)" },
				MemoryEditor::MarkedSpan{ v += 2, 0x2, SColor, "Mat/VctAns 虚数部分?(a*b)" },
				MemoryEditor::MarkedSpan{ 0xF800, 0x800, SColor, " 屏幕缓冲区 " },
				MemoryEditor::MarkedSpan{ 0x8A18, 0x8E00 - 0x8A18, SColor, " 栈 " },
				MemoryEditor::MarkedSpan{ 0x860E, 0x10, SColor, " 内存完整性(Magic string) " },
				MemoryEditor::MarkedSpan{ 0x80F2, 0x2, SColor, " 上一次的KI和KO " },
				MemoryEditor::MarkedSpan{ 0x80F8, 0x1, SColor, " 按键修饰符 " },
				MemoryEditor::MarkedSpan{ 0x80F9, 0x1, SColor, " 模式 " },
				MemoryEditor::MarkedSpan{ 0x80FA, 0x1, SColor, " 子模式 " },
				MemoryEditor::MarkedSpan{ 0x80FB, 0x1, SColor, " 屏幕状态(0:输入公式,1:主屏幕,3:其他菜单) " },
				MemoryEditor::MarkedSpan{ 0x80FC, 0x1, SColor, " 界面?反正和屏幕有关就对了 " },
				MemoryEditor::MarkedSpan{ 0x80FE, 0x1, SColor, " 是否闪烁光标 " },
				MemoryEditor::MarkedSpan{ 0x8102, 0x1, SColor, " 数字格式设置 " },
				MemoryEditor::MarkedSpan{ 0x8103, 0x1, SColor, " 数字格式设置2 " },
				MemoryEditor::MarkedSpan{ 0x8104, 0x1, SColor, " 小数点类型 " },
				MemoryEditor::MarkedSpan{ 0x8105, 0x1, SColor, " 角度单位设置 " },
				MemoryEditor::MarkedSpan{ 0x8106, 0x1, SColor, " 数学模式开关 " },
				MemoryEditor::MarkedSpan{ 0x8107, 0x1, SColor, " 分数类型 " },
				MemoryEditor::MarkedSpan{ 0x8108, 0x1, SColor, " 复数类型 " },
				MemoryEditor::MarkedSpan{ 0x8109, 0x1, SColor, " 频数 " },
				MemoryEditor::MarkedSpan{ 0x810A, 0x1, SColor, " 循环小数 " },
				MemoryEditor::MarkedSpan{ 0x810B, 0x1, SColor, " 自动化简 " },
				MemoryEditor::MarkedSpan{ 0x810C, 0x1, SColor, " 小数输出开关 " },
				MemoryEditor::MarkedSpan{ 0x810E, 0x1, SColor, " 对比度 " },
				MemoryEditor::MarkedSpan{ 0x8117, 0x1, SColor, " 字体大小 " },
				MemoryEditor::MarkedSpan{ 0x8118, 0x1, SColor, " 表格滚动开始 " },
				MemoryEditor::MarkedSpan{ 0x8119, 0x1, SColor, " 表格光标行位置 " },
				MemoryEditor::MarkedSpan{ 0x811A, 0x1, SColor, " 表格光标列位置" },
				MemoryEditor::MarkedSpan{ 0x811B, 0x1, SColor, " 光标大小 " },
				MemoryEditor::MarkedSpan{ 0x8110, 0x1, SColor, " 光标字符位置 " },
				MemoryEditor::MarkedSpan{ 0x8114, 0x1, SColor, " 光标X轴 " },
				MemoryEditor::MarkedSpan{ 0x8115, 0x1, SColor, " 光标Y轴 " },
				MemoryEditor::MarkedSpan{ 0x8116, 0x1, SColor, " 光标图形 " },
				MemoryEditor::MarkedSpan{ 0x811D, 0x1, SColor, " 是否可以接受输入 " },
				MemoryEditor::MarkedSpan{ 0x8140, 0xA, SColor, "Ans1" },
				MemoryEditor::MarkedSpan{ 0x8140 + 10, 0xA, SColor, "Ans2" },
				MemoryEditor::MarkedSpan{ 0x8154, 100, SColor, " 输入区 " },
				MemoryEditor::MarkedSpan{ 0x81B8, 100, SColor, " 缓冲区 " },
				MemoryEditor::MarkedSpan{ 0x821C, 8, SColor, " 随机数种子 " },
				MemoryEditor::MarkedSpan{ 0x8224, 2, SColor, " 不稳定字符 " },
				MemoryEditor::MarkedSpan{ 0x8226, 10, SColor, " M " },
				MemoryEditor::MarkedSpan{ 0x8226 + 10, 10, SColor, " Ans " },
				MemoryEditor::MarkedSpan{ 0x8226 + 10 * 2, 10, SColor, " A " },
				MemoryEditor::MarkedSpan{ 0x8226 + 10 * 3, 10, SColor, " B " },
				MemoryEditor::MarkedSpan{ 0x8226 + 10 * 4, 10, SColor, " C " },
				MemoryEditor::MarkedSpan{ 0x8226 + 10 * 5, 10, SColor, " D " },
				MemoryEditor::MarkedSpan{ 0x8226 + 10 * 6, 10, SColor, " E " },
				MemoryEditor::MarkedSpan{ 0x8226 + 10 * 7, 10, SColor, " F " },
				MemoryEditor::MarkedSpan{ 0x8226 + 10 * 8, 10, SColor, " X " },
				MemoryEditor::MarkedSpan{ 0x8226 + 10 * 9, 10, SColor, " Y " },
				MemoryEditor::MarkedSpan{ 0x829E, 250, SColor, " 历史记录 " },
				MemoryEditor::MarkedSpan{ 0x8398, 100, SColor, " 重做缓冲区/结果区 " },
				MemoryEditor::MarkedSpan{ 0x8408, 10, SColor, " M 虚数部分 " },
				MemoryEditor::MarkedSpan{ 0x8408 + 10, 10, SColor, " Ans 虚数部分 " },
				MemoryEditor::MarkedSpan{ 0x8408 + 10 * 2, 10, SColor, " A 虚数部分 " },
				MemoryEditor::MarkedSpan{ 0x8408 + 10 * 3, 10, SColor, " B 虚数部分 " },
				MemoryEditor::MarkedSpan{ 0x8408 + 10 * 4, 10, SColor, " C 虚数部分 " },
				MemoryEditor::MarkedSpan{ 0x8408 + 10 * 5, 10, SColor, " D 虚数部分 " },
				MemoryEditor::MarkedSpan{ 0x8408 + 10 * 6, 10, SColor, " E 虚数部分 " },
				MemoryEditor::MarkedSpan{ 0x8408 + 10 * 7, 10, SColor, " F 虚数部分 " },
				MemoryEditor::MarkedSpan{ 0x8408 + 10 * 8, 10, SColor, " X 虚数部分 " },
				MemoryEditor::MarkedSpan{ 0x8408 + 10 * 9, 10, SColor, " Y 虚数部分 " },
				MemoryEditor::MarkedSpan{ 0x8546, 100, SColor, "f(x)" },

			};
#else
			return {
				MemoryEditor::MarkedSpan{ v, 0x2, SColor, "Mat/VctA(a*b)" },
				MemoryEditor::MarkedSpan{ v += 2, 0x2, SColor, "Mat/VctB(a*b)" },
				MemoryEditor::MarkedSpan{ v += 2, 0x2, SColor, "Mat/VctC(a*b)" },
				MemoryEditor::MarkedSpan{ v += 2, 0x2, SColor, "Mat/VctAns(a*b)" },
				MemoryEditor::MarkedSpan{ v += 2, 0x2, SColor, "Mat/VctAns imaginary part?(a*b)" },
				MemoryEditor::MarkedSpan{ 0xF800, 0x800, SColor, "Screen Buffer" },
				MemoryEditor::MarkedSpan{ 0x8A18, 0x8E00 - 0x8A18, SColor, "Stack" },
				MemoryEditor::MarkedSpan{ 0x860E, 0x10, SColor, "Memory Integrity (Magic String)" },
				MemoryEditor::MarkedSpan{ 0x80F2, 0x2, SColor, "Last KI and KO" },
				MemoryEditor::MarkedSpan{ 0x80F8, 0x1, SColor, "Key Modifier" },
				MemoryEditor::MarkedSpan{ 0x80F9, 0x1, SColor, "Mode" },
				MemoryEditor::MarkedSpan{ 0x80FA, 0x1, SColor, "Submode" },
				MemoryEditor::MarkedSpan{ 0x80FB, 0x1, SColor, "Screen Status (0: Input Formula, 1: Main Screen, 3: Other Menus) " },
				MemoryEditor::MarkedSpan{ 0x80FC, 0x1, SColor, "User Interface? Related to screen anyways" },
				MemoryEditor::MarkedSpan{ 0x80FE, 0x1, SColor, "Blink Cursor?" },
				MemoryEditor::MarkedSpan{ 0x8102, 0x1, SColor, "Digit Format Setting" },
				MemoryEditor::MarkedSpan{ 0x8103, 0x1, SColor, "Digit Format Setting 2" },
				MemoryEditor::MarkedSpan{ 0x8104, 0x1, SColor, "Decimal Point Type" },
				MemoryEditor::MarkedSpan{ 0x8105, 0x1, SColor, "Angle Unit Setting" },
				MemoryEditor::MarkedSpan{ 0x8106, 0x1, SColor, "Math Mode Switch" },
				MemoryEditor::MarkedSpan{ 0x8107, 0x1, SColor, "Fraction Type" },
				MemoryEditor::MarkedSpan{ 0x8108, 0x1, SColor, "Complex Number Type" },
				MemoryEditor::MarkedSpan{ 0x8109, 0x1, SColor, "Frequency" },
				MemoryEditor::MarkedSpan{ 0x810A, 0x1, SColor, "Recur decimal" },
				MemoryEditor::MarkedSpan{ 0x810B, 0x1, SColor, "Automatic Simplification" },
				MemoryEditor::MarkedSpan{ 0x810C, 0x1, SColor, "Decimal Output Switch" },
				MemoryEditor::MarkedSpan{ 0x810E, 0x1, SColor, "Contrast" },
				MemoryEditor::MarkedSpan{ 0x8117, 0x1, SColor, "Font Size" },
				MemoryEditor::MarkedSpan{ 0x8118, 0x1, SColor, "Table Scroll Start" },
				MemoryEditor::MarkedSpan{ 0x8119, 0x1, SColor, "Table Cursor Row Position" },
				MemoryEditor::MarkedSpan{ 0x811A, 0x1, SColor, "Table Cursor Column Position" },
				MemoryEditor::MarkedSpan{ 0x811B, 0x1, SColor, "Cursor Size" },
				MemoryEditor::MarkedSpan{ 0x8110, 0x1, SColor, "Cursor Character Position" },
				MemoryEditor::MarkedSpan{ 0x8114, 0x1, SColor, "Cursor X Axis" },
				MemoryEditor::MarkedSpan{ 0x8115, 0x1, SColor, "Cursor Y Axis" },
				MemoryEditor::MarkedSpan{ 0x8116, 0x1, SColor, "Cursor Graphics" },
				MemoryEditor::MarkedSpan{ 0x811D, 0x1, SColor, "Can Accept Input?" },
				MemoryEditor::MarkedSpan{ 0x8140, 0xA, SColor, "Ans1" },
				MemoryEditor::MarkedSpan{ 0x8140 + 10, 0xA, SColor, "Ans2" },
				MemoryEditor::MarkedSpan{ 0x8154, 100, SColor, "Input Region" },
				MemoryEditor::MarkedSpan{ 0x81B8, 100, SColor, "Buffer" },
				MemoryEditor::MarkedSpan{ 0x821C, 8, SColor, "Random Number Seed" },
				MemoryEditor::MarkedSpan{ 0x8224, 2, SColor, "Unstable Characters" },
				MemoryEditor::MarkedSpan{ 0x8226, 10, SColor, "M" },
				MemoryEditor::MarkedSpan{ 0x8226 + 10, 10, SColor, "Ans" },
				MemoryEditor::MarkedSpan{ 0x8226 + 10 * 2, 10, SColor, "A" },
				MemoryEditor::MarkedSpan{ 0x8226 + 10 * 3, 10, SColor, "B" },
				MemoryEditor::MarkedSpan{ 0x8226 + 10 * 4, 10, SColor, "C" },
				MemoryEditor::MarkedSpan{ 0x8226 + 10 * 5, 10, SColor, "D" },
				MemoryEditor::MarkedSpan{ 0x8226 + 10 * 6, 10, SColor, "E" },
				MemoryEditor::MarkedSpan{ 0x8226 + 10 * 7, 10, SColor, "F" },
				MemoryEditor::MarkedSpan{ 0x8226 + 10 * 8, 10, SColor, "X" },
				MemoryEditor::MarkedSpan{ 0x8226 + 10 * 9, 10, SColor, "Y" },
				MemoryEditor::MarkedSpan{ 0x829E, 250, SColor, "History Records" },
				MemoryEditor::MarkedSpan{ 0x8398, 100, SColor, "Redo Buffer/Result Area" },
				MemoryEditor::MarkedSpan{ 0x8408, 10, SColor, "M Imaginary Part" },
				MemoryEditor::MarkedSpan{ 0x8408 + 10, 10, SColor, "Ans Imaginary Part" },
				MemoryEditor::MarkedSpan{ 0x8408 + 10 * 2, 10, SColor, "A Imaginary Part" },
				MemoryEditor::MarkedSpan{ 0x8408 + 10 * 3, 10, SColor, "B Imaginary Part" },
				MemoryEditor::MarkedSpan{ 0x8408 + 10 * 4, 10, SColor, "C Imaginary Part" },
				MemoryEditor::MarkedSpan{ 0x8408 + 10 * 5, 10, SColor, "D Imaginary Part" },
				MemoryEditor::MarkedSpan{ 0x8408 + 10 * 6, 10, SColor, "E Imaginary Part" },
				MemoryEditor::MarkedSpan{ 0x8408 + 10 * 7, 10, SColor, "F Imaginary Part" },
				MemoryEditor::MarkedSpan{ 0x8408 + 10 * 8, 10, SColor, "X Imaginary Part" },
				MemoryEditor::MarkedSpan{ 0x8408 + 10 * 9, 10, SColor, "Y Imaginary Part" },
				MemoryEditor::MarkedSpan{ 0x8546, 100, SColor, "f(x)" },
			};
#endif
		}
		default:
			return {};
		}
#undef SColor
	}
	inline constexpr size_t GetInputAreaOffset(HardwareId hid) {
		return hid == HW_ES_PLUS ? 0x8154 : hid == HW_CLASSWIZ ? 0xD180
															   : 0x9268;
	}
	inline constexpr size_t GetInputAreaSize(HardwareId hid) {
		return hid == HW_ES_PLUS ? 100 : 200;
	}
	inline constexpr size_t GetBufferAreaOffset(HardwareId hid) {
		return GetInputAreaOffset(hid) + GetInputAreaOffset(hid);
	}
	inline constexpr size_t GetModeOffset(HardwareId hid) {
		return hid == HW_ES_PLUS ? 0x80F9 : hid == HW_CLASSWIZ ? 0xD111
															   : 0x91A1;
	}
	inline constexpr size_t GetHistoryOffset(HardwareId hid) {
		return hid == HW_ES_PLUS ? 0x829E : hid == HW_CLASSWIZ ? 0xD392
															   : 0x9268 + 400;
	}
	inline constexpr size_t GetAppOffset(HardwareId hid) {
		return hid == HW_ES_PLUS ? 0x829E : hid == HW_CLASSWIZ ? 0xD392
															   : 0xBA68;
	}
	inline constexpr size_t GetScreenBufferOffset(HardwareId hid,int index) {
		if (index == 1) {
			return hid == HW_ES_PLUS ? 0 : hid == HW_CLASSWIZ ? 0xDDD4
															  : 0xCA54;
		}
		else {
			return hid == HW_ES_PLUS ? 0 : hid == HW_CLASSWIZ ? 0xE3D4
															  : 0xD654;
		}
	}
	class Variable {
	public:
		size_t RealPartOffset;
		const char* Name;
	};
	inline size_t GetVariableSize(HardwareId hid) {
		return hid == HW_CLASSWIZ_II ? 0xE : 0xA;
	}
	inline size_t GetReImOffset(HardwareId hid) {
		if (hid == HW_FX_5800P) {
			return {};
		}
		if (hid == HW_ES_PLUS) {
			return static_cast<size_t>(0x8408) - 0x8226;
		}
		else if (hid == HW_CLASSWIZ) {
			return static_cast<size_t>(0xD61C) - 0xD324;
		}
		else if (hid == HW_CLASSWIZ_II) {
			return static_cast<size_t>(0xE) * 11;
		}
		else {
			PANIC("Unknown hardware id %d", hid);
		}
		return {};
	}
	inline std::vector<Variable> GetVariableOffsets(HardwareId hid) {
		if (hid == HW_FX_5800P) {
			return {};
		}
		if (hid == HW_ES_PLUS) {
			return std::initializer_list<Variable>{
				{ 0x8226, "M" },
				{ 0x8226 + 10, "Ans" },
				{ 0x8226 + 10 * 2, "A" },
				{ 0x8226 + 10 * 3, "B" },
				{ 0x8226 + 10 * 4, "C" },
				{ 0x8226 + 10 * 5, "D" },
				{ 0x8226 + 10 * 6, "E" },
				{ 0x8226 + 10 * 7, "F" },
				{ 0x8226 + 10 * 8, "X" },
				{ 0x8226 + 10 * 9, "Y" },
			};
		}
		else if (hid == HW_CLASSWIZ) {
			return std::initializer_list<Variable>{
				{ 0xD324 + 0xA * -1, "M" },
				{ 0xD324 + 0xA * 0, "Ans" },
				{ 0xD324 + 0xA * 1, "A" },
				{ 0xD324 + 0xA * 2, "B" },
				{ 0xD324 + 0xA * 3, "C" },
				{ 0xD324 + 0xA * 4, "D" },
				{ 0xD324 + 0xA * 5, "E" },
				{ 0xD324 + 0xA * 6, "F" },
				{ 0xD324 + 0xA * 7, "x" },
				{ 0xD324 + 0xA * 8, "y" },
				{ 0xD324 + 0xA * 9, "PreAns" },
				{ 0xD324 + 0xA * 10, "z" },

			};
		}
		else if (hid == HW_CLASSWIZ_II) {
			return std::initializer_list<Variable>{
				{ 0x965E, "Ans" },
				{ 0x966C, "A" },
				{ 0x967A, "B" },
				{ 0x9688, "C" },
				{ 0x9696, "D" },
				{ 0x96A4, "E" },
				{ 0x96B2, "F" },
				{ 0x96C0, "x" },
				{ 0x96CE, "y" },
				{ 0x96DC, "z" },
				{ 0x96EA, "PreAns" }
			};
		}
		else {
			PANIC("HardwareId");
		}
		return {};
	}
}