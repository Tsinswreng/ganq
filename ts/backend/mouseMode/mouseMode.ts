import type { I_handleKey } from '@shared/interfaces/I_handleKey';
import type { I_KeyEvent } from '@shared/interfaces/I_KeyEvent';
import type { I_Mouse } from '@shared/interfaces/I_Mouse';
import CyclicArray from '@shared/tools/CyclicArray';
import { Mouse } from '@backend/impl/Mouse';
import { mouse } from '@backend/impl/Mouse';
import { keys } from '@shared/impl/Keys';
import { Direct2d } from '@shared/enum/Direct2d';

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
	shiftDown = false
	ctrlDown = false
	altDown = false
	metaDown = false
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

	_mouse:I_Mouse = mouse
	get mouse(){return this._mouse}
	set mouse(v){this._mouse = v}
	

	//get This(){return MouseMode}
	_status = Status.new()
	get status(){return this._status}
	set status(v){this._status = v}

	handleKey(event: I_KeyEvent) {
		const z = this
		z.status.history.addBackF(event)
		if(event.key === keys.J){
			z.mouse.Move(Direct2d.left, 100)
		}
	}
}
