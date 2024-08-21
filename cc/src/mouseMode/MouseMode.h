#pragma once
#include "IF/I_KeyEvent.h"
#include "common.h"
#include "IF/I_handleKeyEvent.h"
#include "enum/KeyEventResult.h"
#include "enum/KeyState.h"
#include "impl/KeyEvent.h"
#include "impl/Mouse.h"
#include "impl/Keys.h"
#include "./Status.h"

namespace ngaq {


namespace {
	//using KeyEvent::isKeyDown;
}

class MouseMode : public I_handleKeyEvent{

protected:
	Mouse mouse;
	Keys keys = Keys::inst();
	an<Status> _status = mkuq<Status>();
public:
	an<Status> status_(){return _status;}
	//void status_(Status v){_status = v;}


	KeyEventResult handleKeyEvent(an<I_KeyEvent> key){
		println("_____");
		println("key: ", &key);
		println("name: ", key->key_()->name_());
		println( "state: ",
			static_cast<i32>(key->state_())
		);
		//println(keyEvent.state_());
		if(
			!KeyEvent::isKeyUp(*key, *keys.F1)
		){
			if(status_()->isMouseMode_()){
				status_()->isMouseMode_(false);
			}else{
				status_()->isMouseMode_(true);
			}
			//return KeyEventResult::kAccepted;
		}

		if(!status_()->isMouseMode_()){
			return KeyEventResult::kNoop;
		}

		if( KeyEvent::isKeyDown(*key, *keys.J) ){
			mouse.move_hv(-50, 0);
			return KeyEventResult::kAccepted;
		}

		if( KeyEvent::isKeyDown(*key, *keys.K) ){
			mouse.move_hv(0, 50);
			return KeyEventResult::kAccepted;
		}

		if( KeyEvent::isKeyDown(*key, *keys.L) ){
			mouse.move_hv(0, -50);
			return KeyEventResult::kAccepted;
		}

		if( KeyEvent::isKeyDown(*key, *keys.Semicolon) ){
			mouse.move_hv(50, 0);
			return KeyEventResult::kAccepted;
		}
		return KeyEventResult::kAccepted;
	}

};

}//~namespace ngaq

