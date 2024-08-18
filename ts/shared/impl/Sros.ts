import type { I_Sros } from "@shared/interfaces/I_Sros";

type Num_t = number
class Sros_num implements I_Sros<Num_t> {
	constructor(){}
	protected __init__(...args: Parameters<typeof Sros_num.new>){
		const z = this
		return z
	}

	static new(){
		const z = new this()
		z.__init__()
		return z
	}

	//get This(){return Sros_num}
	a(x: number, ...y: number[]): number {
		return y.reduce((acc, val) => acc + val, x);
	}
	s(x: number, y: number): number {
		return x - y;
	}
	m(x: number, ...y: number[]): number {
		return y.reduce((acc, val) => acc * val, x);
	}
	d(x: number, y: number): number {
		if (y === 0) {
			throw new Error("Cannot divide by zero");
		}
		return x / y;
	}
	p(x: number, y: number): number {
		return Math.pow(x, y);
	}
}

export const sros_num = Sros_num.new()