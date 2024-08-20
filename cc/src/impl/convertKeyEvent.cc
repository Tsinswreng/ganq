#include "common.h"
#include "./convertKeyEvent.h"
#include "impl/KeyEvent.h"
#include "impl/Code__Key.h"
#include "enum/KeyState.h"

namespace ngaq {

i32 convertKeyEvent(
	KeyEvent& ans // 傳回的 KeyEvent 物件
	,int nCode // 鉤子事件類型
	, WPARAM wParam // 按下按鍵的 wParam 值 在鍵盤鉤子中，它通常表示按鍵的狀態（按下或釋放）。
	, LPARAM lParam // 該結構包含有關鍵盤事件的詳細信息。
){
	auto code__key = Code__Key::inst().map_();
	if (nCode == HC_ACTION) { // 若潙鍵盤事件
// > 將 lParam 轉換為 KBDLLHOOKSTRUCT 結構的指針，這個結構包含了有關鍵盤事件的詳細信息，例如按下的鍵碼。
		KBDLLHOOKSTRUCT* pKeyboard = (KBDLLHOOKSTRUCT*)lParam;
		// 檢查是否按下 某 鍵
		auto key = code__key[pKeyboard->vkCode];
		//KeyEvent a();
		KeyState keyState;
		if(wParam == WM_KEYDOWN){
			keyState = KeyState::down;
		}else if(wParam == WM_KEYUP){
			keyState = KeyState::up;
		}
		ans = KeyEvent(key, keyState);
		return 0;
	}
	return -1;
}

}//~namespace ngaq