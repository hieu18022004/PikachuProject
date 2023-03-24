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
bool emptyCheck(List list);
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
void dfs(char** board, int row, int col, int i, int j, char c);
void removeNonAdjacentMatch(char** board, int row, int col);

//Game
int availablePaths(COORD n, bool** mapCheck, const int ROWS, const int COLS);
void gameInit(string user, int points, int stages);
COORD getNeighbor(COORD n, bool** mapCheck, const int ROWS, const int COLS);
// Data
struct Player {
    char name[50];
    int yearOfBirth;
    int records;
    int saveStages;
};