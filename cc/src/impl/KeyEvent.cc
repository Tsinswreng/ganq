#include "./KeyEvent.h"
#include "enum/KeyState.h"
namespace _ {

bool KeyEvent::isKeyDown(I_KeyEvent& e, I_Key& key){
	// println("e.key_()->code_(): ",e.key_()->code_());
	// println("key.code_(): ",key.code_());
	// println("e.state_() == KeyState::down: ",e.state_() == KeyState::down);
	// println("e.state_() == KeyState::up: ",e.state_() == KeyState::up);
	if(
		e.key_()->code_() == key.code_()
		&& e.state_() == KeyState::down
	){
		return true;
	}
	return false;
}

bool KeyEvent::isKeyUp(I_KeyEvent& e, I_Key& key){
	// println("e.key_()->code_(): ",e.key_()->code_());
	// println("key.code_(): ",key.code_());
	// println("e.state_() == KeyState::down: ",e.state_() == KeyState::down);
	// println("e.state_() == KeyState::up: ",e.state_() == KeyState::up);
	if(
		e.key_()->code_() == key.code_()
		&& e.state_() == KeyState::up
	){
		return true;
	}
	return false;
}


}//namespace _