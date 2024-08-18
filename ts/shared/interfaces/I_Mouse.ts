import type { Deferrable } from "@shared/Type";
import type { I_Coord2d } from "./I_Coord2d";
import type { Direct2d } from "@shared/enum/Direct2d";
import type { MouseClick } from "@shared/enum/MouseClick";

export interface I_Mouse {
	MoveTo(c:I_Coord2d):Deferrable<any>
	CurPos(): Deferrable<I_Coord2d>
	Move(direct:Direct2d, distance:number):Deferrable<any>
	/** default is left */
	Click(key?:MouseClick):Deferrable<any>

}