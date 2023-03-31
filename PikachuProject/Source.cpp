#include <iostream>
#include<conio.h>
#include "Funcs.h"
using namespace std;
int main()
{
	// y: 0->48 || x: 0 -> 210 center x=106 y=25
	HWND hWnd = GetConsoleWindow(); //console full screen ref: https://www.daniweb.com/programming/software-development/threads/31665/how-to-make-console-programs-full-screen.
	ShowWindow(hWnd, SW_SHOWMAXIMIZED);
	ShowConsoleCursor(false);
	PlaySound(TEXT("Enemy.wav"), NULL, SND_SYNC);
	//gameInit("Hieu", 0, 0, MED_ROWS, MED_COLS);
	return 1;
}



