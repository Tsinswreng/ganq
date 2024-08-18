import rb from 'robotjs';
import { GlobalKeyboardListener } from "node-global-key-listener";const gkl = new GlobalKeyboardListener();
const robot = rb;
gkl.addListener((event) => {
	if(event.name === 'J'){
		// 定义要移动的长度
		const moveLength = 100; // 例如，向左移动 100 像素

		// 获取当前鼠标位置
		const currentPosition = robot.getMousePos();
		console.log(`当前鼠标位置: x=${currentPosition.x}, y=${currentPosition.y}`);

		// 计算新的鼠标位置
		const newX = currentPosition.x - moveLength;
		const newY = currentPosition.y; // y 坐标保持不变

		// 移动鼠标到新的位置
		robot.moveMouse(newX, newY);
		console.log(`移动到新位置: x=${newX}, y=${newY}`);
	}
});
