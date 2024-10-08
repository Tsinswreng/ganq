#pragma once
#include "common.h"
namespace _ {

class I_Key {
public:
	virtual ~I_Key() = default;
	virtual string name_() = 0;
	virtual i32 code_() = 0;
};

}//~namespace _