#include "common.h"
#include "Windows.h"
#include "impl/KeyEvent.h"

namespace ngaq {

i32 convertKeyEvent(
	KeyEvent& ans
	,int nCode // 鉤子事件類型
	, WPARAM wParam // 按下按鍵的 wParam 值 在鍵盤鉤子中，它通常表示按鍵的狀態（按下或釋放）。
	, LPARAM lParam // 該結構包含有關鍵盤事件的詳細信息。
);


}//~namespace ngaq
