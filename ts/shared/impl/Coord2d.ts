import { I_Coord2d } from '@shared/interfaces/I_Coord2d';

export class Coord2d implements I_Coord2d<number> {
	x: number;
	y: number;
	constructor(){}
	protected __init__(...args: Parameters<typeof Coord2d.new>){
		const z = this
		z.x = args[0]
		z.y = args[1]
		return z
	}

	static new(x:number, y:number){
		const z = new this()
		z.__init__(x, y)
		return z
	}

	//get This(){return Coord2d}
	static add(c1: I_Coord2d, c2: I_Coord2d){
		return Coord2d.new(c1.x + c2.x, c1.y + c2.y)
	}

	add(c:I_Coord2d){
		return Coord2d.add(this, c)
	}

}

