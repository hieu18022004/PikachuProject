#include <iostream>
#include "Funcs.h"
using namespace std;
int main()
{
	HWND hWnd = GetConsoleWindow(); //console full screen ref: https://www.daniweb.com/programming/software-development/threads/31665/how-to-make-console-programs-full-screen.
	ShowWindow(hWnd, SW_SHOWMAXIMIZED);
	gameInit("Hieu", 0, 0);
	return 1;
}



