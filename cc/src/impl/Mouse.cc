#include "./Mouse.h"
#include <windows.h>
// #include <cstdio>
// #include "IF/I_Coord2d.h"
#include "impl/Coord2d.h"

namespace _ {

i32 Mouse::moveTo(i32 x, i32 y) {
	SetCursorPos(x, y);
	return 0;
}

i32 Mouse::move(Direct2d direct, i32 distance) {
	POINT p;
	GetCursorPos(&p);

	switch (direct) {
		case Direct2d::up:
			p.y -= distance;
			break;
		case Direct2d::down:
			p.y += distance;
			break;
		case Direct2d::left:
			p.x -= distance;
			break;
		case Direct2d::right:
			p.x += distance;
			break;
		default:
			break;
	}

	SetCursorPos(p.x, p.y);
	return 0;
}

i32 Mouse::move_hv(i32 horiz, i32 vert) {
	POINT p;
	GetCursorPos(&p);

	// 更新鼠標位置
	p.x += horiz;
	p.y += vert;

	SetCursorPos(p.x, p.y);
	return 0;
}

i32 Mouse::scroll_hv(i32 horiz, i32 vert) {
	// 垂直滾動
	if (vert != 0) {
		mouse_event(MOUSEEVENTF_WHEEL, 0, 0, vert, 0);
	}
	// 水平滾動
	if (horiz != 0) {
		mouse_event(MOUSEEVENTF_HWHEEL, 0, 0, horiz, 0);
	}
	return 0;
}


i32 Mouse::curPos(I_Coord2d_i32& ans) {
	POINT p;
	GetCursorPos(&p);
	ans.x_(p.x);
	ans.y_(p.y);
	return 0;
}

// i32 Mouse::click() {
// 	click(MouseClick::left);
// 	return 0;
// }

// /**
//  * @deprecated
//  */
// i32 Mouse::click(MouseClick key) {
// 	DWORD button = (key == MouseClick::left) ? MOUSEEVENTF_LEFTDOWN : MOUSEEVENTF_RIGHTDOWN;

// 	// Simulate mouse down
// 	mouse_event(button, 0, 0, 0, 0);
// 	// Simulate mouse up
// 	mouse_event(button | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
// 	return 0;
// }

i32 Mouse::click(MouseClick key, KeyState keyState){
	// 枚舉 key 有 left, middle, right
	// 枚舉 keyState 有 up, down
	// 幫我實現這函數 平臺是windows

	DWORD button;
	switch (key) {
		case MouseClick::left:
			button = MOUSEEVENTF_LEFTDOWN;
			break;
		case MouseClick::middle:
			button = MOUSEEVENTF_MIDDLEDOWN;
			break;
		case MouseClick::right:
			button = MOUSEEVENTF_RIGHTDOWN;
			break;
		default:
			return -1; // Invalid mouse button
	}

	// Determine the action (down or up)
	if (keyState == KeyState::down) {
		// Simulate mouse button down
		mouse_event(button, 0, 0, 0, 0);
		return 0;
	} else if (keyState == KeyState::up) {
		// Simulate mouse button up
		button = (key == MouseClick::left) ? MOUSEEVENTF_LEFTUP :
					(key == MouseClick::middle) ? MOUSEEVENTF_MIDDLEUP :
					MOUSEEVENTF_RIGHTUP;
		mouse_event(button, 0, 0, 0, 0);
		return 0;
	} else {
		return -1; // Invalid key state
	}

	return 0;
}



} // namespace _
