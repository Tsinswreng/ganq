#pragma once
#include "common.h"
#include "impl/Keys.h"
#include "IF/I_Key.h"
namespace ngaq {

class MouseOpt {

protected:
	Keys keys = Keys::inst();

public:
	an<I_Key> left = keys.J;
	an<I_Key> down = keys.K;
	an<I_Key> right = keys.L;
	an<I_Key> up = keys.Semicolon;
};

}//~namespace ngaq