import rb from 'robotjs';
import { GlobalKeyboardListener } from "node-global-key-listener";

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
