#pragma once
#include "IF/I_KeyStatus.h"
#include "common.h"
#include "tools/CyclicArray/CyclicArray.h"
namespace _ {

class KeyStatus : public I_KeyStatus {
public:

	// ::I_KeyStatus::KeyHistory history_(){return _history;}
	// void history_(::I_KeyStatus::KeyHistory v){_history = v;}

protected:

	// ::I_KeyStatus::KeyHistory _history
	// 	= New<CyclicArray<>>
	;
	


};

}//~namespace _