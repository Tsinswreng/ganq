#pragma once
#include "common.h"
#include "IF/I_KeyEvent.h"
#include "enum/KeyEventResult.h"
namespace _ {

class I_handleKeyEvent {
public:
	virtual KeyEventResult handleKeyEvent(an<I_KeyEvent> keyEvent) = 0;
};

}//~namespace _