import rb from 'robotjs';
import { GlobalKeyboardListener } from "node-global-key-listener";const gkl = new GlobalKeyboardListener();
const robot = rb;
import { I_handleKey } from '@shared/interfaces/I_handleKey';
import { I_KeyEvent } from '@shared/interfaces/I_KeyEvent';
import CyclicArray from '@shared/tools/CyclicArray';
// gkl.addListener((event) => {
// 	if(event.name === 'J'){
// 		// 定义要移动的长度
// 		const moveLength = 100; // 例如，向左移动 100 像素

// 		// 获取当前鼠标位置
// 		const currentPosition = robot.getMousePos();
// 		console.log(`当前鼠标位置: x=${currentPosition.x}, y=${currentPosition.y}`);

// 		// 计算新的鼠标位置
// 		const newX = currentPosition.x - moveLength;
// 		const newY = currentPosition.y; // y 坐标保持不变

// 		// 移动鼠标到新的位置
// 		robot.moveMouse(newX, newY);
// 		console.log(`移动到新位置: x=${newX}, y=${newY}`);
// 	}
// });

class Status{
	constructor(){}
	protected __init__(...args: Parameters<typeof Status.new>){
		const z = this
		return z
	}

	static new(){
		const z = new this()
		z.__init__()
		return z
	}

	//get This(){return Status}
	history = CyclicArray.new<I_KeyEvent>(16)
}


export class MouseMode implements I_handleKey {
	constructor(){}
	protected __init__(...args: Parameters<typeof MouseMode.new>){
		const z = this
		return z
	}

	static new(){
		const z = new this()
		z.__init__()
		return z
	}

	//get This(){return MouseMode}
	_status = Status.new()
	get status(){return this._status}
	set status(v){this._status = v}

	handleKey(event: I_KeyEvent) {
		const z = this
		z.status.history.addBackF(event)
	}
}



