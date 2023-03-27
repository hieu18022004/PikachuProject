#include <iostream>
#include <iomanip>
#include <random>
#include <windows.h>
#include "Funcs.h"
using namespace std;


void gotoxy(int x, int y) {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD cursorCoord;
    cursorCoord.X = x;
    cursorCoord.Y = y;
    SetConsoleCursorPosition(consoleHandle, cursorCoord);
    
}

void printHighlighted(int curX, int curY, char** table, int cordX, int cordY)
{
    gotoxy(curX, curY);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 116);
    cout << table[cordX][cordY];
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}

int randomInt()
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distr(65, 90);
    return distr(gen);
} //ref: https://stackoverflow.com/questions/7560114/random-number-c-in-some-range

void tableShuffle(char** &table, const int ROWS, const int COLS)
{
    char* setChar = new char[ROWS * COLS];
    int index = 0;
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            setChar[index] = table[i][j];
            index++;
        }
    }
    index = 0;
    int n = 0;
    for (int i = 0; i < ROWS * COLS; i++)
    {
        if (setChar[i] != ' ')
        {
            n++;
        }
    }
    char* toShuffle = new char[n];
    for (int i = 0; i < ROWS * COLS; i++)
    {
        if (setChar[i] != ' ')
        {
            toShuffle[index] = setChar[i];
            index++;
        }
    }
    random_shuffle(toShuffle, toShuffle + index);
    index = 0;
    for (int i = 0; i < ROWS * COLS; i++)
    {
        if (setChar[i] != ' ')
        {
            setChar[i]=toShuffle[index];
            index++;
        }
    }
    index = 0;
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            table[i][j] = setChar[index];
            index++;
        }
    }
}

void printTable(char** table, const int ROWS, const int COLS) {

    // print the table
    cout << setw(COLS * 8 + 1) << setfill('-') << "" << endl;
    for (int i = 0; i < ROWS; i++) {
        cout << "|";
        for (int c = 0; c < COLS; c++)
        {
            cout << setw(8) << setfill(' ') << "|";
        }
        cout << endl;
        for (int j = 0; j < COLS; j++) {
            cout << "|   " << table[i][j] << "   ";
        }
        cout << "|" << endl;
        cout << "|";
        for (int c = 0; c < COLS; c++)
        {
            cout << setw(8) << setfill(' ') << "|";
        }
        cout << endl;
        cout << setw(COLS * 8 + 1) << setfill('-') << "" << endl;
    }
}

void printScreen(char** table, const int ROWS, const int COLS, string user, int points, int stages, int cordX, int cordY)
{
    COORD cur = { 0, 0 };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cur);
    printTable(table, ROWS, COLS);
    cout << "\n\n Cordinate: [" << cordX + 1 << " : " << cordY + 1 << "] : " << table[cordX][cordY];
    cout << "\n\n\n\n";
    cout << "Username: " << user << endl << "Points: " << points << endl << "Stages completed: " << stages << endl << "Press x to exit to menu\n";
}

char** tableInit(const int ROWS, const int COLS)
{
    char** table = new char* [ROWS];
    for (int i = 0; i < ROWS; i++)
    {
        table[i] = new char[COLS];
    }
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            table[i][j] = i * j;
        }
    }    int* setChar = new int[COLS * ROWS];
    for (int i = 0; i < ROWS * COLS; i++)
    {
        setChar[i] = randomInt();
        setChar[i + 1] = setChar[i];
        i++;
    }
    int index = 0;
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            table[i][j] = char(setChar[index]);
            index++;
        }
    }
    tableShuffle(table, ROWS, COLS);
    return table;
}

bool** mapCheckInit(const int ROWS, const int COLS)
{
    bool** mapCheck = new bool* [ROWS+2];
    for (int i = 0; i < ROWS + 2; i++)
    {
        mapCheck[i] = new bool[COLS+2];
    }
    for (int i = 0; i < ROWS+2; i++)
    {
        for (int j = 0; j < COLS+2; j++)
        {
            mapCheck[i][j] = false;
        }
    }
    for (int i = 0; i < ROWS + 2; i++)
    {
        mapCheck[i][0] = true;
        mapCheck[i][COLS + 1] = true;
        mapCheck[0][i] = true;
        mapCheck[ROWS + 1][i] = true;
    }
    return mapCheck;
}

bool validCheck(COORD n, bool** mapCheck, const int ROWS, const int COLS)
{
    return n.X >= 0 && n.X < ROWS + 2 && n.Y >= 0 && n.Y < COLS + 2 && mapCheck[n.X][n.Y] == true;
}

bool bfs()


