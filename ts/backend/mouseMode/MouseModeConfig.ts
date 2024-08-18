import { Config } from "@backend/util/Config"
export class MouseModeConfig extends Config {
	constructor(){super()}
	protected __init__(...args: Parameters<typeof MouseModeConfig.new>){
		const z = this
		return z
	}

	static new(){
		const z = new this()
		z.__init__()
		return z
	}

	//get This(){return MouseModeConfig}
	override config = new DefaultConfog
}

class DefaultConfog{
	mouseMode = new MouseMode()
}

class MouseMode{
	
}
