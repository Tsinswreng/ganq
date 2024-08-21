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