#include <iostream>
#include "Funcs.h"
using namespace std;
int main()
{
	HWND hWnd = GetConsoleWindow();
	ShowWindow(hWnd, SW_SHOWMAXIMIZED);
	gameInit("Hieu", 0, 0);
	return 1;
}