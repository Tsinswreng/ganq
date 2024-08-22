#include "common.h"
#include "Windows.h"
#include "impl/KeyEvent.h"

namespace _ {


i32 convertKeyEvent(
	an<KeyEvent>& ans // 在函數中改 指針ʃ指 需 an<KeyEvent>& 而非 an<KeyEvent>
	,int nCode // 鉤子事件類型
	, WPARAM wParam // 按下按鍵的 wParam 值 在鍵盤鉤子中，它通常表示按鍵的狀態（按下或釋放）。
	, LPARAM lParam // 該結構包含有關鍵盤事件的詳細信息。
);


}//~namespace _
