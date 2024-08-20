#pragma once
#include "IF/I_KeyEvent.h"
#include "common.h"
#include "IF/I_handleKeyEvent.h"
#include "enum/KeyEventResult.h"
#include "enum/KeyState.h"
#include "impl/Mouse.h"
#include "impl/Keys.h"
#include "enum/Direct2d.h"
namespace ngaq {

class MouseMode : public I_handleKeyEvent{

protected:
	Mouse mouse;
	Keys keys = Keys::inst();

public:
	KeyEventResult handleKeyEvent(I_KeyEvent& key){
		println("_____");
		println("key: ", &key);
		println("name: ", key.key_().name_());
		println( "state: ",
			static_cast<i32>(key.state_())
		);
		//println(keyEvent.state_());
		if(
			key.key_().code_() == keys.J->code_()
			&& key.state_() == KeyState::down
		){
			mouse.move(Direct2d::left, 50);
		}
		return KeyEventResult::kNoop;
	}

};

}//~namespace ngaq

