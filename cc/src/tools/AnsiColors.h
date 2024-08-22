#pragma once
#include "common.h"
namespace _ {

class AnsiColors {
public:
	static AnsiColors& inst(){
		static AnsiColors inst;
		return inst;
	}

	string Reset = "\x1b[0m";
	string Black = "\x1b[30m";
	string Red = "\x1b[31m";
	string Green = "\x1b[32m";
	string Yellow = "\x1b[33m";
	string Blue = "\x1b[34m";
	string Magenta = "\x1b[35m";
	string Cyan = "\x1b[36m";
	string White = "\x1b[37m";
	string BrightBlack = "\x1b[90m";
	string BrightRed = "\x1b[91m";
	string BrightGreen = "\x1b[92m";
	string BrightYellow = "\x1b[93m";
	string BrightBlue = "\x1b[94m";
	string BrightMagenta = "\x1b[95m";
	string BrightCyan = "\x1b[96m";
	string BrightWhite = "\x1b[97m";
	string BgBlack = "\x1b[40m";
	string BgRed = "\x1b[41m";
	string BgGreen = "\x1b[42m";
	string BgYellow = "\x1b[43m";
	string BgBlue = "\x1b[44m";
	string BgMagenta = "\x1b[45m";
	string BgCyan = "\x1b[46m";
	string BgWhite = "\x1b[47m";
	string BgBrightBlack = "\x1b[100m";
	string BgBrightRed = "\x1b[101m";
	string BgBrightGreen = "\x1b[102m";
	string BgBrightYellow = "\x1b[103m";
	string BgBrightBlue = "\x1b[104m";
	string BgBrightMagenta = "\x1b[105m";
	string BgBrightCyan = "\x1b[106m";
	string BgBrightWhite = "\x1b[107m";
	string Bold = "\x1b[1m";
	string Underline = "\x1b[4m";
	string Inverse = "\x1b[7m";
	string Hidden = "\x1b[8m";


};



}//~namespace _