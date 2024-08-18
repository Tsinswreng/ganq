keyTap('right_alt') actually send left alt instead of right alt

## Expected Behavior
`keyTap('right_alt')` should send right alt

## Current Behavior
`keyTap('right_alt')` sends left alt instead

## Possible Solution


## Steps to Reproduce (for bugs)

I use `node-global-key-listener` to listen to key input.

```
npm install robotjs
npm install node-global-key-listener
```

```js
const rb = require('robotjs');
const { GlobalKeyboardListener } = require("node-global-key-listener");

const gkl = new GlobalKeyboardListener();

gkl.addListener((event) => {
	console.log(event);
});


setInterval(() => {
	try {
		rb.keyTap('right_alt')
	} catch (error) {
		console.log(error)
	}	
}, 1000);

```

it outputs:
```
{
  vKey: 164,
  rawKey: { _nameRaw: 'VK_LMENU', name: 'LALT', standardName: 'LEFT ALT' },
  name: 'LEFT ALT',
  state: 'DOWN',
  scanCode: 56,
  location: [ 0, 0 ],
  _raw: 'KEYBOARD,DOWN,164,56,0,0,15\r\nKEYBOARD,UP,164,56,0,0,16\r\n'
}
{
  vKey: 164,
  rawKey: { _nameRaw: 'VK_LMENU', name: 'LALT', standardName: 'LEFT ALT' },
  name: 'LEFT ALT',
  state: 'UP',
  scanCode: 56,
  location: [ 0, 0 ],
  _raw: 'KEYBOARD,DOWN,164,56,0,0,15\r\nKEYBOARD,UP,164,56,0,0,16\r\n'
}
```

As can be seen from above, `name` is `'LEFT ALT'` instead of `'RIGHT ALT'`

If I press right alt key on my keyboard manually, it will show

```
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
```

As can be seen from above, `name` is `'RIGHT ALT'` . This matchs  expectations so it should not be the bug of `node-global-key-listener`.

Then it should be `robotjs` that sends the wrong alt.

## Context

The reason I want this bug to be fixed is that I want to set right alt for different usage from left alt. So I need to distinguish the two `alt`

## Your Environment
* RobotJS version: 0.6.0
* Node.js version: 18.15.0
* npm version: 9.6.6
* Operating System: Windows 10
