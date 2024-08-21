#include "common.h"
#include <windows.h>
#include <iostream>
#include "enum/KeyEventResult.h"
#include "impl/KeyEvent.h"
#include "impl/Mouse.h"
#include "IF/I_Mouse.h"
#include "mouseMode/MouseMode.h"
#include "impl/convertKeyEvent.h"


namespace ngaq {

MouseMode mouseMode;

//定義在最頂層（即在所有函數外部）且不加 static 修飾符，該變量就是整個程序的全局變量。
HHOOK hKeyboardHook;


// 鍵盤鉤子回調函數 CALLBACK潙宏 __stdcall
LRESULT CALLBACK KeyboardHookProc(
	int nCode // 鉤子事件類型
	, WPARAM wParam // 按下按鍵的 wParam 值 在鍵盤鉤子中，它通常表示按鍵的狀態（按下或釋放）。
	, LPARAM lParam // 該結構包含有關鍵盤事件的詳細信息。
) {
	an<KeyEvent> keyEvent;
	if(convertKeyEvent(keyEvent , nCode, wParam, lParam) != 0){
		return CallNextHookEx(hKeyboardHook, nCode, wParam, lParam);
	}
	auto pr =  mouseMode.handleKeyEvent(keyEvent);
	if(pr == KeyEventResult::kNoop){
		return CallNextHookEx(hKeyboardHook, nCode, wParam, lParam);
	}else if(pr == KeyEventResult::kAccepted){
		return 1;
	}
	return CallNextHookEx(hKeyboardHook, nCode, wParam, lParam);
}

int main_mouseMode() {
// 設置鍵盤鉤子
	hKeyboardHook = SetWindowsHookEx(
//> 鉤子類型常量，表示設置一個低級鍵盤鉤子（Low-Level Keyboard Hook）。低級鉤子允許你監控鍵盤事件，無論是系統還是其他應用程序的鍵盤事件。這意味著你可以捕獲所有鍵盤輸入，包括系統熱鍵。
		WH_KEYBOARD_LL
//>這是指向回調函數的指針，當鍵盤事件發生時，系統會調用這個函數。在這個例子中，KeyboardHookProc 是你自定義的函數，用於處理鍵盤事件。
		, KeyboardHookProc
//>這個參數是用於指定鉤子的模塊句柄。在這裡傳遞 NULL 表示鉤子將在當前進程中安裝。這意味著回調函數 KeyboardHookProc 將在設置鉤子的進程中執行。
		, NULL
//>這個參數是用於指定鉤子的線程 ID。傳遞 0 表示鉤子將適用於所有線程。這意味著無論哪個線程發送鍵盤事件，KeyboardHookProc 都會被調用。
		, 0
	);

	if (hKeyboardHook == NULL) {
		std::cerr << "Failed to set hook!" << std::endl;
		return 1;
	}

	// 進入消息循環
	MSG msg;
	while (GetMessage(
//>指向 MSG 結構的指針，用於接收消息。
		&msg
//>表示消息來源於當前線程的消息隊列。
		, NULL
//> 兩個0: 不濾任何訊
		, 0
		, 0
	)) {
//>用於處理鍵盤輸入消息。當 GetMessage 獲取到鍵盤消息時，TranslateMessage 會將其轉換為相應的字符消息（例如，將按鍵按下的消息轉換為字符輸入）。
		TranslateMessage(&msg);
//>將消息發送到相應的窗口程序（Window Procedure）進行處理。窗口程序是用於處理特定窗口消息的函數，根據消息的類型，窗口程序會執行相應的操作。
		DispatchMessage(&msg);
	}

	// 清理鉤子
	UnhookWindowsHookEx(hKeyboardHook);
	return 0;
}


}//~namespace ngaq