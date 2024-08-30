#pragma once
#include "common.h"
#include "IF/I_Key.h"
#include "enum/KeyState.h"
#include "tools/CyclicArray/I_CyclicArray.h"

namespace I_KeyStatus {
using namespace _;

using KeyHistory = I_CyclicArray<an<I_Key>>;


}//~namespace I_KeyStatus

namespace _ {

class I_KeyStatus{
public:
	virtual ::I_KeyStatus::KeyHistory history_() = 0;
	virtual UMap<an<I_Key>, ::I_KeyStatus::KeyState> key__keyState_() = 0;
};

}//~namespace _
