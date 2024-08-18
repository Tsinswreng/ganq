//iohook: node-key-sender
import rb from 'robotjs';
// rb.moveMouse(500,500)
// rb.mouseClick(); // 左鍵點擊
// const robot = rb
setInterval(() => {
	try {
		//rb.keyTap('backspace') // powertoy改映射後潙右alt
		rb.keyTap('right_alt')
	} catch (error) {
		console.log(error)
	}	
}, 1000);

/* 
{
  vKey: 164,
  rawKey: { _nameRaw: 'VK_LMENU', name: 'LALT', standardName: 'LEFT ALT' },
  name: 'LEFT ALT',
  state: 'DOWN',
  scanCode: 56,
  location: [ 0, 0 ],
  _raw: 'KEYBOARD,DOWN,164,56,0,0,6800\r\n'
}
{
  vKey: 164,
  rawKey: { _nameRaw: 'VK_LMENU', name: 'LALT', standardName: 'LEFT ALT' },
  name: 'LEFT ALT',
  state: 'UP',
  scanCode: 56,
  location: [ 0, 0 ],
  _raw: 'KEYBOARD,UP,164,56,0,0,6801\r\n'
}
*/


/* 

{
  vKey: 165,
  rawKey: { _nameRaw: 'VK_RMENU', name: 'RALT', standardName: 'RIGHT ALT' },
  name: 'RIGHT ALT',
  state: 'DOWN',
  scanCode: 56,
  location: [ 0, 0 ],
  _raw: 'KEYBOARD,DOWN,165,56,0,0,8084\r\n'
}
{
  vKey: 165,
  rawKey: { _nameRaw: 'VK_RMENU', name: 'RALT', standardName: 'RIGHT ALT' },
  name: 'RIGHT ALT',
  state: 'UP',
  scanCode: 56,
  location: [ 0, 0 ],
  _raw: 'KEYBOARD,UP,165,56,0,0,8085\r\n'
}
*/

