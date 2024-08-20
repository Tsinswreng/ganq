#pragma once
#include "common.h"
#include "IF/I_KeyEvent.h"
#include "IF/I_Key.h"
#include "enum/KeyState.h"

namespace ngaq {

class KeyEvent : public I_KeyEvent {
public:
	//KeyEvent(){}
	KeyEvent(I_Key& key, KeyState state) : _key(key), _state(state) {}
	I_Key& key_() override { return _key; }
	KeyState state_() override { return _state; }

protected:
	I_Key& _key;
	KeyState _state;
};

}//~namespace ngaq