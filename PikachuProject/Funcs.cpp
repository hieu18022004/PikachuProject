﻿#include <iostream>
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
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 116);
    gotoxy(curX - 3, curY - 1);
    cout << "       " << endl;
    gotoxy(curX - 3, curY);
    cout << "   " << table[cordX][cordY] << "   " << endl;
    gotoxy(curX - 3, curY + 1);
    cout << "       ";
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

void printTable(char** table, const int ROWS, const int COLS, int curX, int curY) {

    // print the table
    cout << setw(COLS * 8 + 1) << setfill('-') << "" << endl;
    for (int i = 0; i < ROWS; i++) {
        cout << setw(curX + 1) << setfill(' ') << "|";
        for (int c = 0; c < COLS; c++)
        {
            cout << setw(8) << setfill(' ') << "|";
        }
        cout << endl;
        cout << setw(curX) << setfill(' ') << "";
        for (int j = 0; j < COLS; j++) {
            cout << "|   " << table[i][j] << "   ";
        }
        cout << "|" << endl;
        cout << setw(curX + 1) << setfill(' ') << "|";
        for (int c = 0; c < COLS; c++)
        {
            cout << setw(8) << setfill(' ') << "|";
        }
        cout << endl;
        cout << setw(curX) << setfill(' ') << "" << setw(COLS * 8 + 1) << setfill('-') << "" << endl;
    }
}

void printScreen(char** table, const int ROWS, const int COLS, string user, int points, int stages, int cordX, int cordY)
{
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {0, 0});
    cout << "Username: " << user << endl << "Points: " << points << endl << "Stages completed: " << stages << endl << "Press x to exit to menu" << endl << "s to shuffle" << endl;
    COORD cur = { cordX, cordY };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cur);
    printTable(table, ROWS, COLS, cordX, cordY);
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

bool ICheck(COORD start, COORD end, char** table)
{
    if (start.X == end.X)
    {
        if (start.Y > end.Y)
        {
            for (int i = end.Y + 1; i < start.Y; i++)
            {
                if (table[start.X][i] != ' ') return false;
            }
        }
        if (start.Y < end.Y)
        {
            for (int i = start.Y + 1; i < end.Y; i++)
            {
                if (table[start.X][i] != ' ') return false;
            }
        }
        return true;
    }
    if (start.Y == end.Y)
    {
        if (start.X > end.X)
        {
            for (int i = end.X + 1; i < start.X; i++)
            {
                if (table[i][start.Y] != ' ') return false;
            }
        }
        if (start.X < end.X)
        {
            for (int i = start.X + 1; i < end.X; i++)
            {
                if (table[i][start.Y] != ' ') return false;
            }
        }
        return true;
    }
    return false;
}

bool LCheck(COORD start, COORD end, char** table)
{
    COORD corner;
    corner.X = start.X, corner.Y = end.Y;
    if (ICheck(start, corner, table) && ICheck(end, corner, table) && table[corner.X][corner.Y] == ' ') return true;
    corner.X = end.X; corner.Y = start.Y;
    if (ICheck(start, corner, table) && ICheck(end, corner, table) && table[corner.X][corner.Y] == ' ') return true;
    return false;
}

bool ZCheck(COORD start, COORD end, char** table)
{
    COORD corner1, corner2;
    //check ngang
    if (start.Y > end.Y)
    {
        for (int i = end.Y + 1; i < start.Y; i++)
        {
            corner1.X = end.X; corner1.Y = i; corner2.X = start.X; corner2.Y = i;
            if (ICheck(end, corner1, table) && ICheck(corner1, corner2, table) && ICheck(corner2, start, table) && table[corner1.X][corner1.Y] == ' ' && table[corner2.X][corner2.Y] == ' ') return true;
        }
    }
    if (start.Y < end.Y)
    {
        for (int i = start.Y + 1; i < end.Y; i++)
        {
            corner1.X = start.X; corner1.Y = i; corner2.X = end.X; corner2.Y = i;
            if (ICheck(start, corner1, table) && ICheck(corner1, corner2, table) && ICheck(corner2, end, table) && table[corner1.X][corner1.Y] == ' ' && table[corner2.X][corner2.Y] == ' ') return true;
        }
    }
    //check dọc
    if (start.X > end.X)
    {
        for (int i = end.X + 1; i < start.X; i++)
        {
            corner1.X = i; corner1.Y = end.Y; corner2.X = i; corner2.Y = start.Y;
            if (ICheck(end, corner1, table) && ICheck(corner1, corner2, table) && ICheck(corner2, start, table) && table[corner1.X][corner1.Y] == ' ' && table[corner2.X][corner2.Y] == ' ') return true;
        }
    }
    if (start.X < end.X)
    {
        for (int i = start.X + 1; i < end.X; i++)
        {
            corner1.X = i; corner1.Y = start.Y; corner2.X = i; corner2.Y = end.Y;
            if (ICheck(start, corner1, table) && ICheck(corner1, corner2, table) && ICheck(corner2, end, table) && table[corner1.X][corner1.Y] == ' ' && table[corner2.X][corner2.Y] == ' ') return true;
        }
    }
    return false;
}

bool UCheck(COORD start, COORD end, char** table, const int ROWS, const int COLS)
{
    COORD corner1, corner2;
    //check start ở biên
    if (start.X == 0)
    {
        corner1.X = 0; corner1.Y = end.Y;
        if (ICheck(end, corner1, table) && table[corner1.X][corner1.Y] == ' ') return true;
    }
    if (start.X == ROWS - 1)
    {
        corner1.X = ROWS - 1; corner1.Y = end.Y;
        if (ICheck(end, corner1, table) && table[corner1.X][corner1.Y] == ' ') return true;
    }
    if (start.Y == 0)
    {
        corner1.X = end.X; corner1.Y = 0;
        if (ICheck(end, corner1, table) && table[corner1.X][corner1.Y] == ' ') return true;
    }
    if (start.Y == COLS - 1)
    {
        corner1.X = end.X; corner1.Y = COLS - 1;
        if (ICheck(end, corner1, table) && table[corner1.X][corner1.Y] == ' ') return true;
    }
    //check end ở biên
    if (end.X == 0)
    {
        corner1.X = 0; corner1.Y = start.Y;
        if (ICheck(start, corner1, table) && table[corner1.X][corner1.Y] == ' ') return true;
    }
    if (end.X == ROWS - 1)
    {
        corner1.X = ROWS - 1; corner1.Y = start.Y;
        if (ICheck(start, corner1, table) && table[corner1.X][corner1.Y] == ' ') return true;
    }
    if (end.Y == 0)
    {
        corner1.X = start.X; corner1.Y = 0;
        if (ICheck(start, corner1, table) && table[corner1.X][corner1.Y] == ' ') return true;
    }
    if (end.Y == COLS - 1)
    {
        corner1.X = start.X; corner1.Y = COLS - 1;
        if (ICheck(start, corner1, table) && table[corner1.X][corner1.Y] == ' ') return true;
    }
    //check ngang
    corner1.X = start.X; corner1.Y = 0; corner2.X = end.X; corner2.Y = 0;
    if (ICheck(start, corner1, table) && ICheck(corner2, end, table) && table[corner1.X][corner1.Y] == ' ' && table[corner2.X][corner2.Y] == ' ') return true;
    corner1.Y = COLS - 1; corner2.Y = COLS - 1;
    if (ICheck(start, corner1, table) && ICheck(corner2, end, table) && table[corner1.X][corner1.Y] == ' ' && table[corner2.X][corner2.Y] == ' ') return true;
    if (start.Y > end.Y)
    {
        for (int i = 0; i < end.Y; i++)
        {
            corner1.X = end.X; corner1.Y = i; corner2.X = start.X; corner2.Y = i;
            if (ICheck(end, corner1, table) && ICheck(corner1, corner2, table) && ICheck(corner2, start, table) && table[corner1.X][corner1.Y] == ' ' && table[corner2.X][corner2.Y] == ' ') return true;
        }
        for (int i = start.Y + 1; i < COLS; i++)
        {
            corner1.X = end.X; corner1.Y = i; corner2.X = start.X; corner2.Y = i;
            if (ICheck(end, corner1, table) && ICheck(corner1, corner2, table) && ICheck(corner2, start, table) && table[corner1.X][corner1.Y] == ' ' && table[corner2.X][corner2.Y] == ' ') return true;
        }
    }
    if (start.Y < end.Y)
    {
        for (int i = 0; i < start.Y; i++)
        {
            corner1.X = end.X; corner1.Y = i; corner2.X = start.X; corner2.Y = i;
            if (ICheck(end, corner1, table) && ICheck(corner1, corner2, table) && ICheck(corner2, start, table) && table[corner1.X][corner1.Y] == ' ' && table[corner2.X][corner2.Y] == ' ') return true;
        }
        for (int i = end.Y + 1; i < COLS; i++)
        {
            corner1.X = end.X; corner1.Y = i; corner2.X = start.X; corner2.Y = i;
            if (ICheck(end, corner1, table) && ICheck(corner1, corner2, table) && ICheck(corner2, start, table) && table[corner1.X][corner1.Y] == ' ' && table[corner2.X][corner2.Y] == ' ') return true;
        }
    }
    //check dọc
    corner1.X = 0; corner1.Y = start.Y; corner2.X = 0; corner2.Y = end.Y;
    if (ICheck(start, corner1, table) && ICheck(corner2, end, table) && table[corner1.X][corner1.Y] == ' ' && table[corner2.X][corner2.Y] == ' ') return true;
    corner1.Y = ROWS - 1; corner2.Y = ROWS - 1;
    if (ICheck(start, corner1, table) && ICheck(corner2, end, table) && table[corner1.X][corner1.Y] == ' ' && table[corner2.X][corner2.Y] == ' ') return true;
    if (start.X > end.X)
    {
        for (int i = 0; i < end.X; i++)
        {
            corner1.X = i; corner1.Y = end.Y; corner2.X = i; corner2.Y = start.Y;
            if (ICheck(end, corner1, table) && ICheck(corner1, corner2, table) && ICheck(corner2, start, table) && table[corner1.X][corner1.Y] == ' ' && table[corner2.X][corner2.Y] == ' ') return true;
        }
        for (int i = start.X + 1; i < COLS; i++)
        {
            corner1.X = i; corner1.Y = end.Y; corner2.X = i; corner2.Y = start.Y;
            if (ICheck(end, corner1, table) && ICheck(corner1, corner2, table) && ICheck(corner2, start, table) && table[corner1.X][corner1.Y] == ' ' && table[corner2.X][corner2.Y] == ' ') return true;
        }
    }
    if (start.X < end.X)
    {
        for (int i = 0; i < start.X; i++)
        {
            corner1.X = i; corner1.Y = end.Y; corner2.X = i; corner2.Y = start.Y;
            if (ICheck(end, corner1, table) && ICheck(corner1, corner2, table) && ICheck(corner2, start, table) && table[corner1.X][corner1.Y] == ' ' && table[corner2.X][corner2.Y] == ' ') return true;
        }
        for (int i = end.X + 1; i < COLS; i++)
        {
            corner1.X = i; corner1.Y = end.Y; corner2.X = i; corner2.Y = start.Y;
            if (ICheck(end, corner1, table) && ICheck(corner1, corner2, table) && ICheck(corner2, start, table) && table[corner1.X][corner1.Y] == ' ' && table[corner2.X][corner2.Y] == ' ') return true;
        }
    }
    return false;
}

