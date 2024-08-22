#pragma once
//#include <string>
#include "impl/Key.h"
//#include "IF/I_Key.h"
#include "common.h"

namespace Keys_h{
	using namespace _;
	using Kt = an<Key>;
	//using Kt = Key&;
	inline Kt KEY(string name, i32 code){
		return New<Key>(name, code);
	}

}

namespace _ {

using namespace Keys_h;
class Keys {

protected:
	Keys(){};
public:
	~Keys(){};
	static Keys& inst(){
		static Keys keys;
		return keys;
	}

	Kt A = KEY("A", 65);
	Kt B = KEY("B", 66);
	Kt C = KEY("C", 67);
	Kt D = KEY("D", 68);
	Kt E = KEY("E", 69);
	Kt F = KEY("F", 70);
	Kt G = KEY("G", 71);
	Kt H = KEY("H", 72);
	Kt I = KEY("I", 73);
	Kt J = KEY("J", 74);
	Kt K = KEY("K", 75);
	Kt L = KEY("L", 76);
	Kt M = KEY("M", 77);
	Kt N = KEY("N", 78);
	Kt O = KEY("O", 79);
	Kt P = KEY("P", 80);
	Kt Q = KEY("Q", 81);
	Kt R = KEY("R", 82);
	Kt S = KEY("S", 83);
	Kt T = KEY("T", 84);
	Kt U = KEY("U", 85);
	Kt V = KEY("V", 86);
	Kt W = KEY("W", 87);
	Kt X = KEY("X", 88);
	Kt Y = KEY("Y", 89);
	Kt Z = KEY("Z", 90);
	Kt _0 = KEY("0", 48);
	Kt _1 = KEY("1", 49);
	Kt _2 = KEY("2", 50);
	Kt _3 = KEY("3", 51);
	Kt _4 = KEY("4", 52);
	Kt _5 = KEY("5", 53);
	Kt _6 = KEY("6", 54);
	Kt _7 = KEY("7", 55);
	Kt _8 = KEY("8", 56);
	Kt _9 = KEY("9", 57);
	Kt F1 = KEY("F1", 112);
	Kt F2 = KEY("F2", 113);
	Kt F3 = KEY("F3", 114);
	Kt F4 = KEY("F4", 115);
	Kt F5 = KEY("F5", 116);
	Kt F6 = KEY("F6", 117);
	Kt F7 = KEY("F7", 118);
	Kt F8 = KEY("F8", 119);
	Kt F9 = KEY("F9", 120);
	Kt F10 = KEY("F10", 121);
	Kt F11 = KEY("F11", 122);
	Kt F12 = KEY("F12", 123);
	Kt Backspace = KEY("Backspace", 8);
	Kt Tab = KEY("Tab", 9);
	Kt Enter = KEY("Enter", 13);
	Kt Shift_L = KEY("Shift_L", 160);
	Kt Shift_R = KEY("Shift_R", 161);
	Kt Ctrl_L = KEY("Ctrl_L", 162);
	Kt Ctrl_R = KEY("Ctrl_R", 163);
	Kt Alt_L = KEY("Alt_L", 164);
	Kt Alt_R = KEY("Alt_R", 165);
	Kt Meta_L = KEY("Meta_L", 91);
	Kt Pause = KEY("Pause", 19);
	Kt CapsLock = KEY("CapsLock", 20);
	Kt Esc = KEY("Esc", 27);
	Kt Space = KEY("Space", 32);
	Kt PageUp = KEY("PageUp", 33);
	Kt PageDown = KEY("PageDown", 34);
	Kt End = KEY("End", 35);
	Kt Home = KEY("Home", 36);
	Kt Left = KEY("Left", 37);
	Kt Up = KEY("Up", 38);
	Kt Right = KEY("Right", 39);
	Kt Down = KEY("Down", 40);
	Kt Insert = KEY("Insert", 45);
	Kt Delete = KEY("Delete", 46);
	Kt NumLock = KEY("NumLock", 144);
	Kt Numpad0 = KEY("Numpad0", 96);
	Kt Numpad1 = KEY("Numpad1", 97);
	Kt Numpad2 = KEY("Numpad2", 98);
	Kt Numpad3 = KEY("Numpad3", 99);
	Kt Numpad4 = KEY("Numpad4", 100);
	Kt Numpad5 = KEY("Numpad5", 101);
	Kt Numpad6 = KEY("Numpad6", 102);
	Kt Numpad7 = KEY("Numpad7", 103);
	Kt Numpad8 = KEY("Numpad8", 104);
	Kt Numpad9 = KEY("Numpad9", 105);
	Kt NumpadMultiply = KEY("NumpadMultiply", 106);
	Kt NumpadAdd = KEY("NumpadAdd", 107);
	Kt NumpadSubtract = KEY("NumpadSubtract", 109);
	Kt NumpadDecimal = KEY("NumpadDecimal", 110);
	Kt NumpadDivide = KEY("NumpadDivide", 111);
	Kt Semicolon = KEY("Semicolon", 186);
	Kt Equal = KEY("Equal", 187);
	Kt Comma = KEY("Comma", 188);
	Kt Minus = KEY("Minus", 189);
	Kt Period = KEY("Period", 190);
	Kt Slash = KEY("Slash", 191);
	Kt Backquote = KEY("Backquote", 192);
	Kt BracketLeft = KEY("BracketLeft", 219);
	Kt Backslash = KEY("Backslash", 220);
	Kt BracketRight = KEY("BracketRight", 221);
	Kt Quote = KEY("Quote", 222);
};

}//~namespace _
