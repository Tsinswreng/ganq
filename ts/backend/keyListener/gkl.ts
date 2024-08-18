import { GlobalKeyboardListener } from "node-global-key-listener";const gkl = new GlobalKeyboardListener();

gkl.addListener((event) => {
	console.log(event);
});


