import type { I_KeyEvent } from "@shared/interfaces/I_KeyEvent"
import { KeyState } from "@shared/enum/KeyState"
import { Key } from "./Key"
export class KeyEvent implements I_KeyEvent {
	constructor(){}
	protected __init__(...args: Parameters<typeof KeyEvent.new>){
		const z = this
		z.key = args[0]
		z.state = args[1]
		return z
	}

	static new(key:Key, state:KeyState){
		const z = new this()
		z.__init__(key, state)
		return z
	}

	key: Key
	state: KeyState
}


