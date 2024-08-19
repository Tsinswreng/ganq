//#include <string>
#include "impl/Key.h"
#include "IF/I_Key.h"
#include "common.h"
using namespace std;

namespace ngaq {

namespace{
	using Kt = the<I_Key>;
}


class Keys {

protected:
	Keys(){};
	~Keys(){};
public:

	static Keys& inst(){
		static Keys keys;
		return keys;
	}

	Kt A = mkuq<Key>("A", 65);
	Kt B = mkuq<Key>("B", 66);
	Kt C = mkuq<Key>("C", 67);
	Kt D = mkuq<Key>("D", 68);
	Kt E = mkuq<Key>("E", 69);
	Kt F = mkuq<Key>("F", 70);
	Kt G = mkuq<Key>("G", 71);
	Kt H = mkuq<Key>("H", 72);
	Kt I = mkuq<Key>("I", 73);
	Kt J = mkuq<Key>("J", 74);
	Kt K = mkuq<Key>("K", 75);
	Kt L = mkuq<Key>("L", 76);
	Kt M = mkuq<Key>("M", 77);
	Kt N = mkuq<Key>("N", 78);
	Kt O = mkuq<Key>("O", 79);
	Kt P = mkuq<Key>("P", 80);
	Kt Q = mkuq<Key>("Q", 81);
	Kt R = mkuq<Key>("R", 82);
	Kt S = mkuq<Key>("S", 83);
	Kt T = mkuq<Key>("T", 84);
	Kt U = mkuq<Key>("U", 85);
	Kt V = mkuq<Key>("V", 86);
	Kt W = mkuq<Key>("W", 87);
	Kt X = mkuq<Key>("X", 88);
	Kt Y = mkuq<Key>("Y", 89);
	Kt Z = mkuq<Key>("Z", 90);
	Kt _0 = mkuq<Key>("0", 48);
	Kt _1 = mkuq<Key>("1", 49);
	Kt _2 = mkuq<Key>("2", 50);
	Kt _3 = mkuq<Key>("3", 51);
	Kt _4 = mkuq<Key>("4", 52);
	Kt _5 = mkuq<Key>("5", 53);
	Kt _6 = mkuq<Key>("6", 54);
	Kt _7 = mkuq<Key>("7", 55);
	Kt _8 = mkuq<Key>("8", 56);
	Kt _9 = mkuq<Key>("9", 57);
	Kt F1 = mkuq<Key>("F1", 112);
	Kt F2 = mkuq<Key>("F2", 113);
	Kt F3 = mkuq<Key>("F3", 114);
	Kt F4 = mkuq<Key>("F4", 115);
	Kt F5 = mkuq<Key>("F5", 116);
	Kt F6 = mkuq<Key>("F6", 117);
	Kt F7 = mkuq<Key>("F7", 118);
	Kt F8 = mkuq<Key>("F8", 119);
	Kt F9 = mkuq<Key>("F9", 120);
	Kt F10 = mkuq<Key>("F10", 121);
	Kt F11 = mkuq<Key>("F11", 122);
	Kt F12 = mkuq<Key>("F12", 123);
	Kt Backspace = mkuq<Key>("Backspace", 8);
	Kt Tab = mkuq<Key>("Tab", 9);
	Kt Enter = mkuq<Key>("Enter", 13);
	Kt Shift_L = mkuq<Key>("Shift_L", 160);
	Kt Shift_R = mkuq<Key>("Shift_R", 161);
	Kt Ctrl_L = mkuq<Key>("Ctrl_L", 162);
	Kt Ctrl_R = mkuq<Key>("Ctrl_R", 163);
	Kt Alt_L = mkuq<Key>("Alt_L", 164);
	Kt Alt_R = mkuq<Key>("Alt_R", 165);
	Kt Pause = mkuq<Key>("Pause", 19);
	Kt CapsLock = mkuq<Key>("CapsLock", 20);
	Kt Esc = mkuq<Key>("Esc", 27);
	Kt Space = mkuq<Key>("Space", 32);
	Kt PageUp = mkuq<Key>("PageUp", 33);
	Kt PageDown = mkuq<Key>("PageDown", 34);
	Kt End = mkuq<Key>("End", 35);
	Kt Home = mkuq<Key>("Home", 36);
	Kt Left = mkuq<Key>("Left", 37);
	Kt Up = mkuq<Key>("Up", 38);
	Kt Right = mkuq<Key>("Right", 39);
	Kt Down = mkuq<Key>("Down", 40);
	Kt Insert = mkuq<Key>("Insert", 45);
	Kt Delete = mkuq<Key>("Delete", 46);
	Kt NumLock = mkuq<Key>("NumLock", 144);
	Kt Numpad0 = mkuq<Key>("Numpad0", 96);
	Kt Numpad1 = mkuq<Key>("Numpad1", 97);
	Kt Numpad2 = mkuq<Key>("Numpad2", 98);
	Kt Numpad3 = mkuq<Key>("Numpad3", 99);
	Kt Numpad4 = mkuq<Key>("Numpad4", 100);
	Kt Numpad5 = mkuq<Key>("Numpad5", 101);
	Kt Numpad6 = mkuq<Key>("Numpad6", 102);
	Kt Numpad7 = mkuq<Key>("Numpad7", 103);
	Kt Numpad8 = mkuq<Key>("Numpad8", 104);
	Kt Numpad9 = mkuq<Key>("Numpad9", 105);
	Kt NumpadMultiply = mkuq<Key>("NumpadMultiply", 106);
	Kt NumpadAdd = mkuq<Key>("NumpadAdd", 107);
	Kt NumpadSubtract = mkuq<Key>("NumpadSubtract", 109);
	Kt NumpadDecimal = mkuq<Key>("NumpadDecimal", 110);
	Kt NumpadDivide = mkuq<Key>("NumpadDivide", 111);
	Kt Semicolon = mkuq<Key>("Semicolon", 186);
	Kt Equal = mkuq<Key>("Equal", 187);
	Kt Comma = mkuq<Key>("Comma", 188);
	Kt Minus = mkuq<Key>("Minus", 189);
	Kt Period = mkuq<Key>("Period", 190);
	Kt Slash = mkuq<Key>("Slash", 191);
	Kt Backquote = mkuq<Key>("Backquote", 192);
	Kt BracketLeft = mkuq<Key>("BracketLeft", 219);
	Kt Backslash = mkuq<Key>("Backslash", 220);
	Kt BracketRight = mkuq<Key>("BracketRight", 221);
	Kt Quote = mkuq<Key>("Quote", 222);
};

}//~namespace ngaq
