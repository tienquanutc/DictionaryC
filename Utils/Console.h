#ifndef _CONSOLE_H_
#define _CONSOLE_H_ 

#include <windows.h>

class Console {
public:
	static void gotoxy(const short int x, const short int y);
	static void setTextColor(const int wColor);
	static void clear();
};

enum Color {
	BLACK = 0,
	BLUE = 1,
	GREEN = 2,
	CYAN = 3,
	RED = 4,
	MAGENTA = 5,
	BROWN = 6,
	LIGHT_GRAY = 7,
	DARK_GRAY = 8,
	LIGHT_BLUE = 9,
	LIGHT_GREEN = 10,
	LIGHT_CYAN = 11,
	LIGHT_RED = 12,
	LIGHT_MAGENTA = 13,
	YELLOW = 14,
	WHITE = 15
};
#endif
