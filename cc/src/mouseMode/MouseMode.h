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
		println("key: ", &keyEvent);
		println("name: ", keyEvent.key_().name_());
		println( "state: ",
			static_cast<i32>(keyEvent.state_())
		);
		//println(keyEvent.state_());
		return KeyEventResult::kNoop;
	}

};

}//~namespace ngaq

