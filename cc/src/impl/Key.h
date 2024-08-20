#pragma once
#include "IF/I_Key.h"

namespace ngaq{

class Key : public I_Key{
public:
	Key(const string& name, i32 code)
		:_name(name), _code(code){};
	~Key(){};

	string name_(){ return _name; }
	i32 code_(){ return _code; }
	// 重载 == 运算符
	bool operator==(const Key& other) const {
		//return (_name == other._name) && (_code == other._code);
		return _code == other._code;
	}

protected:
	string _name;
	i32 _code;
};

}//~namespace ngaq
