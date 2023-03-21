#include <iostream>
#include <conio.h>
#include <Windows.h>
#include "Funcs.h"
using namespace std;

void gameInit(string user,int points, int stages)
{
	const int ROWS = 3, COLS = 4;
	char** table = tableInit(ROWS, COLS);
	int cordX = 0, cordY = 0, curX = 4, curY = 2;
	while (true)
	{
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
		printScreen(table, ROWS, COLS, user, points, stages, cordX, cordY);
		printHighlighted(curX, curY, table, cordX, cordY);
		cout << endl;
		switch (_getch())
		{
		case 'x':
		{
			system("cls");
			cout << "Do you want to exit to main menu? ";
			char confirm; cin >> confirm;
			if (confirm == 'y')
				return;
			else
				system("cls");
			break;
		}
		case KEY_UP:
		{
			if (cordX == 0)
			{
				cordX = ROWS - 1;
				for (int i = 0; i < ROWS-1; i++)
					curY = curY + 4;
				break;
			}
			cordX--;
			curY = curY - 4;
			break;
		}
		case KEY_DOWN:
		{
			if (cordX == ROWS - 1)
			{
				cordX = 0;
				curY = 2;
				break;
			}
			cordX++;
			curY = curY + 4;
			break;
		}
		case KEY_LEFT:
		{
			if (cordY == 0)
			{
				cordY = COLS - 1;
				for (int i = 0; i < COLS - 1; i++)
				{
					curX = curX + 8;
				}
				break;
			}
			cordY--;
			curX = curX - 8;
			break;
		}
		case KEY_RIGHT:
		{
			if (cordY == COLS - 1)
			{
				cordY = 0;
				curX = 4;
				break;
			}
			cordY++;
			curX = curX + 8;
			break;
		}
		case KEY_RETURN:
		{
			int cordX1 = 0, cordY1 = 0, curX1 = 4, curY1 = 2;
			bool matchCheck = true;
			while (matchCheck==true)
			{
				FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
				printScreen(table, ROWS, COLS, user, points, stages, cordX, cordY);
				printHighlighted(curX, curY, table, cordX, cordY);
				printHighlighted(curX1, curY1, table, cordX1, cordY1);
				cout << endl;
				switch (_getch())
				{
				case KEY_UP:
				{
					if (cordX1 == 0)
					{
						cordX1 = ROWS - 1;
						for (int i = 0; i < ROWS - 1; i++)
							curY1 = curY1 + 4;
						break;
					}
					cordX1--;
					curY1 = curY1 - 4;
					break;
				}
				case KEY_DOWN:
				{
					if (cordX1 == ROWS - 1)
					{
						cordX1 = 0;
						curY1 = 2;
						break;
					}
					cordX1++;
					curY1 = curY1 + 4;
					break;
				}
				case KEY_LEFT:
				{
					if (cordY1 == 0)
					{
						cordY1 = COLS - 1;
						for (int i = 0; i < COLS - 1; i++)
						{
							curX1 = curX1 + 8;
						}
						break;
					}
					cordY1--;
					curX1 = curX1 - 8;
					break;
				}
				case KEY_RIGHT:
				{
					if (cordY1 == COLS - 1)
					{
						cordY1 = 0;
						curX1 = 4;
						break;
					}
					cordY1++;
					curX1 = curX1 + 8;
					break;
				}
				case KEY_RETURN:
				{
					if (table[cordX][cordY] == table[cordX1][cordY1])
					{
						table[cordX][cordY] = ' ';
						table[cordX1][cordY1] = ' ';
					}
					matchCheck = false;
					break;
				}
				}
			}
			break;
		}
		}
	}
}