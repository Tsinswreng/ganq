import type { KeyState } from "@shared/enum/KeyState"
import { I_Key } from "./I_Key"

export interface I_KeyEvent {
	key: I_Key
	state: KeyState
}