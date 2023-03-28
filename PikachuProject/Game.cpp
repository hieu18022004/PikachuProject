#include <iostream>
#include <conio.h>
#include <Windows.h>
#include "Funcs.h"
using namespace std;

/*int availablePaths(int nX, int nY, bool** mapCheck, const int ROWS, const int COLS)
{
	int paths = 0, x = nX, y = nY;
	int dx[4] = { 0,0,1,-1 };
	int dy[4] = { -1,1,0,0 };
	for (int i = 0; i < 4; i++)
	{
		int tmpx = x + dx[i], tmpy = y + dy[i];
		if (tmpx >= 0 && tmpx < ROWS + 1 && tmpy >= 0 && tmpy < COLS + 1)
		{
			if (mapCheck[tmpx + 1][tmpy + 1] == true)
				paths++;
		}
	}
	return paths;
}

COORD getNeighbor(COORD n, bool** mapCheck, const int ROWS, const int COLS)
{
	COORD neighbor;
	neighbor.X = -1, neighbor.Y = -1;
	int dx[4] = { 0,0,1,-1 };
	int dy[4] = { -1,1,0,0 };
	for (int i = 0; i < 4; i++)
	{
		int tmpx = n.X + dx[i], tmpy = n.Y + dy[i];
		if (tmpx >= 0 && tmpx < ROWS + 2 && tmpy >= 0 && tmpy < COLS + 2)
		{
			if (mapCheck[tmpx + 1][tmpy + 1] == true)
			{
				neighbor.X = tmpx;
				neighbor.Y = tmpy;
				return neighbor;
			}
		}
	}
	return neighbor;
}*/

void gameInit(string user,int points, int stages)
{
	const int ROWS = 5, COLS = 6;
	char** table = tableInit(ROWS, COLS);
	int coordX = 0, coordY = 0, curX = 11, curY = 4;
	while (true)
	{
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
		printScreen(table, ROWS, COLS, user, points, stages, coordX, coordY);
		printHighlighted(curX, curY, table, coordX, coordY);
		cout << endl;
		switch (_getch())
		{
		case 's':
		{
			tableShuffle(table, ROWS, COLS);
			break;
		}
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
			if (coordX == 0)
			{
				coordX = ROWS - 1;
				for (int i = 0; i < ROWS-1; i++)
					curY = curY + 4;
				break;
			}
			coordX--;
			curY = curY - 4;
			break;
		}
		case KEY_DOWN:
		{
			if (coordX == ROWS - 1)
			{
				coordX = 0;
				curY = 2;
				break;
			}
			coordX++;
			curY = curY + 4;
			break;
		}
		case KEY_LEFT:
		{
			if (coordY == 0)
			{
				coordY = COLS - 1;
				for (int i = 0; i < COLS - 1; i++)
				{
					curX = curX + 8;
				}
				break;
			}
			coordY--;
			curX = curX - 8;
			break;
		}
		case KEY_RIGHT:
		{
			if (coordY == COLS - 1)
			{
				coordY = 0;
				curX = 4;
				break;
			}
			coordY++;
			curX = curX + 8;
			break;
		}
		case KEY_RETURN:
		{
			int coordX1 = 0, coordY1 = 0, curX1 = 11, curY1 = 4;
			bool matchCheck = true;
			while (matchCheck==true)
			{
				FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
				printScreen(table, ROWS, COLS, user, points, stages, coordX, coordY);
				printHighlighted(curX, curY, table, coordX, coordY);
				printHighlighted(curX1, curY1, table, coordX1, coordY1);
				cout << endl;
				switch (_getch())
				{
				case KEY_UP:
				{
					if (coordX1 == 0)
					{
						coordX1 = ROWS - 1;
						for (int i = 0; i < ROWS - 1; i++)
							curY1 = curY1 + 4;
						break;
					}
					coordX1--;
					curY1 = curY1 - 4;
					break;
				}
				case KEY_DOWN:
				{
					if (coordX1 == ROWS - 1)
					{
						coordX1 = 0;
						curY1 = 2;
						break;
					}
					coordX1++;
					curY1 = curY1 + 4;
					break;
				}
				case KEY_LEFT:
				{
					if (coordY1 == 0)
					{
						coordY1 = COLS - 1;
						for (int i = 0; i < COLS - 1; i++)
						{
							curX1 = curX1 + 8;
						}
						break;
					}
					coordY1--;
					curX1 = curX1 - 8;
					break;
				}
				case KEY_RIGHT:
				{
					if (coordY1 == COLS - 1)
					{
						coordY1 = 0;
						curX1 = 4;
						break;
					}
					coordY1++;
					curX1 = curX1 + 8;
					break;
				}
				case KEY_RETURN:
				{
					if (table[coordX][coordY] == table[coordX1][coordY1])
					{
						COORD coord, coord1;
						coord.X = coordX; coord.Y = coordY; coord1.X = coordX1; coord1.Y = coordY1;
						if (coordX == 0 && coordX1 == 0 || coordX == ROWS - 1 && coordX1 == ROWS - 1 || coordY == 0 && coordY1 == 0 || coordY == COLS - 1 && coordY1 == COLS - 1)
						{
							table[coordX][coordY] = ' ';
							table[coordX1][coordY1] = ' ';
							matchCheck = false;
							break;
						}
						else if (coordX == coordX1 && abs(coordY - coordY1) == 1 || coordY == coordY1 && abs(coordX - coordX1) == 1)
						{
							table[coordX][coordY] = ' ';
							table[coordX1][coordY1] = ' ';
							matchCheck = false;
							break;
						}
						else if (ICheck(coord, coord1, table))
						{
							table[coordX][coordY] = ' ';
							table[coordX1][coordY1] = ' ';
							matchCheck = false;
							system("cls");
							cout << "I" << endl;
							system("pause");
							system("cls");
							break;
						}
						else if (LCheck(coord, coord1, table))
						{
							table[coordX][coordY] = ' ';
							table[coordX1][coordY1] = ' ';
							matchCheck = false;
							system("cls");
							cout << "L" << endl;
							system("pause");
							system("cls");
							break;
						}
						else if (ZCheck(coord, coord1, table))
						{
							table[coordX][coordY] = ' ';
							table[coordX1][coordY1] = ' ';
							matchCheck = false;
							system("cls");
							cout << "Z" << endl;
							system("pause");
							system("cls");
							break;
						}
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
