#pragma once
#include "common.h"
namespace ngaq {

class I_Key {
public:
	virtual ~I_Key() = default;
	virtual string name_();
	virtual i32 code_();
};

}//~namespace ngaq