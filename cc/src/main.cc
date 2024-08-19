#include <iostream>
#include "common.h"
#include "impl/Mouse.h"
#include <thread>
#include "enum/Direct2d.h"
#include <chrono>

namespace ngaq{
i32 _(){
	auto mouse = Mouse();
	mouse.moveTo(500, 300);
	for(int i = 0; i < 100; i++){
		mouse.move(Direct2d::left, 20);
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
	}
	
	return 0;
}
}//~namespace ngaq


int main(){
	return ngaq::_();
}

//#include <windows.h>
// int main(){
//     // 設定目標坐標
//     int x = 500; // X 坐標
//     int y = 300; // Y 坐標

//     // 移動鼠標指針
//     if (SetCursorPos(x, y)) {
//         std::cout << "Mouse moved to (" << x << ", " << y << ")." << std::endl;
//     } else {
//         std::cerr << "Failed to move mouse." << std::endl;
//     }

//     return 0;
// 	std::cout << "Hello, world!" << std::endl;
// 	return 0;
// }