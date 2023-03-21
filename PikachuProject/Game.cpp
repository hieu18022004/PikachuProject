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
	gotoxy(2, 5);
	while (true)
	{
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
		printScreen(table, ROWS, COLS, user, points, stages, cordX, cordY);
		cout << endl;
		switch (_getch())
		{
		case 'x':
		{
			cout << "Do you want to exit to main menu? ";
			char confirm; cin >> confirm;
			if (confirm == 'y')
				return;
			break;
		}
		case KEY_UP:
		{
			if (cordX == 0)
			{
				break;
			}
			cordX--;
			break;
		}
		case KEY_DOWN:
		{
			if (cordX == ROWS - 1)
			{
				break;
			}
			cordX++;;
			break;
		}
		case KEY_LEFT:
		{
			if (cordY == 0)
				break;
			cordY--;
			break;
		}
		case KEY_RIGHT:
		{
			if (cordY == COLS - 1)
				break;
			cordY++;
			break;
		}
		}
	}
}