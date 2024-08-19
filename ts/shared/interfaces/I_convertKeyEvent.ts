import { I_KeyEvent } from "./I_KeyEvent";

export interface I_convertKeyEvent<Orig> {
	convertKeyEvent(event: Orig): I_KeyEvent|undef
}