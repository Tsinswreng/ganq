// #include <iostream>
// #include "tools/CyclicArray/CyclicArray.h" // 确保包含你的 CyclicArray 头文件

// int main() {
//     try {
//         // 创建一个容量为5的循环数组
//         CyclicArray<int> cyclicArray(5);

//         // 测试添加元素
//         std::cout << "Adding elements to the cyclic array:" << std::endl;
//         for (int i = 0; i < 5; ++i) {
//             cyclicArray.addBack(i);
//             std::cout << "Added: " << i << ", Size: " << cyclicArray.size_() << std::endl;
//         }

//         // 尝试添加一个超出容量的元素
//         std::cout << "Trying to add element 5 (should fail): " << cyclicArray.addBack(5) << std::endl;

//         // 打印当前元素
//         std::cout << "Current elements in the cyclic array: ";
//         for (int i = 0; i < cyclicArray.size_(); ++i) {
//             std::cout << cyclicArray.frontGet(i) << " ";
//         }
//         std::cout << std::endl;

//         // 测试删除元素
//         std::cout << "Removing elements from the front:" << std::endl;
//         while (!cyclicArray.isEmpty()) {
//             auto removed = cyclicArray.rmFront();
//             if (removed) {
//                 std::cout << "Removed: " << *removed << ", Size: " << cyclicArray.size_() << std::endl;
//             }
//         }

//         // 测试清空数组
//         cyclicArray.clear();
//         std::cout << "Cleared the array, Size: " << cyclicArray.size_() << std::endl;

//         // 测试添加到前面
//         std::cout << "Adding elements to the front:" << std::endl;
//         for (int i = 0; i < 5; ++i) {
//             cyclicArray.addFront(i);
//             std::cout << "Added: " << i << ", Size: " << cyclicArray.size_() << std::endl;
//         }

//         // 打印当前元素
//         std::cout << "Current elements in the cyclic array: ";
//         for (int i = 0; i < cyclicArray.size_(); ++i) {
//             std::cout << cyclicArray.frontGet(i) << " ";
//         }
//         std::cout << std::endl;

//     } catch (const std::exception& e) {
//         std::cerr << "Exception: " << e.what() << std::endl;
//     }

//     return 0;
// }
