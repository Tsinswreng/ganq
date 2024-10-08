#pragma once
#include "common.h"
#include "IF/I_Key.h"
#include "enum/KeyState.h"
namespace _ {

class I_KeyEvent {
public:
	virtual an<I_Key> key_() = 0;
	virtual KeyState state_() = 0;
};

}//~namespace _