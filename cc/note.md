## c++模板多態
<2024-08-22T16:10:04.993+08:00>

// I_CyclicArray是CyclicArray的父類、I_KeyEvent是KeyEvent的父類、an是共享指針
```cpp
	using I_KeyHistory = I_CyclicArray<an<I_KeyEvent>>;
	using KeyHistory = CyclicArray<an<KeyEvent>>;

	KeyHistory* kh = new KeyHistory(10);
	I_KeyHistory* kh = static_cast<I_KeyHistory*>(kh);
	//error//Incompatible pointer types assigning to 'I_KeyHistory *' (aka 'I_CyclicArray<shared_ptr<_::I_KeyEvent>> *') from 'KeyHistory *' (aka 'CyclicArray<shared_ptr<_::KeyEvent>> *')clang(typecheck_convert_incompatible_pointer)
```

AI曰
```
I_KeyHistory 和 KeyHistory 是两个不同的类型，尽管它们之间有继承关系，但由于模板参数的不同，它们并不能直接转换。

具体来说，I_KeyHistory 是一个模板类型 I_CyclicArray<an<I_KeyEvent>>，而 KeyHistory 是 CyclicArray<an<KeyEvent>>。这两个类型的模板参数 an<I_KeyEvent> 和 an<KeyEvent> 是不同的类型，即使 I_KeyEvent 是 KeyEvent 的父类，编译器仍然认为这两个类型不兼容。

在C++中，模板类型的特化是严格的，编译器不会自动进行类型转换。即使你使用 static_cast，编译器也会检查类型的兼容性，发现它们不兼容，因此会抛出错误。
```

改用
```cpp
using KeyHistory = CyclicArray<an<I_KeyEvent>>;
```

## powertoy改鍵
```cpp
#define HELP_PARTIALKEY   0x0105L
```

把退格映射成右alt:
```
_____
key: 0x9ff7c0
name: Backspace
state: 0 //down
e.key_()->code_(): 8
key.code_(): 165
e.state_() == KeyState::down: 1     
e.state_() == KeyState::up: 0       
Unknown key event: 260
_____
key: 0x9ff6a8
name: Alt_R
state: 1984579104 // 未初始化
e.key_()->code_(): 165
key.code_(): 165
e.state_() == KeyState::down: 0     
e.state_() == KeyState::up: 0       
Unknown key event: 261
_____
key: 0x9ff7c0
name: Backspace
state: 10483572
e.key_()->code_(): 8
key.code_(): 165
e.state_() == KeyState::down: 0     
e.state_() == KeyState::up: 0       
_____
key: 0x9ff6a8
name: Alt_R
state: 1 //up
e.key_()->code_(): 165
key.code_(): 165
e.state_() == KeyState::down: 0     
e.state_() == KeyState::up: 1
```