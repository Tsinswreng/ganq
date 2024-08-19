#pragma once
#include "common.h"
#include "IF/I_KeyEvent.h"

namespace ngaq {

class I_hanleKeyEvent {
public:
	virtual i32 handleKeyEvent(an<I_KeyEvent> keyEvent) = 0;
};

}//~namespace ngaq