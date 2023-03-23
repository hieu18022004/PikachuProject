#include <iostream>
#include <conio.h>
#include <Windows.h>
#include "Funcs.h"
using namespace std;

int availablePaths(COORD n, bool** mapCheck, const int ROWS, const int COLS)
{
	int paths = 0, x = n.X, y = n.Y;
	if (n.X == 0)
	{
		if (n.X == 0 && n.Y == 0)
		{
			if (mapCheck[0][1] == true)
			{
				paths++;
			}
			if (mapCheck[1][0] == true)
			{
				paths++;
			}
		}
		if (n.X == 0 && n.Y == COLS - 1)
		{
			if (mapCheck[0][COLS - 2] == true)
			{
				paths++;
			}
			if (mapCheck[1][COLS - 1] == true)
			{
				paths++;
			}
		}
		if (mapCheck[0][n.Y - 1] == true)
		{
			paths++;
		}
		if (mapCheck[0][n.Y + 1] == true)
		{
			paths++;
		}
		if (mapCheck[1][n.Y] == true)
		{
			paths++;
		}
	}
	if (n.X == ROWS - 1)
	{
		if (n.X == ROWS - 1 && n.Y == 0)
		{
			if (mapCheck[ROWS - 1][1] == true)
			{
				paths++;
			}
			if (mapCheck[ROWS - 1][0] == true)
			{
				paths++;
			}
		}
		if (n.X == ROWS - 1 && n.Y == COLS - 1)
		{
			if (mapCheck[ROWS - 1][COLS - 2] == true)
			{
				paths++;
			}
			if (mapCheck[ROWS - 2][COLS - 1] == true)
			{
				paths++;
			}
		}
		if (mapCheck[ROWS - 1][n.Y - 1] == true)
		{
			paths++;
		}
		if (mapCheck[ROWS - 1][n.Y + 1] == true)
		{
			paths++;
		}
		if (mapCheck[ROWS - 2][n.Y] == true)
		{
			paths++;
		}
	}
	if (n.Y == 0)
	{
		if (mapCheck[n.X - 1][0] == true)
		{
			paths++;
		}
		if (mapCheck[n.X + 1][0] == true)
		{
			paths++;
		}
		if (mapCheck[n.X][1] == true)
		{
			paths++;
		}
	}
	if (n.Y == COLS - 1)
	{
		if (mapCheck[n.X - 1][COLS - 1] == true)
		{
			paths++;
		}
		if (mapCheck[n.X + 1][COLS - 1] == true)
		{
			paths++;
		}
		if (mapCheck[n.X][COLS - 2] == true)
		{
			paths++;
		}
	}
	return paths;
}

COORD getNeighbor(COORD n, bool** mapCheck, const int ROWS, const int COLS)
{
	COORD neighbor;
	if (n.X == 0)
	{
		if (n.X == 0 && n.Y == 0)
		{
			if (mapCheck[0][1] == true)
			{
				neighbor.X = 0;
				neighbor.Y = 1;
				return neighbor;
			}
			if (mapCheck[1][0] == true)
			{
				neighbor.X = 1;
				neighbor.Y = 0;
				return neighbor;
			}
		}
		if (n.X == 0 && n.Y == COLS - 1)
		{
			if (mapCheck[0][COLS - 2] == true)
			{
				neighbor.X = 0;
				neighbor.Y = COLS - 2;
				return neighbor;
			}
			if (mapCheck[1][COLS - 1] == true)
			{
				neighbor.X = 1;
				neighbor.Y = COLS - 1;
				return neighbor;
			}
		}
		if (mapCheck[0][n.Y - 1] == true)
		{
			neighbor.X = 0;
			neighbor.Y = n.Y - 1;
			return neighbor;
		}
		if (mapCheck[0][n.Y + 1] == true)
		{
			neighbor.X = 0;
			neighbor.Y = n.Y + 1;
			return neighbor;
		}
		if (mapCheck[1][n.Y] == true)
		{
			neighbor.X = 1;
			neighbor.Y = n.Y;
			return neighbor;
		}
	}
	if (n.X == ROWS - 1)
	{
		if (n.X == ROWS - 1 && n.Y == 0)
		{
			if (mapCheck[ROWS - 1][1] == true)
			{
				neighbor.X = ROWS - 1;
				neighbor.Y = 1;
				return neighbor;
			}
			if (mapCheck[ROWS - 1][0] == true)
			{
				neighbor.X = ROWS - 2;
				neighbor.Y = 0;
				return neighbor;
			}
		}
		if (n.X == ROWS - 1 && n.Y == COLS - 1)
		{
			if (mapCheck[ROWS - 1][COLS - 2] == true)
			{
				neighbor.X = ROWS - 1;
				neighbor.Y = COLS - 2;
				return neighbor;
			}
			if (mapCheck[ROWS - 2][COLS - 1] == true)
			{
				neighbor.X = ROWS - 2;
				neighbor.Y = COLS - 1;
				return neighbor;
			}
		}
		if (mapCheck[ROWS - 1][n.Y - 1] == true)
		{
			neighbor.X = ROWS - 1;
			neighbor.Y = n.Y - 1;
			return neighbor;
		}
		if (mapCheck[ROWS - 1][n.Y + 1] == true)
		{
			neighbor.X = ROWS - 1;
			neighbor.Y = n.Y + 1;
			return neighbor;
		}
		if (mapCheck[ROWS - 2][n.Y] == true)
		{
			neighbor.X = 1;
			neighbor.Y = n.Y;
			return neighbor;
		}
	}
	if (n.Y == 0)
	{
		if (mapCheck[n.X - 1][0] == true)
		{
			neighbor.X = n.X - 1;
			neighbor.Y = 0;
			return neighbor;
		}
		if (mapCheck[n.X + 1][0] == true)
		{
			neighbor.X = n.X + 1;
			neighbor.Y = 0;
			return neighbor;
		}
		if (mapCheck[n.X][1] == true)
		{
			neighbor.X = n.X;
			neighbor.Y = 1;
			return neighbor;
		}
	}
	if (n.Y == COLS - 1)
	{
		if (mapCheck[n.X - 1][COLS - 1] == true)
		{
			neighbor.X = n.X - 1;
			neighbor.Y = COLS - 1;
			return neighbor;
		}
		if (mapCheck[n.X + 1][COLS - 1] == true)
		{
			neighbor.X = n.X + 1;
			neighbor.Y = COLS - 1;
			return neighbor;
		}
		if (mapCheck[n.X][COLS - 2] == true)
		{
			neighbor.X = n.X;
			neighbor.Y = COLS - 2;
			return neighbor;
		}
	}
}

void gameInit(string user,int points, int stages)
{
	const int ROWS = 5, COLS = 6;
	char** table = tableInit(ROWS, COLS);
	bool** mapCheck = mapCheckInit(ROWS, COLS);
	int coordX = 0, coordY = 0, curX = 4, curY = 2;
	while (true)
	{
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
		printScreen(table, ROWS, COLS, user, points, stages, coordX, coordY);
		printHighlighted(curX, curY, table, coordX, coordY);
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
			int coordX1 = 0, coordY1 = 0, curX1 = 4, curY1 = 2;
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
					COORD coord, coord1;
					coord.X = coordX; coord.Y = coordY; coord1.X = coordX1; coord1.Y = coordY1;
					if (table[coordX][coordY] == table[coordX1][coordY1])
					{
						table[coordX][coordY] = ' ';
						table[coordX1][coordY1] = ' ';
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
