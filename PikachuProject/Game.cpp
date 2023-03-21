#include <iostream>
#include <conio.h>
#include <Windows.h>
#include "Funcs.h"
using namespace std;

void gameInit(string user,int points, int stages)
{
	const int ROWS = 3, COLS = 4;
	char** table = tableInit(ROWS, COLS);
	int cordX = 0, cordY = 0;
	printScreen(table, ROWS, COLS, user, points, stages, cordX, cordY);
	char interact = 0;
	while (true)
	{
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
		SetCursorPos(cordX, cordY);
		interact = _getch();
		printScreen(table, ROWS, COLS, user, points, stages, cordX, cordY);
		cout << endl;
		switch (interact)
		{
		case 'x':
			{
				cout << "Do you want to exit to main menu? ";
				char confirm; cin >> confirm;
				if (confirm == 'y')
					return;
				break;
			}
		default:
			if (GetKeyState(VK_UP) < 0)
			{
				if (cordX == 0)
				{
					break;
				}
				cordX--;
				break;
			}
			if (GetKeyState(VK_DOWN) < 0 )
			{
				if (cordX == ROWS - 1)
				{
					break;
				}
				cordX++;
				break;
			}
			if (GetKeyState(VK_LEFT) < 0)
			{
				if (cordY == 0)
					break;
				cordY--;
				break;
			}
			if (GetKeyState(VK_RIGHT) < 0)
			{
				if (cordY == COLS - 1)
					break;
				cordY++;
				break;
			}
		}
	}
}