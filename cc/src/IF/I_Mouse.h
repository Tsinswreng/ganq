#pragma once
#include "common.h"
#include "enum/Direct2d.h"
#include "enum/MouseClick.h"
#include "IF/I_Coord2d.h"

namespace ngaq {

namespace {
	//使 只在當前文件中有效
	using Coord2d = I_Coord2d<i32>;
}


class I_Mouse {
public:
	virtual ~I_Mouse() = default;
	virtual i32 moveTo(i32 x, i32 y) = 0;
	/** @deprecated */
	virtual i32 move(Direct2d direct, i32 distance) = 0;
	virtual i32 move_hv(i32 horiz, i32 vert) = 0;
	virtual i32 scroll_hv(i32 horiz, i32 vert) = 0;
	virtual i32 curPos(Coord2d& ans) = 0;
	virtual i32 click() = 0;
	virtual i32 click(MouseClick key) = 0;
	//TODO 向上滚动100个单位，向右滚动100个单位（斜着向右上角滚动）
	//ScrollMouse(100, 100);
	// virtual i32 move(垂直距, 水平距) = 0;
};

}//~namespace ngaq