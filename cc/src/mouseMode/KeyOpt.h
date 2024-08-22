#pragma once
#include "common.h"
#include "impl/Keys.h"
#include "IF/I_Key.h"

namespace _ {

class MouseModeOpt {

protected:
	Keys& keys = Keys::inst();
	i32 _step = 50;
public:
	an<I_Key> left = keys.J;
	an<I_Key> down = keys.K;
	an<I_Key> right = keys.L;
	an<I_Key> up = keys.Semicolon;
	i32 step_(){return _step;}
	void step_(i32 v){_step = v;}
};

}//~namespace _