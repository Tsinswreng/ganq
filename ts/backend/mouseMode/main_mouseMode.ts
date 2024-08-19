import rb from 'robotjs';
import { GlobalKeyboardListener } from "node-global-key-listener";
import { keyEventConverter } from '@backend/impl/KeyEventConverter';
import { MouseMode } from './mouseMode';
const gkl = new GlobalKeyboardListener();
const robot = rb;
const mouseMode = MouseMode.new();


export async function Main_mouseMode(){
	gkl.addListener(event => {
		try {
			const keyEvent = keyEventConverter.convertKeyEvent(event);
			if(keyEvent == void 0){
				console.warn("unknown key event:", event);
				return;
			}
			mouseMode.handleKey(keyEvent);
		} catch (err) {
			console.error(err)
		}
	})
}
