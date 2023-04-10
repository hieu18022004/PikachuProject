#pragma once
#include <Windows.h>
#include <iostream>
#include <ctime>
#include <chrono>
#include <cstring>
#include <string>
#include <fstream>
#include <iomanip>
#include <conio.h>
#include <algorithm>
#include <random>
#pragma comment (lib,"Winmm.lib")

using namespace std;
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_RETURN 13
#define EZ_ROWS 4
#define EZ_COLS 8
#define MED_ROWS 6
#define MED_COLS 10
#define HARD_ROWS 10
#define HARD_COLS 14
#define ASIAN_ROWS 10
#define ASIAN_COLS 16

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
int randomInt(); //ref: https://stackoverflow.com/questions/7560114/random-number-c-in-some-range
void printTableV2(char** table, const int ROWS, const int COLS,int curX,int curY, char** bg); //ref:https://cplusplus.com/forum/beginner/248878/
char** tableInit(const int ROWS, const int COLS);
void tableShuffle(char** &table, const int ROWS, const int COLS);
void printScreen(char** table, const int ROWS, const int COLS, string user, string stages, int cordX, int cordY, char** bg);

void gotoxy(int x, int y); //ref:https://stackoverflow.com/questions/55635791/how-to-use-function-gotoxyint-x-int-y

//color ref:https://stackoverflow.com/questions/9965710/how-to-change-text-and-background-color
void printHighlighted(int curX, int curY, char** table, int cordX, int cordY);
void undoHighlighted(int curX, int curY, char** table, int cordX, int cordY);

//path ref:https://cplusplus.com/forum/beginner/248878/
bool ICheck(COORD start, COORD end, char** table);
bool LCheck(COORD start, COORD end, char** table, int cordX, int cordY);
bool ZCheck(COORD start, COORD end, char** table, int cordX, int cordY);
bool validCheck(COORD corner, const int ROWS, const int COLS);
bool UCheck(COORD start, COORD end, char** table, const int ROWS, const int COLS, int cordX, int cordY);
void pathI(COORD start, COORD end, int cordX, int cordY);
void marginPath(COORD coord, COORD coord1, const int ROWS, const int COLS, int cordX, int cordY);
void pathCorner(COORD start, COORD corner, COORD end, int cordX, int cordY);

//help move
bool L_Availability(COORD start, COORD end, char** table);
bool Z_Availability(COORD start, COORD end, char** table);
bool U_Availability(COORD start, COORD end, char** table, const int ROWS, const int COLS);
bool moveAvailability(char** table, const int ROWS, const int COLS);
int Help(char** table, const int ROWS, const int COLS, int DifX, int DifY);

//ASIAN Difficulty
void swapChar(char& a, char& b);
void asianDif(char** &table, const int ROWS, const int COLS);

//Game
bool checkEndCondition(char** table, const int ROWS, const int COLS);
int gameInit(string user, string stages, const int ROWS, const int COLS, char** bg);

// UI & VFX Funcs
void ShowConsoleCursor(bool showFlag);
void playBG(bool flag);
void playBGAsian(bool flag);
void matchMusic();
void selectMusic();
void gameFinishMusic();
void roundstartMusic();
void printCharizardMascot();
void printVenusaurMascot();
void printBlastoiseMascot();
char** getBackground( string mode);
void deleteBackground(char** bg, string mode);
void displayBackground(char** table, const int ROWS, const int COLS, int curX, int curY, char** bg);

//menu and leaderboard
void printLogo();
int joinMenu();
int launchMenu(string displayname);
int difficultyMenu();
void gameFinishAnnounce(chrono::duration<double> elapsed_seconds);
void displayLeaderboard(pair <string, chrono::duration<double>> leaderboard[], int size);
void goodbyeMenu();

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


//void saveGameData();
void SignUp();
bool SignIn(string& displayname);
void saveScoreLeaderboard(pair<string, chrono::duration<double>> leaderboard[], int size, string mode);
void loadScoreLeaderboard(pair <string, chrono::duration<double>> leaderboard[], int size, string mode);
void leaderboardInit(pair <string, chrono::duration<double>> leaderboard[], int size);
void convertTxtToBin(const char* txtFileName, const char* binFileName);
int updateLeaderboard(pair<string, chrono::duration<double>> leaderboard[], int size, string name, chrono::duration<double> time_elapsed);

