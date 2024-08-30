#include "./MouseMode.h"
#include <thread>
#include <chrono>

namespace _ {

void MouseMode::_updStatus(::MouseMode::Kt key){

	status_()->cnt ++;
	auto prev = status_()->history_()->backGet(1);
	
	if(prev != nullptr && KeyEvent::eq(*_curKey, *prev)){
		status_()->duplicateEvent_(true);
	}else{
		status_()->duplicateEvent_(false);
	}
	

	if(
		KeyEvent::isKeyDown(*key, *keys.Shift_L)
		|| KeyEvent::isKeyDown(*key, *keys.Shift_R)
	){
		_status->isShiftDown_(true);
		
	}else if(
		KeyEvent::isKeyUp(*key, *keys.Shift_L)
		|| KeyEvent::isKeyUp(*key, *keys.Shift_R)
	){
		_status->isShiftDown_(false);
		
	}
	

}

//TODO 每次按鍵都會開一個新的線程
KeyEventResult MouseMode::_normalMove_cc(i32 x, i32 y){
	if(_curKey->state_() == KeyState::down){
		std::thread([this, x, y](){
			auto initCnt = status_()->cnt;
			for(i32 i = 0;;i++){
				_mouse.move_cc(
					x,y
				);

				if(
					status_()->cnt != initCnt
					&& !status_()->duplicateEvent_()
				){
					break;
				}
				std::this_thread::sleep_for(
					std::chrono::milliseconds(50)
				);
			}
			
		}).detach();
	}else{
		
	}
	return KeyEventResult::kAccepted;
}

void MouseMode::_init_keyCode__fn(){
		//左鍵
		auto& M = keyCode__fn;
		M[keys.W->code_()] = [this]()->Opt<KeyEventResult>{
			if(_curKey->state_() == KeyState::down){
				_mouse.click(MouseClick::left, KeyState::down);
			}else{
				_mouse.click(MouseClick::left, KeyState::up);
			}
			return KeyEventResult::kAccepted;
		};
		//右鍵
		M[keys.E->code_()] = [this]()->Opt<KeyEventResult>{
			if(_curKey->state_() == KeyState::down){
				_mouse.click(MouseClick::right, KeyState::down);
			}else{
				_mouse.click(MouseClick::right, KeyState::up);
			}
			return KeyEventResult::kAccepted;
		};



		// 試 持續左移 //TODO 用線程池 否則每次按鍵都會開一個新的線程
		// M[keys.H->code_()] = [this]()->Opt<KeyEventResult>{
		// 	return _normalMove_cc(-1 * _status->mouseStep_normal_(), 0);
		// };

		// 左移
		M[keys.J->code_()] = [this]()->Opt<KeyEventResult>{
			return _normalMove_cc(-1 * _status->mouseStep_normal_(), 0);
		};
		// 右移
		M[keys.Semicolon->code_()] = [this]()->Opt<KeyEventResult>{
			return _normalMove_cc(1 * _status->mouseStep_normal_(), 0);
		};

		// 下移
		M[keys.K->code_()] = [this]()->Opt<KeyEventResult>{
			return _normalMove_cc(
				0, _status->mouseStep_normal_() * -1
			);
			
		};

		// 上移
		M[keys.L->code_()] = [this]()->Opt<KeyEventResult>{
			return _normalMove_cc(
				0, _status->mouseStep_normal_()
			);
		};
		// ---- 快速

		// 快左移
		M[keys.N->code_()] = [this]()->Opt<KeyEventResult>{
			if(_curKey->state_() == KeyState::down){
				_mouse.move_cc(
					-1 * _status->mouseStep_fast_(), 0
				);
			}else{
				
			}
			return KeyEventResult::kAccepted;
		};
		// 快右移
		M[keys.Period->code_()] = [this]()->Opt<KeyEventResult>{
			if(_curKey->state_() == KeyState::down){
				_mouse.move_cc(
					_status->mouseStep_fast_(), 0
				);
			}else{
				
			}
			return KeyEventResult::kAccepted;
		};

		// 快下移
		M[keys.M->code_()] = [this]()->Opt<KeyEventResult>{
			if(_curKey->state_() == KeyState::down){
				_mouse.move_cc(
					0, _status->mouseStep_fast_() * -1
				);
			}else{
				
			}
			return KeyEventResult::kAccepted;
		};

		// 快上移
		M[keys.Comma->code_()] = [this]()->Opt<KeyEventResult>{
			if(_curKey->state_() == KeyState::down){
				_mouse.move_cc(
					0, _status->mouseStep_fast_()
				);
			}else{
				
			}
			return KeyEventResult::kAccepted;
		};


		// ---- 滾輪

		// 左移
		M[keys.A->code_()] = [this]()->Opt<KeyEventResult>{
			if(_curKey->state_() == KeyState::down){
				_mouse.scroll_cc(
					-1 * _status->mouseStep_normal_(), 0
				);
			}else{
				
			}
			return KeyEventResult::kAccepted;
		};
		// 右移
		M[keys.F->code_()] = [this]()->Opt<KeyEventResult>{
			println("right");
			if(_curKey->state_() == KeyState::down){
				_mouse.scroll_cc(
					_status->mouseStep_normal_(), 0
				);
			}else{
				
			}
			return KeyEventResult::kAccepted;
		};

		// 下移
		M[keys.S->code_()] = [this]()->Opt<KeyEventResult>{
			if(_curKey->state_() == KeyState::down){
				_mouse.scroll_cc(
					0, _status->mouseStep_normal_() * -1
				);
			}else{
				
			}
			return KeyEventResult::kAccepted;
		};

		// 上移
		M[keys.D->code_()] = [this]()->Opt<KeyEventResult>{
			if(_curKey->state_() == KeyState::down){
				_mouse.scroll_cc(
					0, _status->mouseStep_normal_()
				);
			}else{
				
			}
			return KeyEventResult::kAccepted;
		};
		// ---- 快速

		// M[keys.J->code_()] = [this]()->Opt<KeyEventResult>{
		// if(_curKey->state_() == KeyState::down){
				
		// 	}else{
				
		// 	}
		// 	return KeyEventResult::kAccepted;
		// };
}

KeyEventResult MouseMode::handleKeyEvent(an<I_KeyEvent> key){
	_curKey = key;

	_status->history_()->addBackF(key);
	_updStatus(key);
	//println(1);// -

	println("_____");
	println("name: ", key->key_()->name_());
	println("code: ", key->key_()->code_());
	println( "state: ",
		static_cast<i32>(key->state_())
	);
	//println(AC.Cyan, "mouseMode: ", status_()->isMouseMode_(), AC.Reset);
	//println(keyEvent.state_());
	println(AC.Cyan, "duplicateEvent_: ", status_()->duplicateEvent_(), AC.Reset);

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
		println(AC.Green, "isMouseMode_ false", AC.Reset);
		return KeyEventResult::kNoop;
	}



	if(status_()->isShiftDown_()){
		status_()->mouseStep_normal_(
			_opt.mouseStep_slow_()
		);
		status_()->mouseStep_fast_(
			_opt.mouseStep_faster_()
		);
		// TODO 不按shift旹 每次按鍵 下面都執行
	}else{
		status_()->mouseStep_normal_(
			_opt.mouseStep_()
		);
		status_()->mouseStep_fast_(
			_opt.mouseStep_fast_()
		);
	}

	auto it = keyCode__fn.find(key->key_()->code_());
	
	if(it != keyCode__fn.end()){ // 判斷是否有對應的函式
		auto resl = it->second();
		if(resl != nullopt){
			return resl.value();
		}
	}

	// normalMove(key);
	// fastMove(key);

	return KeyEventResult::kAccepted;
}

}//~namespace _