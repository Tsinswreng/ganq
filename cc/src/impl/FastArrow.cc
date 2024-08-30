#include "common.h"
#include "./FastArrow.h"
#include "enum/KeyEventResult.h"
#include "impl/Keys.h"

static auto& keys = _::Keys::inst();
namespace _ {

KeyEventResult FastArrow::handleKeyEvent(an<I_KeyEvent> keyEvent){
	if(keyEvent->key_()->code_() == keys.Alt_L->code_()){

	}
	return KeyEventResult::kNoop;
}

}//~namespace _
