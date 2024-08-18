import { I_Key } from "@shared/interfaces/I_Key"
export class Key implements I_Key {
	constructor(){}
	protected __init__(...args: Parameters<typeof Key.new>){
		const z = this
		z.name = args[0]
		z.code = args[1]
		return z
	}

	static new(name:str, code:int){
		const z = new this()
		z.__init__(name, code)
		return z
	}

	//get This(){return Key}
	name: string
	code: number
}
