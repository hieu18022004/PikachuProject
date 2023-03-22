#pragma once
#include <Windows.h>
using namespace std;
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_RETURN 13
//structs
struct Node {
	COORD n;
	Node* pNext = NULL;
};
 
struct List {
	Node* pHead = NULL;
};

//list
Node* nodeCreate(int x, int y);
void headPush(List& list, int x, int y);
COORD headPop(List& list);
COORD headGet(List list);

//Functions
int randomInt();
void printTable(char** table, const int ROWS, const int COLS);
char** tableInit(const int ROWS, const int COLS);
bool** mapCheckInit(const int ROWS, const int COLS);
void tableShuffle(char** &table, const int ROWS, const int COLS);
void printScreen(char** table, const int ROWS, const int COLS, string user, int points, int stages, int cordX, int cordY);
void gotoxy(int x, int y);
void printHighlighted(int curX, int curY, char** table, int cordX, int cordY);

//Game
int availablePaths(COORD n, bool** mapCheck, const int ROWS, const int COLS);
void gameInit(string user, int points, int stages);