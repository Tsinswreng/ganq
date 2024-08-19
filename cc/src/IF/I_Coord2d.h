#pragma once
namespace ngaq{

template <class Num_t>
class I_Coord2d{
public:
	virtual Num_t x_() = 0;
	virtual void x_(Num_t x) = 0;

	virtual Num_t y_() = 0;
	virtual void y_(Num_t y) = 0;
};

}//~namespace ngaq