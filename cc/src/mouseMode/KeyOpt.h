#pragma once
#include "common.h"
#include "impl/Keys.h"
#include "IF/I_Key.h"

namespace _ {

/** @unused */
class MouseModeOpt {


protected:
	Keys& keys = Keys::inst();
	i32 _mouseStep = 15;
	i32 _mouseStep_slow = 5;
	i32 _mouseStep_fast = 200;
	i32 _mouseStep_faster = 800;
public:

	static MouseModeOpt& inst(){
		static MouseModeOpt inst;
		return inst;
	}

	an<I_Key> left = keys.J;
	an<I_Key> down = keys.K;
	an<I_Key> right = keys.L;
	an<I_Key> up = keys.Semicolon;
	i32 mouseStep_(){return _mouseStep;}
	void mouseStep_(i32 v){_mouseStep = v;}

	i32 mouseStep_slow_(){return _mouseStep_slow;}
	void mouseStep_slow_(i32 v){_mouseStep_slow = v;}

	i32 mouseStep_fast_(){return _mouseStep_fast;}
	void mouseStep_fast_(i32 v){_mouseStep_fast = v;}

	i32 mouseStep_faster_(){return _mouseStep_faster;}
	void mouseStep_faster_(i32 v){_mouseStep_faster = v;}


};

}//~namespace _