#include <iostream>
#include <conio.h>
#include <Windows.h>
#include "Funcs.h"
#include <chrono>
#include <thread>
#include <random>
using namespace std;


void gameInit(string user,int points, int stages, const int ROWS, const int COLS)
{
	int DifX = 106 - COLS / 2 * 8, DifY = 25 - ROWS / 2 * 4;
	char** table = tableInit(ROWS, COLS);
	int coordX = 0, coordY = 0, curX = DifX + 4, curY = DifY + 2;
	printScreen(table, ROWS, COLS, user, points, stages, DifX, DifY);
	deleteBorder(table, ROWS, COLS, DifX, DifY);
	while (true)
	{
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
		deleteBorder(table, ROWS, COLS, DifX, DifY);
		printHighlighted(curX, curY, table, coordX, coordY);
		cout << endl;
		switch (_getch())
		{
		case 's':
		{
			random_device rd;
			mt19937 gen(rd());
			uniform_int_distribution<> distr(1, 10);
			if (distr(gen) == 4) exit(1);
			tableShuffle(table, ROWS, COLS);
			printScreen(table, ROWS, COLS, user, points, stages, DifX, DifY);
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
			undoHighlighted(curX, curY, table, coordX, coordY);
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
			undoHighlighted(curX, curY, table, coordX, coordY);
			if (coordX == ROWS - 1)
			{
				coordX = 0;
				curY = DifY + 2;
				break;
			}
			coordX++;
			curY = curY + 4;
			break;
		}
		case KEY_LEFT:
		{
			undoHighlighted(curX, curY, table, coordX, coordY);
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
			undoHighlighted(curX, curY, table, coordX, coordY);
			if (coordY == COLS - 1)
			{
				coordY = 0;
				curX = DifX + 4;
				break;
			}
			coordY++;
			curX = curX + 8;
			break;
		}
		case KEY_RETURN:
		{
			int coordX1 = coordX, coordY1 = coordY, curX1 = curX, curY1 = curY;
			bool matchCheck = true;
			while (matchCheck==true)
			{
				FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
				deleteBorder(table, ROWS, COLS, DifX, DifY);
				printHighlighted(curX, curY, table, coordX, coordY);
				printHighlighted(curX1, curY1, table, coordX1, coordY1);
				cout << endl;
				switch (_getch())
				{
				case KEY_UP:
				{
					undoHighlighted(curX1, curY1, table, coordX1, coordY1);
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
					undoHighlighted(curX1, curY1, table, coordX1, coordY1);
					if (coordX1 == ROWS - 1)
					{
						coordX1 = 0;
						curY1 = DifY + 2;
						break;
					}
					coordX1++;
					curY1 = curY1 + 4;
					break;
				}
				case KEY_LEFT:
				{
					undoHighlighted(curX1, curY1, table, coordX1, coordY1);
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
					undoHighlighted(curX1, curY1, table, coordX1, coordY1);
					if (coordY1 == COLS - 1)
					{
						coordY1 = 0;
						curX1 = DifX + 4;
						break;
					}
					coordY1++;
					curX1 = curX1 + 8;
					break;
				}
				case KEY_RETURN:
				{
					if (table[coordX][coordY] == table[coordX1][coordY1] && table[coordX][coordY] != ' ')
					{
						if (coordX == coordX1 && coordY == coordY1)
						{
							matchCheck = false;
							break;
						}
						COORD coord, coord1;
						coord.X = coordX; coord.Y = coordY; coord1.X = coordX1; coord1.Y = coordY1;
						if (coordX == 0 && coordX1 == 0 || coordX == ROWS - 1 && coordX1 == ROWS - 1 || coordY == 0 && coordY1 == 0 || coordY == COLS - 1 && coordY1 == COLS - 1)
						{
							table[coordX][coordY] = ' ';
							table[coordX1][coordY1] = ' ';
							matchCheck = false;
							printScreen(table, ROWS, COLS, user, points, stages, DifX, DifY);
							deleteBorder(table, ROWS, COLS, DifX, DifY);
							break;
						}
						else if (coordX == coordX1 && abs(coordY - coordY1) == 1 || coordY == coordY1 && abs(coordX - coordX1) == 1)
						{
							table[coordX][coordY] = ' ';
							table[coordX1][coordY1] = ' ';
							matchCheck = false;
							printScreen(table, ROWS, COLS, user, points, stages, DifX, DifY);
							deleteBorder(table, ROWS, COLS, DifX, DifY);
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
							printScreen(table, ROWS, COLS, user, points, stages, DifX, DifY);
							deleteBorder(table, ROWS, COLS, DifX, DifY);
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
							printScreen(table, ROWS, COLS, user, points, stages, DifX, DifY);
							deleteBorder(table, ROWS, COLS, DifX, DifY);
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
							printScreen(table, ROWS, COLS, user, points, stages, DifX, DifY);
							deleteBorder(table, ROWS, COLS, DifX, DifY);
							break;
						}
						else if (UCheck(coord, coord1, table, ROWS, COLS))
						{
							table[coordX][coordY] = ' ';
							table[coordX1][coordY1] = ' ';
							matchCheck = false;
							system("cls");
							cout << "U" << endl;
							system("pause");
							system("cls");
							printScreen(table, ROWS, COLS, user, points, stages, DifX, DifY);
							deleteBorder(table, ROWS, COLS, DifX, DifY);
							break;
						}
					}
					printScreen(table, ROWS, COLS, user, points, stages, DifX, DifY);
					deleteBorder(table, ROWS, COLS, DifX, DifY);
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
