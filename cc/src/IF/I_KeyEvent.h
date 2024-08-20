#pragma once
#include "common.h"
#include "IF/I_Key.h"
#include "enum/KeyState.h"
namespace ngaq {

class I_KeyEvent {
public:
	virtual I_Key& key_() = 0;
	virtual KeyState state_() = 0;
};

}//~namespace ngaq