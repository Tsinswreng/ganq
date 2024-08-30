#pragma once
#include "common.h"
#include "IF/I_handleKeyEvent.h"
#include "enum/KeyEventResult.h"
namespace _ {

class FastArrow : public I_handleKeyEvent {
public:
	KeyEventResult handleKeyEvent(an<I_KeyEvent> keyEvent) override;
};

}//~namespace _
