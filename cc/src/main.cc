#include "entryPoints/main_mouseMode.h"
//#include "entryPoints/main_test.h"
#include "common.h"
int main(){
	_::main_mouseMode();
	return 0;
}


// #include <windows.h>
// #include <iostream>

// int main() {
//     // 设置鼠标移动的速度
//     const int moveDistance = 5; // 每次移动的像素数
//     bool isMoving = false; // 是否正在移动鼠标

//     // 主循环
//     while (true) {
//         // 检查 J 键的状态
//         if (GetAsyncKeyState('J') & 0x8000) {
//             if (!isMoving) {
//                 isMoving = true; // 开始移动
//             }
//             // 移动鼠标
//             POINT p;
//             GetCursorPos(&p); // 获取当前鼠标位置
//             SetCursorPos(p.x + moveDistance, p.y); // 向右移动
//         } else {
//             isMoving = false; // 停止移动
//         }

//         // 休眠以减少 CPU 使用率
//         Sleep(10);
//     }

//     return 0;
// }
