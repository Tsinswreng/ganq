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
#include "tools/AnsiColors.h"
#include "./KeyOpt.h"

// typescript 中、我在兩個文件中分別用type關鍵字定義了相同的類型別名、那麼這兩個類型別名是互不幹擾的、只在當前文件中有效。c++如何實現這個?
namespace {
	//using KeyEvent::isKeyDown;
	using namespace _;
	static auto& AC = AnsiColors::inst();
	using Kt = an<I_KeyEvent>;
}

namespace _ {

class MouseMode : public I_handleKeyEvent{

protected:
	MouseModeOpt _opt;
	Mouse _mouse;
	Keys keys = Keys::inst();
	an<Status> _status = mkuq<Status>();
	void _updStatus(){

	}
public:
	MouseModeOpt opt_(){return _opt;}

	an<Status> status_(){return _status;}
	//void status_(Status v){_status = v;}


	KeyEventResult handleKeyEvent(an<I_KeyEvent> key){
		println("_____");
		println("name: ", key->key_()->name_());
		println("code: ", key->key_()->code_());
		println( "state: ",
			static_cast<i32>(key->state_())
		);
		println(AC.Cyan, "mouseMode: ", status_()->isMouseMode_(), AC.Reset);
		//println(keyEvent.state_());
		if(
			KeyEvent::isKeyDown(*key, *keys.F1)
		){
			if(status_()->isMouseMode_()){
				status_()->isMouseMode_(false);
			}else{
				status_()->isMouseMode_(true);
			}
			return KeyEventResult::kAccepted;
		}
		if(!status_()->isMouseMode_()){
			return KeyEventResult::kNoop;
		}

		normalMove(key);
		fastMove(key);

		return KeyEventResult::kAccepted;
	}

	KeyEventResult normalMove(an<I_KeyEvent> key){
		auto step = opt_().step_();
		if( KeyEvent::isKeyDown(*key, *keys.J) ){
			_mouse.move_hv(-1*step, 0);
			return KeyEventResult::kAccepted;
		}

		if( KeyEvent::isKeyDown(*key, *keys.K) ){
			_mouse.move_hv(0, step);
			return KeyEventResult::kAccepted;
		}

		if( KeyEvent::isKeyDown(*key, *keys.L) ){
			_mouse.move_hv(0, -1*step);
			return KeyEventResult::kAccepted;
		}

		if( KeyEvent::isKeyDown(*key, *keys.Semicolon) ){
			_mouse.move_hv(step, 0);
			return KeyEventResult::kAccepted;
		}
		return KeyEventResult::kNoop;
	}

	KeyEventResult fastMove(an<I_KeyEvent> key){
		auto step = opt_().step_() * 4;
		if( KeyEvent::isKeyDown(*key, *keys.N) ){
			_mouse.move_hv(-1*step, 0);
			return KeyEventResult::kAccepted;
		}

		if( KeyEvent::isKeyDown(*key, *keys.M) ){
			_mouse.move_hv(0, step);
			return KeyEventResult::kAccepted;
		}

		if( KeyEvent::isKeyDown(*key, *keys.Comma) ){
			_mouse.move_hv(0, -1*step);
			return KeyEventResult::kAccepted;
		}

		if( KeyEvent::isKeyDown(*key, *keys.Period) ){
			_mouse.move_hv(step, 0);
			return KeyEventResult::kAccepted;
		}
		return KeyEventResult::kNoop;
	}

	KeyEventResult scrollMove(an<I_KeyEvent> key){
		auto step = opt_().step_();
		if( KeyEvent::isKeyDown(*key, *keys.J) ){
			_mouse.move_hv(-1*step, 0);
			return KeyEventResult::kAccepted;
		}

		if( KeyEvent::isKeyDown(*key, *keys.K) ){
			_mouse.move_hv(0, step);
			return KeyEventResult::kAccepted;
		}

		if( KeyEvent::isKeyDown(*key, *keys.L) ){
			_mouse.move_hv(0, -1*step);
			return KeyEventResult::kAccepted;
		}

		if( KeyEvent::isKeyDown(*key, *keys.Semicolon) ){
			_mouse.move_hv(step, 0);
			return KeyEventResult::kAccepted;
		}
		return KeyEventResult::kNoop;
	}

};

}//~namespace _

