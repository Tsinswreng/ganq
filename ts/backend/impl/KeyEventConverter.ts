import type { I_convertKeyEvent } from "@shared/interfaces/I_convertKeyEvent"
import type { I_KeyEvent } from "@shared/interfaces/I_KeyEvent"
import type { IGlobalKeyEvent } from "node-global-key-listener"
import { KeyState } from "@shared/enum/KeyState"
import { Key } from "@shared/impl/Key"
import { keys } from "@shared/impl/Keys"
import { KeyEvent } from "@shared/impl/KeyEvent"
class KeyEventConverter implements I_convertKeyEvent<IGlobalKeyEvent> {
	constructor(){}
	protected __init__(...args: Parameters<typeof KeyEventConverter.new>){
		const z = this
		return z
	}

	static new(){
		const z = new this()
		z.__init__()
		return z
	}

	_convert_state(state: IGlobalKeyEvent["state"]){
		switch(state){
			case "DOWN":
				return KeyState.down
			case "UP":
				return KeyState.up
		}
	}

	_convert_key(event: IGlobalKeyEvent): Key|undef {
		const z = this
		switch(event.name){
			case "A": return keys.A;break
			case "B": return keys.B;break
			case "C": return keys.C;break
			case "D": return keys.D;break
			case "E": return keys.E;break
			case "F": return keys.F;break
			case "G": return keys.G;break
			case "H": return keys.H;break
			case "I": return keys.I;break
			case "J": return keys.J;break
			case "K": return keys.K;break
			case "L": return keys.L;break
			case "M": return keys.M;break
			case "N": return keys.N;break
			case "O": return keys.O;break
			case "P": return keys.P;break
			case "Q": return keys.Q;break
			case "R": return keys.R;break
			case "S": return keys.S;break
			case "T": return keys.T;break
			case "U": return keys.U;break
			case "V": return keys.V;break
			case "W": return keys.W;break
			case "X": return keys.X;break
			case "Y": return keys.Y;break
			case "Z": return keys.Z;break
			case "0": return keys._0;break
			case "1": return keys._1;break
			case "2": return keys._2;break
			case "3": return keys._3;break
			case "4": return keys._4;break
			case "5": return keys._5;break
			case "6": return keys._6;break
			case "7": return keys._7;break
			case "8": return keys._8;break
			case "9": return keys._9;break
			case "F1": return keys.F1;break
			case "F2": return keys.F2;break
			case "F3": return keys.F3;break
			case "F4": return keys.F4;break
			//...
			case "LEFT CTRL": return keys.Ctrl_L;break
			case "RIGHT CTRL": return keys.Ctrl_R;break
			case "LEFT SHIFT": return keys.Shift_L;break
			case "RIGHT SHIFT": return keys.Shift_R;break
			case "LEFT ALT": return keys.Alt_L;break
			case "RIGHT ALT": return keys.Alt_R;break
			case "SPACE": return keys.Space;break
			//... TODO
		}
	}

	//get This(){return KeyEventConverter}
	convertKeyEvent(event: IGlobalKeyEvent): I_KeyEvent|undef {
		const z = this
		const state:KeyState = z._convert_state(event.state)
		const key:Key|undef = z._convert_key(event)
		if(key == void 0 || event == void 0){
			return void 0
		}
		return KeyEvent.new(key, state)
	}
}

export const keyEventConverter = KeyEventConverter.new()