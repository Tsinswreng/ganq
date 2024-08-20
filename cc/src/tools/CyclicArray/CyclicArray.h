#include "tools/CyclicArray/I_CyclicArray.h"
#include <stdexcept>

template <typename T>
class CyclicArray : public I_CyclicArray<T> {
private:
	std::vector<T> _data;
	i32 _size = 0;
	i32 _capacity = 0;
	i32 _frontI = 0;
	i32 _backI = 0;

public:
	CyclicArray(i32 capacity) {
		if (capacity <= 0) {
			throw std::out_of_range("Capacity must be greater than 0");
		}
		_capacity = capacity;
		_data.resize(capacity);
	}

	i32 capacity_() override {
		return _capacity;
	}

	i32 size_() override {
		return _size;
	}

	bool isEmpty() override {
		return _size == 0;
	}

	bool isFull() override {
		return _size == _capacity;
	}

	i32 clear() override {
		_data.clear();
		_data.resize(_capacity);
		_size = 0;
		_frontI = 0;
		_backI = 0;
		return 0;
	}

	static i32 posAdd(i32 index, i32 capacity, i32 num) {
		index = (index+num) % capacity;
		return index;
	}

	static i32 posSub(i32 index, i32 capacity, i32 num){
		num = num % capacity;
		index -= num;
		if (index < 0) {
			index += capacity;
		}
		return index;
	}

	i32 addBack(T ele) override {
		if (isFull()) {
			return -1; // Indicate failure
		}
		if (isEmpty()) {
			_data[_backI] = ele;
		} else {
			_backI = posAdd(_backI, _capacity, 1);
			_data[_backI] = ele;
		}
		_size += 1;
		return 0;
	}

	std::optional<T> addBackF(T ele) override {
		if (addBack(ele) == 0) {
			return std::nullopt;
		}
		auto front = rmFront();
		addBack(ele);
		return front;
	}

	std::optional<T> rmBack() override {
		if (isEmpty()) {
			return std::nullopt;
		}
		T t = backGet(0);
		//_data[_backI] = T(); // Clear the value
		_size -= 1;
		_backI = posSub(_backI, _capacity, 1);
		return t;
	}

	T backGet(i32 pos) override {
		return _data[posSub(_backI, _capacity, pos)];
	}

	void backSet(i32 num, T ele) override {
		_data[posSub(_backI, _capacity, num)] = ele;
	}

	i32 addFront(T ele) override {
		if (isFull()) {
			return -1; // Indicate failure
		}
		if (isEmpty()) {
			_data[_frontI] = ele;
		} else {
			_frontI = posSub(_frontI, _capacity, 1);
			_data[_frontI] = ele;
		}
		_size += 1;
		return 0;
	}

	std::optional<T> addFrontF(T ele) override {
		if (addFront(ele) == 0) {
			return std::nullopt;
		}
		auto back = rmBack();
		addFront(ele);
		return back;
	}

	std::optional<T> rmFront() override {
		if (isEmpty()) {
			return std::nullopt;
		}
		T t = frontGet(0);
		//_data[_frontI] = T(); // Clear the value
		_frontI = posAdd(_frontI, _capacity, 1);
		_size -= 1;
		return t;
	}

	T frontGet(i32 pos) override {
		return _data[posAdd(_frontI, _capacity, pos)];
	}

	void frontSet(i32 num, T ele) override {
		_data[posAdd(_frontI, _capacity, num)] = ele;
	}

	void capacityAdd(i32 add) override {
		if (add < 0) {
			throw std::invalid_argument("Cannot decrease capacity");
		}
		std::vector<T> newData(_capacity + add);
		for (i32 i = 0; i < _size; ++i) {
			newData[i] = frontGet(i);
		}
		_data = std::move(newData);
		_capacity += add;
		_frontI = 0;
		_backI = _size - 1;
	}

	// std::function<std::optional<T>(i32)> frontIterFn() override {
	// 	i32 i = 0;
	// 	return [this](i32 cnt=1) {
	// 		auto ans = frontGet(cnt);
	// 	};
	// }

	// std::function<std::optional<T>(i32)> backIterFn() override {
	// 	return [this](i32 cnt) {
	// 		if (cnt < 0 || cnt >= _size) {
	// 			return std::nullopt;
	// 		}
	// 		return backGet(cnt);
	// 	};
	// }

	std::vector<T> toVector() override {
		std::vector<T> result;
		for (i32 i = 0; i < _size; ++i) {
			result.push_back(frontGet(i));
		}
		return result;
	}
};