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
	using Fn_t = Fun<Opt<KeyEventResult>(Kt)>;
}

namespace _ {

class MouseMode : public I_handleKeyEvent{

protected:
	UMap<i32, ::MouseMode::Fn_t> keyCode__fn;
	void _init_keyCode__fn(){
		keyCode__fn[keys.W->code_()] = [this](an<I_KeyEvent> key)->Opt<KeyEventResult>{
			_mouse.click();
			return KeyEventResult::kAccepted;
		};

		keyCode__fn[keys.E->code_()] = [this](an<I_KeyEvent> key)->Opt<KeyEventResult>{
			_mouse.click(MouseClick::right);
			return KeyEventResult::kAccepted;
		};

	}
	MouseModeOpt& _opt = MouseModeOpt::inst();
	Mouse _mouse;
	Keys keys = Keys::inst();
	an<Status> _status = mkuq<Status>();
	void _updStatus(::MouseMode::Kt key){
		_status->history_()->addBackF(key);

		if(
			KeyEvent::isKeyDown(*key, *keys.Shift_L)
			|| KeyEvent::isKeyDown(*key, *keys.Shift_R)
		){
			_status->isShiftDown_(true);
			return;
		}

		if(
			KeyEvent::isKeyUp(*key, *keys.Shift_L)
			|| KeyEvent::isKeyUp(*key, *keys.Shift_R)
		){
			_status->isShiftDown_(false);
			return;
		}
	}
public:

	MouseMode(){
		_init_keyCode__fn();
	}
	//MouseModeOpt opt_(){return _opt;}

	an<Status> status_(){return _status;}
	//void status_(Status v){_status = v;}


	KeyEventResult handleKeyEvent(an<I_KeyEvent> key){
		//println(0);
		_updStatus(key);
		//println(1);// -
		if(status_()->isShiftDown_()){
			status_()->mouseStep_(
				_opt.mouseStep_slow_()
			);
		}else{
			status_()->mouseStep_(
				_opt.mouseStep_()
			);
		}
		println("_____");
		println("name: ", key->key_()->name_());
		println("code: ", key->key_()->code_());
		println( "state: ",
			static_cast<i32>(key->state_())
		);
		println(AC.Cyan, "mouseMode: ", status_()->isMouseMode_(), AC.Reset);
		//println(keyEvent.state_());

		auto it = keyCode__fn.find(key->key_()->code_());
		
		if(it != keyCode__fn.end()){ // 判斷是否有對應的函式
			auto resl = it->second(key);
			if(resl != nullopt){
				return resl.value();
			}
		}
		
		
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
		auto step = status_()->mouseStep_();
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
		auto step = status_()->mouseStep_() * 4;
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
		auto step = status_()->mouseStep_();
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

