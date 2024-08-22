#pragma once

#ifndef KEY_MAPPING_H
#define KEY_MAPPING_H

#include "common.h"
#include <unordered_map>
#include "./Keys.h" // 确保包含 Keys 类的定义

namespace _ {

namespace {
	using KMap = UMap<i32, an<Key>>;
	inline an<Key> KEY(an<Key> key){
		return key;
	}

} //namespace



class Code__Key {
public:
	~Code__Key() {}
	KMap map_(){return _map;}
	static Code__Key& inst(){
		static Code__Key keys;
		return keys;
	}
protected:
	Code__Key(){
		_map = createM();
	}

	KMap _map;
	KMap createM() {
		//UMap<int, Kt> M;
		auto K = Keys::inst();
		auto M = _map;
		// 将 keycode 和 Keys 的成员进行映射
		M[65] = KEY(K.A);
		M[66] = KEY(K.B);
		M[67] = KEY(K.C);
		M[68] = KEY(K.D);
		M[69] = KEY(K.E);
		M[70] = KEY(K.F);
		M[71] = KEY(K.G);
		M[72] = KEY(K.H);
		M[73] = KEY(K.I);
		M[74] = KEY(K.J);
		M[75] = KEY(K.K);
		M[76] = KEY(K.L);
		M[77] = KEY(K.M);
		M[78] = KEY(K.N);
		M[79] = KEY(K.O);
		M[80] = KEY(K.P);
		M[81] = KEY(K.Q);
		M[82] = KEY(K.R);
		M[83] = KEY(K.S);
		M[84] = KEY(K.T);
		M[85] = KEY(K.U);
		M[86] = KEY(K.V);
		M[87] = KEY(K.W);
		M[88] = KEY(K.X);
		M[89] = KEY(K.Y);
		M[90] = KEY(K.Z);
		M[48] = KEY(K._0);
		M[49] = KEY(K._1);
		M[50] = KEY(K._2);
		M[51] = KEY(K._3);
		M[52] = KEY(K._4);
		M[53] = KEY(K._5);
		M[54] = KEY(K._6);
		M[55] = KEY(K._7);
		M[56] = KEY(K._8);
		M[57] = KEY(K._9);
		M[91] = KEY(K.Meta_L);
		M[112] = KEY(K.F1);
		M[113] = KEY(K.F2);
		M[114] = KEY(K.F3);
		M[115] = KEY(K.F4);
		M[116] = KEY(K.F5);
		M[117] = KEY(K.F6);
		M[118] = KEY(K.F7);
		M[119] = KEY(K.F8);
		M[120] = KEY(K.F9);
		M[121] = KEY(K.F10);
		M[122] = KEY(K.F11);
		M[123] = KEY(K.F12);
		M[8] = KEY(K.Backspace);
		M[9] = KEY(K.Tab);
		M[13] = KEY(K.Enter);
		M[160] = KEY(K.Shift_L);
		M[161] = KEY(K.Shift_R);
		M[162] = KEY(K.Ctrl_L);
		M[163] = KEY(K.Ctrl_R);
		M[164] = KEY(K.Alt_L);
		M[165] = KEY(K.Alt_R);
		M[19] = KEY(K.Pause);
		M[20] = KEY(K.CapsLock);
		M[27] = KEY(K.Esc);
		M[32] = KEY(K.Space);
		M[33] = KEY(K.PageUp);
		M[34] = KEY(K.PageDown);
		M[35] = KEY(K.End);
		M[36] = KEY(K.Home);
		M[37] = KEY(K.Left);
		M[38] = KEY(K.Up);
		M[39] = KEY(K.Right);
		M[40] = KEY(K.Down);
		M[45] = KEY(K.Insert);
		M[46] = KEY(K.Delete);
		M[144] = KEY(K.NumLock);
		M[96] = KEY(K.Numpad0);
		M[97] = KEY(K.Numpad1);
		M[98] = KEY(K.Numpad2);
		M[99] = KEY(K.Numpad3);
		M[100] = KEY(K.Numpad4);
		M[101] = KEY(K.Numpad5);
		M[102] = KEY(K.Numpad6);
		M[103] = KEY(K.Numpad7);
		M[104] = KEY(K.Numpad8);
		M[105] = KEY(K.Numpad9);
		M[106] = KEY(K.NumpadMultiply);
		M[107] = KEY(K.NumpadAdd);
		M[109] = KEY(K.NumpadSubtract);
		M[110] = KEY(K.NumpadDecimal);
		M[111] = KEY(K.NumpadDivide);
		M[186] = KEY(K.Semicolon);
		M[187] = KEY(K.Equal);
		M[188] = KEY(K.Comma);
		M[189] = KEY(K.Minus);
		M[190] = KEY(K.Period);
		M[191] = KEY(K.Slash);
		M[192] = KEY(K.Backquote);
		M[219] = KEY(K.BracketLeft);
		M[220] = KEY(K.Backslash);
		M[221] = KEY(K.BracketRight);
		M[222] = KEY(K.Quote);

		return M;
	}
};

}//~namespace _

#endif // KEY_MAPPING_H
