#include "Functions.h"
using namespace std;

bool checkEndCondition(char** table, const int ROWS, const int COLS)
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			if (table[i][j] != ' ') return false;
		}
	}
	return true;
}

int gameInit(string user, string stages, const int ROWS, const int COLS, char** bg)
{
	int DifX = 106 - COLS / 2 * 8 + 32, DifY = 25 - ROWS / 2 * 4;
	char** table = tableInit(ROWS, COLS);
	int coordX = 0, coordY = 0, curX = DifX + 4, curY = DifY + 2;
	printScreen(table, ROWS, COLS, user, stages, DifX, DifY, bg);
	while (true)
	{
		if (checkEndCondition(table, ROWS, COLS) == true)
		{
			for (int i = 0; i < ROWS; i++)
			{
				delete[] table[i];
			}
			delete[] table;
			return 1;
		}
		if (ROWS == EZ_ROWS && COLS == EZ_COLS)
		{
			printVenusaurMascot();
		}
		if (ROWS == MED_ROWS && COLS == MED_COLS)
		{
			printCharizardMascot();
		}
		if (ROWS == HARD_ROWS && COLS == HARD_COLS)
		{
			printBlastoiseMascot();
		}
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
		if (ROWS == ASIAN_ROWS && COLS == ASIAN_COLS) asianDif(table, ROWS, COLS);
		if (moveAvailability(table, ROWS, COLS) == false)
		{
			system("cls");
			gotoxy(106 - 11, DifY - 2);
			cout << "Out of move! Shuffling!";
			tableShuffle(table, ROWS, COLS);
			Sleep(1000);
		}
		printScreen(table, ROWS, COLS, user, stages, DifX, DifY, bg);
		printHighlighted(curX, curY, table, coordX, coordY);
		cout << endl;
		switch (_getch())
		{
		case 'h':
		{
			/*random_device rd;
			mt19937 gen(rd());
			uniform_int_distribution<> distr(1, 10);
			if (distr(gen) == 4) return 0;*/
			if (Help(table, ROWS, COLS, DifX, DifY) == 1)
			{
				system("cls");
				break;
			}
		}
		case 'x':
		{
			system("cls");
			cout << "Do you want to exit to main menu? ";
			char confirm; cin >> confirm;
			if (confirm == 'y')
				return 0;
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
				printHighlighted(curX, curY, table, coordX, coordY);
				printHighlighted(curX1, curY1, table, coordX1, coordY1);
				cout << endl;
				switch (_getch())
				{
				case KEY_UP:
				{
					undoHighlighted(curX1, curY1, table, coordX1, coordY1);
					displayBackground(table, ROWS, COLS, DifX, DifY, bg);
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
					displayBackground(table, ROWS, COLS, DifX, DifY, bg);
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
					displayBackground(table, ROWS, COLS, DifX, DifY, bg);
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
					displayBackground(table, ROWS, COLS, DifX, DifY, bg);
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
					undoHighlighted(curX1, curY1, table, coordX1, coordY1);
					undoHighlighted(curX, curY, table, coordX, coordY);
					if (table[coordX][coordY] == table[coordX1][coordY1] && table[coordX][coordY] != ' ')
					{
						if (coordX == coordX1 && coordY == coordY1)
						{
							matchCheck = false;
							break;
						}
						COORD coord, coord1;
						coord.X = coordX; coord.Y = coordY; coord1.X = coordX1; coord1.Y = coordY1;
						if (ICheck(coord, coord1, table))
						{
							table[coordX][coordY] = ' ';
							table[coordX1][coordY1] = ' ';
							pathI(coord, coord1, DifX, DifY);
							matchCheck = false;
							matchMusic();
							system("cls");
							break;
						}
						else if (coordX == 0 && coordX1 == 0 || coordX == ROWS - 1 && coordX1 == ROWS - 1 || coordY == 0 && coordY1 == 0 || coordY == COLS - 1 && coordY1 == COLS - 1)
						{
							table[coordX][coordY] = ' ';
							table[coordX1][coordY1] = ' ';
							marginPath(coord, coord1, ROWS, COLS, DifX, DifY);
							matchCheck = false;
							matchMusic();
							system("cls");
							break;
						}
						else if (LCheck(coord, coord1, table, DifX, DifY))
						{
							table[coordX][coordY] = ' ';
							table[coordX1][coordY1] = ' ';
							matchCheck = false;
							matchMusic();
							system("cls");
							break;
						}
						else if (ZCheck(coord, coord1, table, DifX, DifY))
						{
							table[coordX][coordY] = ' ';
							table[coordX1][coordY1] = ' ';
							matchCheck = false;
							matchMusic();
							system("cls");
							break;
						}
						else if (UCheck(coord, coord1, table, ROWS, COLS, DifX, DifY))
						{
							table[coordX][coordY] = ' ';
							table[coordX1][coordY1] = ' ';
							matchCheck = false;
							matchMusic();
							system("cls");
							break;
						}
					}
					system("cls");
					matchCheck = false;
					break;
				}
				}
			}
			break;
		}
		}
	}
	return 0;
}

