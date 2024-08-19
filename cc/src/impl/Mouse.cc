#include "./Mouse.h"
#include <windows.h>
// #include <cstdio>
// #include "IF/I_Coord2d.h"
#include "impl/Coord2d.h"

namespace ngaq {

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

i32 Mouse::curPos(I_Coord2d_i32& ans) {
	POINT p;
	GetCursorPos(&p);
	ans.x_(p.x);
	ans.y_(p.y);
	return 0;
}

i32 Mouse::click() {
	click(MouseClick::left);
	return 0;
}

i32 Mouse::click(MouseClick key) {
	DWORD button = (key == MouseClick::left) ? MOUSEEVENTF_LEFTDOWN : MOUSEEVENTF_RIGHTDOWN;

	// Simulate mouse down
	mouse_event(button, 0, 0, 0, 0);
	// Simulate mouse up
	mouse_event(button | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
	return 0;
}

} // namespace ngaq
