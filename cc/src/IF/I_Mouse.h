#pragma once
#include "common.h"
#include "enum/Direct2d.h"
#include "enum/MouseClick.h"
#include "IF/I_Coord2d.h"
#include "enum/KeyState.h"
namespace _ {

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
	/** 正方嚮: 右, 下 */
	virtual i32 move_hv(i32 x, i32 y) = 0;
	/** 正方嚮: 右, 下 */
	virtual i32 scroll_hv(i32 x, i32 y) = 0;
	virtual i32 curPos(Coord2d& ans) = 0;
	// virtual i32 click() = 0;
	// virtual i32 click(MouseClick key) = 0;
	virtual i32 click(MouseClick key, KeyState keyState) = 0;
};

}//~namespace _