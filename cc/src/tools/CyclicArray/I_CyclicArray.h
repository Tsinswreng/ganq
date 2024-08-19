#pragma once
#include <optional>
#include <functional>
#include <vector>
using i32 = int;

namespace {
	template <typename T>
	using opt = std::optional<T>;
}

template <typename T>
class I_CyclicArray{
public:
	virtual i32 capacity_()=0;
	virtual i32 size_()=0;
	virtual bool isEmpty()=0;
	virtual bool isFull()=0;
	virtual i32 clear()=0;

	// virtual i32 posAdd(i32 index, i32 capacity, i32 num);
	// virtual i32 posSub(i32 index, i32 capacity, i32 num);

	virtual i32 addBack(T ele)=0;
	virtual opt<T> addBackF(T ele)=0;
	virtual opt<T> rmBack()=0;
	virtual T backGet(i32 pos)=0;
	virtual void backSet(i32 num, T ele)=0;

	virtual i32 addFront(T ele)=0;
	virtual opt<T> addFrontF(T ele)=0;
	virtual opt<T> rmFront()=0;
	virtual T frontGet(i32 pos)=0;
	virtual void frontSet(i32 num, T ele)=0;
	virtual void capacityAdd(i32 add)=0;
	virtual std::function<i32(i32)> frontIterFn()=0;
	virtual std::function<i32(i32)> backIterFn()=0;
	virtual std::vector<T> toVector()=0;
};
