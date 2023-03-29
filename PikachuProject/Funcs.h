#pragma once
#include <Windows.h>
using namespace std;
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_RETURN 13
#define EZ_X 72
#define EZ_Y 8
//queue structs
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
int getSize(List list);
void headPush(List& list, int x, int y);
void tailPush(List& list, int x, int y);
COORD headPop(List& list);
COORD headGet(List list);
COORD tailGet(List list);
void removeAll(List& list);

//Functions
int randomInt();
void printTable(char** table, const int ROWS, const int COLS,int curX,int curY);
char** tableInit(const int ROWS, const int COLS);
void tableShuffle(char** &table, const int ROWS, const int COLS);
void printScreen(char** table, const int ROWS, const int COLS, string user, int points, int stages, int cordX, int cordY);
void gotoxy(int x, int y);
void printHighlighted(int curX, int curY, char** table, int cordX, int cordY);
bool ICheck(COORD start, COORD end, char** table);
bool LCheck(COORD start, COORD end, char** table);
bool ZCheck(COORD start, COORD end, char** table);
bool UCheck(COORD start, COORD end, char** table, const int ROWS, const int COLS);
bool findWays(char** table, const int ROWS, const int COLS, int DifX, int DifY);
int help(char** table, const int ROWS, const int COLS, int DifX, int DifY);


//Game
void gameInit(string user, int points, int stages, int DifX, int DifY);
// Data and player infor
struct Player 
{
    char name[50];
    int yearOfBirth;
    int records;
    int saveStages;
};

// Struct to store player information
struct LogIn 
{
    string username;
    string password;
};

// Struct to store game information
struct Game 
{
    string account;
    int currentStage;
};

// Struct to store leaderboard entry
struct LeaderboardEntry 
{
    string username;
    int timeTaken;
};


void saveGameData();
void SignUp();
void displayMainMenu();
void displayDifficultyMenu();