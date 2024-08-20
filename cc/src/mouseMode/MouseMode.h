#pragma once
#include "IF/I_KeyEvent.h"
#include "common.h"
#include "IF/I_handleKeyEvent.h"
#include "enum/KeyEventResult.h"
namespace ngaq {

class MouseMode : public I_handleKeyEvent{
public:
	KeyEventResult handleKeyEvent(I_KeyEvent& keyEvent){
		println("_____");
		println(keyEvent.key_());
		println(keyEvent.state_());
		return KeyEventResult::kNoop;
	}

};

}//~namespace ngaq

