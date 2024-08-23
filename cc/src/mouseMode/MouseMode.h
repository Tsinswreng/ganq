#pragma once
#include "IF/I_KeyEvent.h"
#include "common.h"
#include "IF/I_handleKeyEvent.h"
#include "enum/KeyEventResult.h"
#include "enum/KeyState.h"
#include "enum/MouseClick.h"
#include "impl/KeyEvent.h"
#include "impl/Mouse.h"
#include "impl/Keys.h"
#include "./Status.h"
#include "tools/AnsiColors.h"
#include "./KeyOpt.h"


// typescript 中、我在兩個文件中分別用type關鍵字定義了相同的類型別名、那麼這兩個類型別名是互不幹擾的、只在當前文件中有效。c++如何實現這個?
static auto& AC = _::AnsiColors::inst();
namespace MouseMode{
	//using KeyEvent::isKeyDown;
	using namespace _;	
	using Kt = an<I_KeyEvent>;
	using Fn_t = Fun<Opt<KeyEventResult>()>;
}

namespace _ {

class MouseMode : public I_handleKeyEvent{

protected:
	UMap<i32, ::MouseMode::Fn_t> keyCode__fn;
	void _init_keyCode__fn();

	::MouseMode::Kt _curKey;
	MouseModeOpt& _opt = MouseModeOpt::inst();
	Mouse _mouse;
	Keys keys = Keys::inst();
	an<Status> _status = mkuq<Status>();
	void _updShiftStatus(::MouseMode::Kt key);
public:

	MouseMode(){
		_init_keyCode__fn();
	}
	//MouseModeOpt opt_(){return _opt;}

	an<Status> status_(){return _status;}
	//void status_(Status v){_status = v;}


	KeyEventResult handleKeyEvent(an<I_KeyEvent> key);

	// KeyEventResult normalMove(an<I_KeyEvent> key){
	// 	auto step = status_()->mouseStep_normal_();
	// 	if( KeyEvent::isKeyDown(*key, *keys.J) ){
	// 		_mouse.move_cc(-1*step, 0);
	// 		return KeyEventResult::kAccepted;
	// 	}

	// 	if( KeyEvent::isKeyDown(*key, *keys.K) ){
	// 		_mouse.move_cc(0, step);
	// 		return KeyEventResult::kAccepted;
	// 	}

	// 	if( KeyEvent::isKeyDown(*key, *keys.L) ){
	// 		_mouse.move_cc(0, -1*step);
	// 		return KeyEventResult::kAccepted;
	// 	}

	// 	if( KeyEvent::isKeyDown(*key, *keys.Semicolon) ){
	// 		_mouse.move_cc(step, 0);
	// 		return KeyEventResult::kAccepted;
	// 	}
	// 	return KeyEventResult::kNoop;
	// }

	// KeyEventResult fastMove(an<I_KeyEvent> key){
	// 	auto step = status_()->mouseStep_normal_() * 4;
	// 	if( KeyEvent::isKeyDown(*key, *keys.N) ){
	// 		_mouse.move_cc(-1*step, 0);
	// 		return KeyEventResult::kAccepted;
	// 	}

	// 	if( KeyEvent::isKeyDown(*key, *keys.M) ){
	// 		_mouse.move_cc(0, step);
	// 		return KeyEventResult::kAccepted;
	// 	}

	// 	if( KeyEvent::isKeyDown(*key, *keys.Comma) ){
	// 		_mouse.move_cc(0, -1*step);
	// 		return KeyEventResult::kAccepted;
	// 	}

	// 	if( KeyEvent::isKeyDown(*key, *keys.Period) ){
	// 		_mouse.move_cc(step, 0);
	// 		return KeyEventResult::kAccepted;
	// 	}
	// 	return KeyEventResult::kNoop;
	// }

	// KeyEventResult scrollMove(an<I_KeyEvent> key){
	// 	auto step = status_()->mouseStep_normal_();
	// 	if( KeyEvent::isKeyDown(*key, *keys.J) ){
	// 		_mouse.move_cc(-1*step, 0);
	// 		return KeyEventResult::kAccepted;
	// 	}

	// 	if( KeyEvent::isKeyDown(*key, *keys.K) ){
	// 		_mouse.move_cc(0, step);
	// 		return KeyEventResult::kAccepted;
	// 	}

	// 	if( KeyEvent::isKeyDown(*key, *keys.L) ){
	// 		_mouse.move_cc(0, -1*step);
	// 		return KeyEventResult::kAccepted;
	// 	}

	// 	if( KeyEvent::isKeyDown(*key, *keys.Semicolon) ){
	// 		_mouse.move_cc(step, 0);
	// 		return KeyEventResult::kAccepted;
	// 	}
	// 	return KeyEventResult::kNoop;
	//}

};

}//~namespace _

