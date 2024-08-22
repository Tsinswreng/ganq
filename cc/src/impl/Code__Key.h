#pragma once

#ifndef KEY_MAPPING_H
#define KEY_MAPPING_H

#include "common.h"
//#include <unordered_map>
#include "./Keys.h" // 确保包含 Keys 类的定义


namespace Code__Key{
	using namespace _;
	using KMap = UMap<i32, an<Key>>;
	inline an<Key> KEY(an<Key> key){
		return key;
	}

} //namespace

namespace _ {

class Code__Key {
public:
	~Code__Key() {}
	::Code__Key::KMap map_(){return _map;}
	static Code__Key& inst(){
		static Code__Key keys;
		return keys;
	}
protected:
	Code__Key(){
		_map = createM();
	}

	::Code__Key::KMap _map;
	::Code__Key::KMap createM();
};

}//~namespace _

#endif // KEY_MAPPING_H
