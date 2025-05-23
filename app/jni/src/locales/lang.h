#pragma once
#include <string>
#include <unordered_map>

namespace DefaultLocales {

const std::string en_US = R"(
# English (United States) resources for CasioEmuMsvc
Localization.LanguageName=English (United States)
Localization.Lang.en_US=English (United States)
Localization.Lang.vi_VN=Vietnamese (VietNam)
Localization.Lang.zh_Hans=Chinese (Simplified)
Localization.EnableCJK=0
Localization.CJKPreference=CN

StartupUI.Title=Startup
StartupUI.ImportRomPackage=Import...
StartupUI.EnterPassword=Enter Password
StartupUI.PasswordPopupHint=Please enter the password for the encrypted ROM package:
Button.Positive=OK
Button.Negative=Cancel
Button.Refresh=Refresh
StartupUI.ChooseModelHint=Choose a model:
StartupUI.RecentlyUsed=Recently used
StartupUI.RecentlyUsedTableHeader=Recently
StartupUI.AllModel=All
StartupUI.SearchBoxHeader=Search
StartupUI.DontShowEmuRom=Don't show emulator roms
StartupUI.RomName=Name
StartupUI.RomVer=Version
StartupUI.RomSum=Chksum
StartupUI.RomType=Type
StartupUI.ExportRomPackage=Encrypt and export
StartupUI.Launch=Launch
StartupUI.Reveal=Reveal in Explorer
StartupUI.Edit=Edit
StartupUI.Export=Export...
Table.NotAvailable=N/A
StartupUI.EmulatorRom=Emulator
CopyrightWatermark.Dismiss=Dismiss
CopyrightWatermark.Licenses=Licenses
CopyrightWatermark.VisitOfficialRepo=Visit official repository

ModelEditor.Name=Name
ModelEditor.InterfacePath=Interface texture path
ModelEditor.RomPath=Rom path
ModelEditor.FlashDumpPath=Flash dump path
ModelEditor.CsrMask=Code segment register mask
ModelEditor.PdValue=PD value(ES only)
ModelEditor.HardwareType=Hardware type
ModelEditor.SampleRom=Sample emulator ROM
ModelEditor.NewRenderMethod=New status bar rendering method
ModelEditor.RealRom=Real hardware ROM
ModelEditor.LegacyKO=Legacy keyboard output SFR (ES)
ModelEditor.InkColor=Screen foreground color
Button.Save=Save
ModelEditor.KeyName=Key name
ModelEditor.KIKO=KIKO value

HexEditors.ContextMenu.MonitorWrite=Find out what wrote to this addr
HexEditors.ContextMenu.MonitorRead=Find out what read from this addr
HexEditor.ContextMenu.ShowDataPreview=Show Data Preview
HexEditor.ContextMenu.ShowHexII=Show HexII
HexEditor.ContextMenu.ShowAscii=Show Ascii
HexEditor.ContextMenu.GreyOutZeros=Grey out zeroes
HexEditor.ContextMenu.UppercaseHex=Uppercase hex
HexEditor.ContextMenu.NCols=%d cols
HexEditor.PreviewAs=Preview as:

5800FS.Name=Name
5800FS.Length=Length
5800FS.Back=Back

AddressWindow.Header=Manage Addresses
AddressWindow.Address=Address
AddressWindow.Value=Value
AddressWindow.Fixed=Lock
AddressWindow.Add=Add New Address
AddressWindow.AddBtn=Add Address

CallAnalysis.Stop=Stop
CallAnalysis.Clear=Clear
CallAnalysis.Function=Function
CallAnalysis.CallCount=Call count
CallAnalysis.Close=Close
CallAnalysis.Caller=Caller
CallAnalysis.Stacktrace=Stacktrace
CallAnalysis.StartRec=Start recording
CallAnalysis.Filters=Filters:
CallAnalysis.CalleeFilter=Callee:
CallAnalysis.CallerFilter=Caller:

CodeViewer.Loading=Waiting for disassembler...
CodeViewer.Goto=Goto:
CodeViewer.Step=Step
CodeViewer.Trace=Trace
CodeViewer.JumpOut=Jump out
CodeViewer.Continue=Continue
CodeViewer.Pause=Pause
CodeViewer.GotoPC=Jump to PC

ScreenshotBtn=Screenshot

HwController.Value1=Screen flashing threshold
HwController.Value2=Screen flashing brightness coeff
# 闪屏模拟阈值
# HwController.Value1=???
# 闪屏对比度补偿
# HwController.Value2=???
HwController.ScreenBufferSelect=Screen buffer select
HwController.CPS=Cycles per second
HwController.Interrupt=Raise an interrupt

MemBP.BPType=Choose breakpoint type:
MemBP.Delete=Delete
MemBP.NoBPHint=No breakpoints. Please add a breakpoint.
MemBP.MonitoringHint=Monitoring: 0x%06x
MemBP.ClearRec=Clear records
MemBP.AddAddr=Add
MemBP.BreakWhenHit=Break when hit bp

WatchWindow.CoreStatus=Core status
WatchWindow.Pause=Pause
WatchWindow.Continue=Continue
WatchWindow.Function=Function
WatchWindow.LrDestroyed=LR destroyed
WatchWindow.StackMemViewRange=Stack memory view range

VarWindow.Variable=Variable
VarWindow.ReP=Real part
VarWindow.ImP=Imaginary part
VarWindow.Hex=Hex
VarWindow.Addr=Addr
VarWindow.ShowAddrOpt=Show address
VarWindow.ShowHexOpt=Show hex
VarWindow.ShowImPWhenComplex=Show imaginary part in cmplx mode
VarWindow.AlwaysShowImP=Always show imaginary part

Label.Copy=Copy
Label.SfrsHeader=SFRs in this model:
Label.GeneralHeader=Available in this model:

Ui.CurrentLang=Current langauge:
Ui.ChangeLang=Change language
Ui.DarkMode=Dark mode
Ui.LightMode=Light mode
Ui.Scale=Scale value
Ui.ApplyScale=Apply Setting
Ui.ForceUpdateLang=Force Update Language
Ui.ForceUpdateLangDesc=Reload default language (usually used to update language files if there is an update for android)
Ui.Browse=Browse
Ui.InjectionFilePath=Injection File Path

Rop.Input=Input
Rop.InputSize=Input size
Rop.LoadToInputArea=Load to input area
Rop.LoadedTip=Loaded
Rop.XAnMode=X "an" mode
Rop.InputAn=Input "an"
Rop.AnInputed=An is inputed
Rop.InjectAddr=Inject address
Rop.InjectHex=Inject hex
Rop.Injected=Injected successfully
Rop.AddInjector=Add Injector
Rop.Remove=Remove
Rop.Injector=Injector
Rop.Paste=Paste
Rop.Clear=Clear
Rop.Inject=Inject
Rop.TabBar=Injector Tabs
Rop.InjectorNum=Injector
Rop.RemoveInjector=Remove
Rop.InfoPopup=Information
Rop.CustomInject=Custom Injections
Rop.ReloadCustomInjects=Reload Custom Injections
#Rop.CustomInjectReloaded=Custom injections reloaded
Rop.CurrentInjectFile =Current Inject File
Rop.CustomInjectApplied=Custom injection '%s' applied successfully
Rop.CustomInjectError=Error applying injection '%s'
Rop.Address=Address
Rop.Loading=Loading
Rop.CustomInjectReloading=Reloading
Rop.AutoReload=Auto reload

HexEditor.Options=Options
HexEditor.Range=Range

BitmapViewer.Address=Address
BitmapViewer.Address_2=Address(Int)
BitmapViewer.Width=Width
BitmapViewer.PixelSize=Pixel size
BitmapViewer.BitOffset=Bit offset

Files.CurrentPath=Current Path
Files.Back=Back
Files.Save=Save
Files.Open=Open
Files.Cancel=Cancel
)";

const std::string vi_VN = R"(
# Vietnamese (Viet Nam) resources for CasioEmuMsvc
# Dịch bởi hieuxyz(update/edit)
Localization.LanguageName=Tiếng Việt
Localization.Lang.en_US=Tiếng Anh (Hoa Kỳ)
Localization.Lang.vi_VN=Tiếng Việt (Việt Nam)
Localization.Lang.zh_Hans=Tiếng Trung (Giản thể)
Localization.EnableCJK=0
Localization.CJKPreference=CN

StartupUI.Title=Khởi động
StartupUI.ImportRomPackage=Nhập...
StartupUI.EnterPassword=Nhập mật khẩu
StartupUI.PasswordPopupHint=Vui lòng nhập mật khẩu cho ROM package đã mã hóa:
Button.Positive=OK
Button.Negative=Hủy
Button.Refresh=Làm mới
StartupUI.ChooseModelHint=Chọn một model:
StartupUI.RecentlyUsed=Đã dùng gần đây
StartupUI.RecentlyUsedTableHeader=Gần đây
StartupUI.AllModel=Tất cả
StartupUI.SearchBoxHeader=Tìm kiếm
StartupUI.DontShowEmuRom=Không hiển thị emu ROM
StartupUI.RomName=Tên
StartupUI.RomVer=Phiên bản
StartupUI.RomSum=Kiểm tra
StartupUI.RomType=Loại
StartupUI.ExportRomPackage=Mã hóa và xuất
StartupUI.Launch=Khởi chạy
StartupUI.Reveal=Mở trong Explorer
StartupUI.Edit=Sửa
StartupUI.Export=Xuất...
Table.NotAvailable=N/A
StartupUI.EmulatorRom=Giả lập
CopyrightWatermark.Dismiss=Bỏ qua
CopyrightWatermark.Licenses=Giấy phép
CopyrightWatermark.VisitOfficialRepo=Truy cập repo chính thức

ModelEditor.Name=Tên
ModelEditor.InterfacePath=Đường dẫn Interface(giao diện máy)
ModelEditor.RomPath=Đường dẫn file ROM
ModelEditor.FlashDumpPath=Đường dẫn Dump Flash
ModelEditor.CsrMask=Bộ lọc thanh ghi segment
ModelEditor.PdValue=Giá trị PD (chỉ ES)
ModelEditor.HardwareType=Loại phần cứng
ModelEditor.SampleRom=ROM giả lập mẫu
ModelEditor.NewRenderMethod=Cách vẽ thanh trạng thái mới
ModelEditor.RealRom=ROM thật(realhw)
ModelEditor.LegacyKO=SFR đầu ra bàn phím cũ (ES)
ModelEditor.InkColor=Màu chữ màn hình
Button.Save=Lưu
ModelEditor.KeyName=Tên phím
ModelEditor.KIKO=Giá trị KIKO

HexEditors.ContextMenu.MonitorWrite=Tìm nguồn đã ghi vào địa chỉ này
HexEditors.ContextMenu.MonitorRead=Tìm nguồn đã đọc từ địa chỉ này
HexEditor.ContextMenu.ShowDataPreview=Hiện xem trước dữ liệu
HexEditor.ContextMenu.ShowHexII=Hiện HexII
HexEditor.ContextMenu.ShowAscii=Hiện Ascii
HexEditor.ContextMenu.GreyOutZeros=Làm xám số 0
HexEditor.ContextMenu.UppercaseHex=Hex chữ hoa
HexEditor.ContextMenu.NCols=%d cột
HexEditor.PreviewAs=Xem trước dưới dạng:

5800FS.Name=Tên
5800FS.Length=Độ dài
5800FS.Back=Quay lại

AddressWindow.Header=Quản lý địa chỉ
AddressWindow.Address=Địa chỉ
AddressWindow.Value=Giá trị
AddressWindow.Fixed=Khóa
AddressWindow.Add=Thêm địa chỉ mới
AddressWindow.AddBtn=Thêm địa chỉ

CallAnalysis.Stop=Dừng
CallAnalysis.Clear=Xóa
CallAnalysis.Function=Hàm
CallAnalysis.CallCount=Số lần gọi
CallAnalysis.Close=Đóng
CallAnalysis.Caller=Người gọi
CallAnalysis.Stacktrace=Dấu vết stack
CallAnalysis.StartRec=Bắt đầu ghi
CallAnalysis.Filters=Bộ lọc:
CallAnalysis.CalleeFilter=Được gọi:
CallAnalysis.CallerFilter=Người gọi:

CodeViewer.Loading=Đang đợi disassembler...
CodeViewer.Goto=Đến:
CodeViewer.Step=Bước
CodeViewer.Trace=Theo dõi
CodeViewer.JumpOut=Nhảy ra
CodeViewer.Continue=Tiếp tục
CodeViewer.Pause=Tạm dừng
CodeViewer.GotoPC=Nhảy đến PC

ScreenshotBtn=Chụp màn hình

HwController.Value1=Ngưỡng nháy màn hình
HwController.Value2=Hệ số độ sáng nháy màn hình
HwController.ScreenBufferSelect=Chọn buffer màn hình
HwController.CPS=Chu kỳ mỗi giây
HwController.Interrupt=Kích hoạt ngắt

MemBP.BPType=Chọn loại điểm dừng:
MemBP.Delete=Xóa
MemBP.NoBPHint=Không có điểm dừng. Vui lòng thêm điểm dừng.
MemBP.MonitoringHint=Đang giám sát: 0x%06x
MemBP.ClearRec=Xóa bản ghi
MemBP.AddAddr=Thêm
MemBP.BreakWhenHit=Dừng khi chạm điểm dừng

WatchWindow.CoreStatus=Trạng thái nhân(lõi)
WatchWindow.Pause=Tạm dừng
WatchWindow.Continue=Tiếp tục
WatchWindow.Function=Hàm
WatchWindow.LrDestroyed=LR đã bị hủy
WatchWindow.StackMemViewRange=Phạm vi xem bộ nhớ stack
VarWindow.Variable=Biến
VarWindow.ReP=Phần thực
VarWindow.ImP=Phần ảo
VarWindow.Hex=Hex(số thập lục phân)
VarWindow.Addr=Địa chỉ
VarWindow.ShowAddrOpt=Hiện địa chỉ
VarWindow.ShowHexOpt=Hiện dạng hex(thập lục phân)
VarWindow.ShowImPWhenComplex=Hiện phần ảo ở chế độ phức
VarWindow.AlwaysShowImP=Luôn hiện phần ảo

Label.Copy=Sao chép
Label.SfrsHeader=SFR trong model này:
Label.GeneralHeader=Có sẵn trong model này:

Ui.CurrentLang=Ngôn ngữ hiện tại:
Ui.ChangeLang=Đổi ngôn ngữ
Ui.DarkMode=Chế độ tối
Ui.LightMode=Chế độ sáng
Ui.Scale=Giá trị tỉ lệ
Ui.ApplyScale=Áp dụng cài đặt
Ui.ForceUpdateLang=Bắt buộc cập nhật ngôn ngữ
Ui.ForceUpdateLangDesc=Tải lại ngôn ngữ mặc định (thường dùng để cập nhật lại file ngôn ngữ nếu có bản cập nhật cho android)
Ui.Browse=Duyệt
Ui.InjectionFilePath=Đường dẫn file custom inj

Rop.Input=Đầu vào
Rop.InputSize=Nhập
Rop.LoadToInputArea=Load vào vùng input
Rop.LoadedTip=Load thành công
Rop.XAnMode=Chế độ X "an"
Rop.InputAn=Nhập "an"
Rop.AnInputed=Đã nhập An
Rop.InjectAddr=Địa chỉ inj
Rop.InjectHex=Inj hex
Rop.Injected=Đã inject thành công
Rop.AddInjector=Thêm Injector
Rop.Remove=Xoá
Rop.Injector=Injector
Rop.Paste=Dán
Rop.Clear=Xoá
Rop.Inject=Inject
Rop.TabBar=Injector Tabs
Rop.InjectorNum=Injector
Rop.RemoveInjector=Remove
Rop.InfoPopup=Thông tin
Rop.CustomInject=Injections tùy chỉnh
Rop.ReloadCustomInjects=Tải lại Injections tùy chỉnh
Rop.CurrentInjectFile =File inj(ct) hiện tại
#Rop.CustomInjectReloaded=Tải lại thành công
Rop.CustomInjectApplied=Injection tùy chỉnh '%s' áp dụng thành công
Rop.CustomInjectError=Lỗi khi áp dụng injection '%s'
Rop.Address=Địa chỉ
Rop.Loading=Đang tải
Rop.CustomInjectReloading=Đang tải lại
Rop.AutoReload=Tự động reload

HexEditor.Options=Tùy chọn
HexEditor.Range=Phạm vi

BitmapViewer.Address=Địa chỉ
BitmapViewer.Address_2=Địa chỉ(Số nguyên)
BitmapViewer.Width=Chiều rộng
BitmapViewer.PixelSize=Kích thước pixel
BitmapViewer.BitOffset=Độ lệch bit

Files.CurrentPath=Đường dẫn hiện tại
Files.Back=Quay lại
Files.Save=Lưu
Files.Open=Mở
Files.Cancel=Hủy
)";

const std::string zh_CN = R"(
# 简体中文 (Chinese Simplified) resources for CasioEmuMsvc
Localization.LanguageName=简体中文
Localization.Lang.en_US=英语(美国)
Localization.Lang.vi_VN=越南语（越南)
Localization.Lang.zh_Hans=简体中文
Localization.EnableCJK=1
Localization.CJKPreference=CN

StartupUI.Title=启动
StartupUI.ImportRomPackage=导入...
StartupUI.EnterPassword=输入密码
StartupUI.PasswordPopupHint=请输入加密ROM包的密码：
Button.Positive=确定
Button.Negative=取消
Button.Refresh=刷新
StartupUI.ChooseModelHint=选择型号：
StartupUI.RecentlyUsed=最近使用
StartupUI.RecentlyUsedTableHeader=最近
StartupUI.AllModel=全部
StartupUI.SearchBoxHeader=搜索
StartupUI.DontShowEmuRom=不显示模拟器ROM
StartupUI.RomName=名称
StartupUI.RomVer=版本
StartupUI.RomSum=校验和
StartupUI.RomType=类型
StartupUI.ExportRomPackage=加密并导出
StartupUI.Launch=启动
StartupUI.Reveal=在资源管理器中显示
StartupUI.Edit=编辑
StartupUI.Export=导出...
Table.NotAvailable=不可用
StartupUI.EmulatorRom=模拟器
CopyrightWatermark.Dismiss=关闭
CopyrightWatermark.Licenses=许可证
CopyrightWatermark.VisitOfficialRepo=访问官方仓库

ModelEditor.Name=名称
ModelEditor.InterfacePath=界面纹理路径
ModelEditor.RomPath=ROM路径
ModelEditor.FlashDumpPath=Flash转储路径
ModelEditor.CsrMask=代码段寄存器掩码
ModelEditor.PdValue=PD值(仅ES)
ModelEditor.HardwareType=硬件类型
ModelEditor.SampleRom=示例模拟器ROM
ModelEditor.NewRenderMethod=新状态栏渲染方法
ModelEditor.RealRom=真实硬件ROM
ModelEditor.LegacyKO=传统键盘输出SFR(ES)
ModelEditor.InkColor=屏幕前景色
Button.Save=保存
ModelEditor.KeyName=按键名称
ModelEditor.KIKO=KIKO值

HexEditors.ContextMenu.MonitorWrite=查找写入此地址的内容
HexEditors.ContextMenu.MonitorRead=查找从此地址读取的内容
HexEditor.ContextMenu.ShowDataPreview=显示数据预览
HexEditor.ContextMenu.ShowHexII=显示HexII
HexEditor.ContextMenu.ShowAscii=显示ASCII
HexEditor.ContextMenu.GreyOutZeros=灰显零值
HexEditor.ContextMenu.UppercaseHex=大写十六进制
HexEditor.ContextMenu.NCols=%d列
HexEditor.PreviewAs=预览为：

5800FS.Name=名称
5800FS.Length=长度
5800FS.Back=返回

AddressWindow.Header=管理地址
AddressWindow.Address=地址
AddressWindow.Value=值
AddressWindow.Fixed=锁定
AddressWindow.Add=添加新地址
AddressWindow.AddBtn=添加地址

CallAnalysis.Stop=停止
CallAnalysis.Clear=清除
CallAnalysis.Function=函数
CallAnalysis.CallCount=调用次数
CallAnalysis.Close=关闭
CallAnalysis.Caller=调用者
CallAnalysis.Stacktrace=堆栈跟踪
CallAnalysis.StartRec=开始记录
CallAnalysis.Filters=过滤器：
CallAnalysis.CalleeFilter=被调用者：
CallAnalysis.CallerFilter=调用者：

CodeViewer.Loading=等待反汇编器...
CodeViewer.Goto=转到：
CodeViewer.Step=单步
CodeViewer.Trace=追踪
CodeViewer.JumpOut=跳出
CodeViewer.Continue=继续
CodeViewer.Pause=暂停
CodeViewer.GotoPC=跳转到PC

ScreenshotBtn=截图

HwController.Value1=闪屏模拟阈值
HwController.Value2=闪屏对比度补偿
HwController.ScreenBufferSelect=屏幕缓冲区选择
HwController.CPS=每秒周期数
HwController.Interrupt=触发中断

MemBP.BPType=选择断点类型：
MemBP.Delete=删除
MemBP.NoBPHint=无断点。请添加断点。
MemBP.MonitoringHint=监视中：0x%06x
MemBP.ClearRec=清除记录
MemBP.AddAddr=添加
MemBP.BreakWhenHit=命中断点时中断

WatchWindow.CoreStatus=核心状态
WatchWindow.Pause=暂停
WatchWindow.Continue=继续
WatchWindow.Function=函数
WatchWindow.LrDestroyed=LR已破坏
WatchWindow.StackMemViewRange=堆栈内存查看范围

VarWindow.Variable=变量
VarWindow.ReP=实部
VarWindow.ImP=虚部
VarWindow.Hex=十六进制
VarWindow.Addr=地址
VarWindow.ShowAddrOpt=显示地址
VarWindow.ShowHexOpt=显示十六进制
VarWindow.ShowImPWhenComplex=复数模式下显示虚部
VarWindow.AlwaysShowImP=始终显示虚部

Label.Copy=复制
Label.SfrsHeader=此型号的SFR：
Label.GeneralHeader=此型号可用：

Rop.Input=输入
Rop.InputSize=输入大小
Ui.CurrentLang=当前语言：
Ui.ChangeLang=更改语言
Ui.DarkMode=深色模式
Ui.LightMode=浅色模式
Ui.Scale=比例值
Ui.ApplyScale=应用设置
Ui.ForceUpdateLang=强制更新语言
Ui.ForceUpdateLangDesc=重新加载默认语言（通常用于在 android 有更新时更新语言文件）
Ui.Browse=浏览
Ui.InjectionFilePath=注入文件路径

Rop.LoadToInputArea=加载到输入区
Rop.LoadedTip=已加载
Rop.XAnMode=X "an"模式
Rop.InputAn=输入"an"
Rop.AnInputed=已输入an
Rop.InjectAddr=注入地址
Rop.InjectHex=注入十六进制
Rop.Injected=注入成功
Rop.AddInjector=添加喷射器
Rop.Remove=消除
Rop.Injector=注射器
Rop.Paste=粘贴
Rop.Clear=清除
Rop.Inject=注入
Rop.TabBar=喷油器标签
Rop.InjectorNum=注射器
Rop.RemoveInjector=消除
Rop.InfoPopup=信息
Rop.CustomInject=自定义注入
Rop.ReloadCustomInjects=重新加载自定义注入
#Rop.CustomInjectReloaded=重新加载自定义注入
Rop.CurrentInjectFile =当前注入文件
Rop.CustomInjectApplied=自定义注入 '%s' 已成功应用
Rop.CustomInjectError=注入错误 '%s'
Rop.Address=地址
Rop.Loading=加载中
Rop.CustomInjectReloading=重新加载
Rop.AutoReload=自动重新加载

HexEditor.Options=选项
HexEditor.Range=范围

BitmapViewer.Address=地址
BitmapViewer.Address_2=地址（整数）
BitmapViewer.Width=宽度
BitmapViewer.PixelSize=像素大小
BitmapViewer.BitOffset=位偏移

Files.CurrentPath=当前路径
Files.Back=后退
Files.Save=节省
Files.Open=打开
Files.Cancel=取消
)";

const std::unordered_map<std::string, const std::string&> defaultLocales = {
    {"en_US", en_US},
    {"vi_VN", vi_VN}, 
    {"zh_CN", zh_CN}
};

} // namespace DefaultLocales
