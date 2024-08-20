#pragma once

#ifndef KEY_MAPPING_H
#define KEY_MAPPING_H

#include "common.h"
#include <unordered_map>
#include "./Keys.h" // 确保包含 Keys 类的定义

namespace ngaq {

class Code__Key {
public:
	~Code__Key() {}
	UMap<i32, Kt> map_(){return _map;}
	static Code__Key& inst(){
		static Code__Key keys;
		return keys;
	}
protected:
	Code__Key(){
		_map = createM();
	}

	UMap<i32, Kt> _map;
	UMap<int, Kt> createM() {
		//UMap<int, Kt> M;
		auto K = Keys::inst();
		auto M = _map;
		// 将 keycode 和 Keys 的成员进行映射
		M[65] = K.A;
		M[66] = K.B;
		M[67] = K.C;
		M[68] = K.D;
		M[69] = K.E;
		M[70] = K.F;
		M[71] = K.G;
		M[72] = K.H;
		M[73] = K.I;
		M[74] = K.J;
		M[75] = K.K;
		M[76] = K.L;
		M[77] = K.M;
		M[78] = K.N;
		M[79] = K.O;
		M[80] = K.P;
		M[81] = K.Q;
		M[82] = K.R;
		M[83] = K.S;
		M[84] = K.T;
		M[85] = K.U;
		M[86] = K.V;
		M[87] = K.W;
		M[88] = K.X;
		M[89] = K.Y;
		M[90] = K.Z;
		M[48] = K._0;
		M[49] = K._1;
		M[50] = K._2;
		M[51] = K._3;
		M[52] = K._4;
		M[53] = K._5;
		M[54] = K._6;
		M[55] = K._7;
		M[56] = K._8;
		M[57] = K._9;
		M[112] = K.F1;
		M[113] = K.F2;
		M[114] = K.F3;
		M[115] = K.F4;
		M[116] = K.F5;
		M[117] = K.F6;
		M[118] = K.F7;
		M[119] = K.F8;
		M[120] = K.F9;
		M[121] = K.F10;
		M[122] = K.F11;
		M[123] = K.F12;
		M[8] = K.Backspace;
		M[9] = K.Tab;
		M[13] = K.Enter;
		M[160] = K.Shift_L;
		M[161] = K.Shift_R;
		M[162] = K.Ctrl_L;
		M[163] = K.Ctrl_R;
		M[164] = K.Alt_L;
		M[165] = K.Alt_R;
		M[19] = K.Pause;
		M[20] = K.CapsLock;
		M[27] = K.Esc;
		M[32] = K.Space;
		M[33] = K.PageUp;
		M[34] = K.PageDown;
		M[35] = K.End;
		M[36] = K.Home;
		M[37] = K.Left;
		M[38] = K.Up;
		M[39] = K.Right;
		M[40] = K.Down;
		M[45] = K.Insert;
		M[46] = K.Delete;
		M[144] = K.NumLock;
		M[96] = K.Numpad0;
		M[97] = K.Numpad1;
		M[98] = K.Numpad2;
		M[99] = K.Numpad3;
		M[100] = K.Numpad4;
		M[101] = K.Numpad5;
		M[102] = K.Numpad6;
		M[103] = K.Numpad7;
		M[104] = K.Numpad8;
		M[105] = K.Numpad9;
		M[106] = K.NumpadMultiply;
		M[107] = K.NumpadAdd;
		M[109] = K.NumpadSubtract;
		M[110] = K.NumpadDecimal;
		M[111] = K.NumpadDivide;
		M[186] = K.Semicolon;
		M[187] = K.Equal;
		M[188] = K.Comma;
		M[189] = K.Minus;
		M[190] = K.Period;
		M[191] = K.Slash;
		M[192] = K.Backquote;
		M[219] = K.BracketLeft;
		M[220] = K.Backslash;
		M[221] = K.BracketRight;
		M[222] = K.Quote;

		return M;
	}
};

}//~namespace ngaq

#endif // KEY_MAPPING_H
