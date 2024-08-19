#pragma once
#include "IF/I_Mouse.h"
#include "IF/I_Coord2d.h"



namespace ngaq {

namespace {
	//使 只在當前文件中有效
	using Coord2d = I_Coord2d<i32>;
}


class Mouse : public I_Mouse {
public:
	i32 moveTo(int x, int y) override;
	i32 move(Direct2d direct, i32 distance) override;
	i32 curPos(Coord2d& pos) override;
	i32 click() override;
	i32 click(MouseClick key) override;
};

} // namespace ngaq
