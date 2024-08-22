#include "common.h"
#include "./convertKeyEvent.h"
#include "impl/KeyEvent.h"
#include "impl/Code__Key.h"
#include "enum/KeyState.h"
#include <iostream>
#include "tools/AnsiColors.h"

namespace _ {

static auto& AC = AnsiColors::inst();

i32 convertKeyEvent(
	_Out_ an<KeyEvent>& ans // 傳回的 KeyEvent 物件
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
		if(key == nullptr){
			//std::cerr <<AC.Yellow, "Unknown key code: " << pKeyboard->vkCode << std::endl;
			println(AC.Yellow, "Unknown key code: ", pKeyboard->vkCode, AC.Reset);
			return -1;
		}
		//KeyEvent a();
		KeyState keyState;
		if(wParam == WM_KEYDOWN){
			keyState = KeyState::down;
		}else if(wParam == WM_KEYUP){
			keyState = KeyState::up;
		}else{
			println(AC.Yellow, "Unknown key event: ", wParam, AC.Reset);
			//std::cerr << "Unknown key event: " << wParam << std::endl;
		}
// Object of type 'KeyEvent' cannot be assigned because its copy assignment operator is implicitly deleted clang(ovl_deleted_special_oper)
//KeyEvent.h(17, 9): Copy assignment operator of 'KeyEvent' is implicitly deleted because field '_key' is of reference type 'I_Key &'
		// auto keyEvent = mkuq<KeyEvent>(*key, keyState);
		// ans = mv(keyEvent);
		ans = New<KeyEvent>(key, keyState);
		//ans = mv(New<KeyEvent>(*key, keyState));
		return 0;
	}
	return -1;
}

}//~namespace _