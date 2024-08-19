#pragma once
#include "common.h"
#include "IF/I_Coord2d.h"

namespace ngaq{

using I_Coord2d_i32 = I_Coord2d<i32>;

class Coord2d_i32 : public I_Coord2d<i32>{
public:
	Coord2d_i32(i32 x, i32 y) : _x(x), _y(y) {}
	i32 x_(){return _x;}
	void x_(i32 x){_x = x;}

	i32 y_(){return _y;}
	void y_(i32 y){_y = y;}
protected:
	i32 _x;
	i32 _y;
};

}//~namespace ngaq