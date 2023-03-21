#pragma once
using namespace std;
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
//structs

//Functions
int randomInt();
void printTable(char** table, const int ROWS, const int COLS);
char** tableInit(const int ROWS, const int COLS);
void tableShuffle(char** &table, const int ROWS, const int COLS);
void printScreen(char** table, const int ROWS, const int COLS, string user, int points, int stages, int cordX, int cordY);
void gotoxy(int x, int y);
//Game
void gameInit(string user, int points, int stages);