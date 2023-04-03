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
	bool exitFlag = false;
	playBG(true);
	while (exitFlag == false)
	{
		switch (launchMenu())
		{
		case 1:
		{
			system("cls");
			switch (difficultyMenu())
			{
			case 1:
			{
				system("cls");
				gameInit("Hieu", 0, 0, EZ_ROWS, EZ_COLS);
				break;
			}
			case 2:
			{
				system("cls");
				gameInit("Hieu", 0, 0, MED_ROWS, MED_COLS);
				break;
			}
			case 3:
			{
				system("cls");
				gameInit("Hieu", 0, 0, HARD_ROWS, HARD_COLS);
				break;
			}
			case 4:
			{
				system("cls");
				gameInit("Hieu", 0, 0, ASIAN_ROWS, ASIAN_COLS);
				break;
			}
			}
			system("cls");
			break;
		}
		}
	}
	return 1;
}



