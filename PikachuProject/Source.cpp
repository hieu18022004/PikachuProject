#include <iostream>
#include<conio.h>
#include "Funcs.h"
using namespace std;
int main()
{
	HWND hWnd = GetConsoleWindow(); //console full screen ref: https://www.daniweb.com/programming/software-development/threads/31665/how-to-make-console-programs-full-screen.
	ShowWindow(hWnd, SW_SHOWMAXIMIZED);
	int y = 0, x = 0;
	while (true)
	{
		gotoxy(x, y);
		cout << "Here: " << x << ":" << y;
		switch (_getch())
		{
		case VK_DOWN:
		{
			y++;
			break;
		}
		case VK_RIGHT:
		{
			x++;
			break;
		}
		}
	}
	//gameInit("Hieu", 0, 0, EZ_X, EZ_Y);
	return 1;
}



