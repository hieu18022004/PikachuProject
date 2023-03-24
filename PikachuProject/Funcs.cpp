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
    bool** mapCheck = new bool* [ROWS];
    for (int i = 0; i < ROWS + 2; i++)
    {
        mapCheck[i] = new bool[COLS];
    }
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            mapCheck[i][j] = false;
        }
    }
    return mapCheck;
}

bool validMove(COORD n, bool** mapCheck, const int ROWS, const int COLS)
{
    if (n.X >= 0 && n.X < ROWS && n.Y >= 0 && n.Y < COLS)
    {
        if (mapCheck[n.X][n.Y] == true)
            return true;
    }
    return false;
}
bool pathCheck(COORD start, COORD end, bool** mapCheck, const int ROWS, const int COLS)
{
    COORD cur = start;
    List turn;
    headPush(turn, cur.X, cur.Y);
    while (emptyCheck(turn) == false)
    {

    }

}


void removeNonAdjacentMatch(char** board, int row, int col) 
{
    // Duyệt toàn bộ bảng và kiểm tra từng cặp ô
    for (int i = 0; i < row; i++) 
    {
        for (int j = 0; j < col; j++) 
        {
            if (board[i][j] != ' ') 
            {
                // Nếu ô chưa được loại bỏ, thực hiện DFS để tìm các ô kề nhau
                char c = board[i][j];
                board[i][j] = ' ';
                dfs(board, row, col, i, j, c);
            }
        }
    }
}

void dfs(char** board, int row, int col, int i, int j, char c) {
    // Duyệt các ô kề nhau
    if (i > 0 && board[i - 1][j] == c) {
        board[i - 1][j] = ' ';
        dfs(board, row, col, i - 1, j, c);
    }
    if (j > 0 && board[i][j - 1] == c) {
        board[i][j - 1] = ' ';
        dfs(board, row, col, i, j - 1, c);
    }
    if (i < row - 1 && board[i + 1][j] == c) {
        board[i + 1][j] = ' ';
        dfs(board, row, col, i + 1, j, c);
    }
    if (j < col - 1 && board[i][j + 1] == c) {
        board[i][j + 1] = ' ';
        dfs(board, row, col, i, j + 1, c);
    }
}



