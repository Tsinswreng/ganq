import pyautogui
import time

# 等待几秒钟，以便你可以切换到目标窗口
time.sleep(5)

# 按下右 Alt 键
pyautogui.keyDown('altright')

# 释放右 Alt 键
pyautogui.keyUp('altright')
