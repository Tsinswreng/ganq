//#include <string>
#include "impl/Key.h"
#include "IF/I_Key.h"
#include "common.h"
using namespace std;

namespace ngaq {

namespace{
	using Kt = an<I_Key>;
}


class Keys {

protected:
	Keys(){};
public:
	~Keys(){};
	static Keys& inst(){
		static Keys keys;
		return keys;
	}

	Kt A = New<Key>("A", 65);
	Kt B = New<Key>("B", 66);
	Kt C = New<Key>("C", 67);
	Kt D = New<Key>("D", 68);
	Kt E = New<Key>("E", 69);
	Kt F = New<Key>("F", 70);
	Kt G = New<Key>("G", 71);
	Kt H = New<Key>("H", 72);
	Kt I = New<Key>("I", 73);
	Kt J = New<Key>("J", 74);
	Kt K = New<Key>("K", 75);
	Kt L = New<Key>("L", 76);
	Kt M = New<Key>("M", 77);
	Kt N = New<Key>("N", 78);
	Kt O = New<Key>("O", 79);
	Kt P = New<Key>("P", 80);
	Kt Q = New<Key>("Q", 81);
	Kt R = New<Key>("R", 82);
	Kt S = New<Key>("S", 83);
	Kt T = New<Key>("T", 84);
	Kt U = New<Key>("U", 85);
	Kt V = New<Key>("V", 86);
	Kt W = New<Key>("W", 87);
	Kt X = New<Key>("X", 88);
	Kt Y = New<Key>("Y", 89);
	Kt Z = New<Key>("Z", 90);
	Kt _0 = New<Key>("0", 48);
	Kt _1 = New<Key>("1", 49);
	Kt _2 = New<Key>("2", 50);
	Kt _3 = New<Key>("3", 51);
	Kt _4 = New<Key>("4", 52);
	Kt _5 = New<Key>("5", 53);
	Kt _6 = New<Key>("6", 54);
	Kt _7 = New<Key>("7", 55);
	Kt _8 = New<Key>("8", 56);
	Kt _9 = New<Key>("9", 57);
	Kt F1 = New<Key>("F1", 112);
	Kt F2 = New<Key>("F2", 113);
	Kt F3 = New<Key>("F3", 114);
	Kt F4 = New<Key>("F4", 115);
	Kt F5 = New<Key>("F5", 116);
	Kt F6 = New<Key>("F6", 117);
	Kt F7 = New<Key>("F7", 118);
	Kt F8 = New<Key>("F8", 119);
	Kt F9 = New<Key>("F9", 120);
	Kt F10 = New<Key>("F10", 121);
	Kt F11 = New<Key>("F11", 122);
	Kt F12 = New<Key>("F12", 123);
	Kt Backspace = New<Key>("Backspace", 8);
	Kt Tab = New<Key>("Tab", 9);
	Kt Enter = New<Key>("Enter", 13);
	Kt Shift_L = New<Key>("Shift_L", 160);
	Kt Shift_R = New<Key>("Shift_R", 161);
	Kt Ctrl_L = New<Key>("Ctrl_L", 162);
	Kt Ctrl_R = New<Key>("Ctrl_R", 163);
	Kt Alt_L = New<Key>("Alt_L", 164);
	Kt Alt_R = New<Key>("Alt_R", 165);
	Kt Pause = New<Key>("Pause", 19);
	Kt CapsLock = New<Key>("CapsLock", 20);
	Kt Esc = New<Key>("Esc", 27);
	Kt Space = New<Key>("Space", 32);
	Kt PageUp = New<Key>("PageUp", 33);
	Kt PageDown = New<Key>("PageDown", 34);
	Kt End = New<Key>("End", 35);
	Kt Home = New<Key>("Home", 36);
	Kt Left = New<Key>("Left", 37);
	Kt Up = New<Key>("Up", 38);
	Kt Right = New<Key>("Right", 39);
	Kt Down = New<Key>("Down", 40);
	Kt Insert = New<Key>("Insert", 45);
	Kt Delete = New<Key>("Delete", 46);
	Kt NumLock = New<Key>("NumLock", 144);
	Kt Numpad0 = New<Key>("Numpad0", 96);
	Kt Numpad1 = New<Key>("Numpad1", 97);
	Kt Numpad2 = New<Key>("Numpad2", 98);
	Kt Numpad3 = New<Key>("Numpad3", 99);
	Kt Numpad4 = New<Key>("Numpad4", 100);
	Kt Numpad5 = New<Key>("Numpad5", 101);
	Kt Numpad6 = New<Key>("Numpad6", 102);
	Kt Numpad7 = New<Key>("Numpad7", 103);
	Kt Numpad8 = New<Key>("Numpad8", 104);
	Kt Numpad9 = New<Key>("Numpad9", 105);
	Kt NumpadMultiply = New<Key>("NumpadMultiply", 106);
	Kt NumpadAdd = New<Key>("NumpadAdd", 107);
	Kt NumpadSubtract = New<Key>("NumpadSubtract", 109);
	Kt NumpadDecimal = New<Key>("NumpadDecimal", 110);
	Kt NumpadDivide = New<Key>("NumpadDivide", 111);
	Kt Semicolon = New<Key>("Semicolon", 186);
	Kt Equal = New<Key>("Equal", 187);
	Kt Comma = New<Key>("Comma", 188);
	Kt Minus = New<Key>("Minus", 189);
	Kt Period = New<Key>("Period", 190);
	Kt Slash = New<Key>("Slash", 191);
	Kt Backquote = New<Key>("Backquote", 192);
	Kt BracketLeft = New<Key>("BracketLeft", 219);
	Kt Backslash = New<Key>("Backslash", 220);
	Kt BracketRight = New<Key>("BracketRight", 221);
	Kt Quote = New<Key>("Quote", 222);
};

}//~namespace ngaq
