import type { I_Coord2d } from "@shared/interfaces/I_Coord2d";
import type { I_Mouse } from "@shared/interfaces/I_Mouse";
import type { Deferrable } from "@shared/Type";
//
import { MouseClick } from "@shared/enum/MouseClick";
import { Coord2d } from "@shared/impl/Coord2d";
import { Direct2d } from "@shared/enum/Direct2d";
import rb from 'robotjs';

export class Mouse implements I_Mouse {
	constructor(){}
	protected __init__(...args: Parameters<typeof Mouse.new>){
		const z = this
		return z
	}

	static new(){
		const z = new this()
		z.__init__()
		return z
	}

	_rb = rb
	get rb(){return this._rb}
	set rb(v){this._rb = v}
	

	async MoveTo(c: I_Coord2d) {
		const z = this
		z.rb.moveMouse(c.x, c.y)
	}
	async CurPos(){
		const z = this
		const pos = z.rb.getMousePos()
		return Coord2d.new(pos.x, pos.y)
	}

	async Move(direct: Direct2d, distance: number) {
		const z = this
		switch (direct) {
			case Direct2d.down:
				z.rb.moveMouse(z.rb.getMousePos().x, z.rb.getMousePos().y + distance)
				break
			case Direct2d.left:
				z.rb.moveMouse(z.rb.getMousePos().x - distance, z.rb.getMousePos().y)
				break
			case Direct2d.right:
				z.rb.moveMouse(z.rb.getMousePos().x + distance, z.rb.getMousePos().y)
				break
			case Direct2d.up:
				z.rb.moveMouse(z.rb.getMousePos().x, z.rb.getMousePos().y - distance)
				break
			default:
				throw new Error("Invalid direction.")
		}
	}
	async Click(key?: MouseClick) {
		const z = this
		if(key == void 0){
			return z.rb.mouseClick()
		}
		if (true) {
			switch (key) {
				case MouseClick.left:
					z.rb.mouseClick('left')
					break
				case MouseClick.middle:
					z.rb.mouseClick('middle')
					break
				case MouseClick.right:
					z.rb.mouseClick('right')
					break
				default:
					throw new Error("Invalid key.")
			}
		}
	}
	
}

export const mouse = Mouse.new()