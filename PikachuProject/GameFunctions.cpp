#include "Functions.h"
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

void undoHighlighted(int curX, int curY, char** table, int cordX, int cordY)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    gotoxy(curX - 3, curY - 1);
    cout << "       " << endl;
    gotoxy(curX - 3, curY);
    cout << "   " << table[cordX][cordY] << "   " << endl;
    gotoxy(curX - 3, curY + 1);
    cout << "       ";
}

int randomInt()
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distr(65, 90);
    return distr(gen);
} 

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

void printTableV2(char** table, const int ROWS, const int COLS, int curX, int curY, char** bg) //ref https://cplusplus.com/forum/beginner/248878/
{
    //print table
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            gotoxy(curX + 4 + j * 8, curY + 2 + i * 4);
            cout << table[i][j];
            if (j != COLS - 1)
            {
                if (table[i][j] != ' ' || table[i][j + 1] != ' ')
                {
                    gotoxy(curX + 4 + j * 8 + 4, curY + 2 + i * 4 - 1); cout << char(179);
                    gotoxy(curX + 4 + j * 8 + 4, curY + 2 + i * 4); cout << char(179);
                    gotoxy(curX + 4 + j * 8 + 4, curY + 2 + i * 4 + 1); cout << char(179);
                }
            }
            if (i != ROWS - 1)
            {
                if (table[i][j] != ' ' || table[i + 1][j] != ' ')
                {
                    if (j == COLS - 1)
                    {
                        gotoxy(curX + 8 * j + 1, curY + 4 * (i + 1));
                        for (int k = 0; k < 7; k++)
                        {
                            cout << char(196);
                        }
                    }
                    else
                    {
                        gotoxy(curX + 8 * j + 1, curY + 4 * (i + 1));
                        for (int k = 0; k < 7; k++)
                        {
                            cout << char(196);
                        }
                    }
                }
            }
        }
    }
    //print border clockwise
    gotoxy(curX, curY);
    cout << char(201);
    for (int i = 1; i < 8 * COLS; i++)
    {
        cout << char(205);
    }
    cout << char(187);
    for (int i = 1; i < 4 * ROWS; i++)
    {
        gotoxy(curX, curY + i);
        cout << char(186);
        gotoxy(curX + 8 * COLS, curY + i);
        cout << char(186);
    }
    gotoxy(curX, curY + 4 * ROWS);
    cout << char(200);
    for (int i = 1; i < 8 * COLS; i++)
    {
        cout << char(205);
    }
    cout << char(188);
    displayBackground(table, ROWS, COLS, curX, curY, bg);
}

void printScreen(char** table, const int ROWS, const int COLS, string user, string stages, int cordX, int cordY, char** bg)
{
    gotoxy(0, 0);
    cout << "\n\n\nUsername: " << user << endl << "Stage: " << stages << endl << "Press h for Help (might be punish when in ASIAN)" << endl
        << "Press x to exit" << endl << "Your progress will ONLY be save when you clear the board! ";
    gotoxy(cordX, cordY);
    printTableV2(table, ROWS, COLS, cordX, cordY, bg);
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
    for (int i = 0; i < ROWS * COLS - 1; i++)
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

//path check
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
            return true;
        }
        if (start.Y < end.Y)
        {
            for (int i = start.Y + 1; i < end.Y; i++)
            {
                if (table[start.X][i] != ' ') return false;
            }
            return true;
        }
    }
    if (start.Y == end.Y)
    {
        if (start.X > end.X)
        {
            for (int i = end.X + 1; i < start.X; i++)
            {
                if (table[i][start.Y] != ' ') return false;
            }
            return true;
        }
        if (start.X < end.X)
        {
            for (int i = start.X + 1; i < end.X; i++)
            {
                if (table[i][start.Y] != ' ') return false;
            }
            return true;
        }
    }
    return false;
}

bool LCheck(COORD start, COORD end, char** table, int cordX, int cordY)
{
    COORD corner;
    corner.X = start.X, corner.Y = end.Y;
    if (ICheck(start, corner, table) && ICheck(end, corner, table) && table[corner.X][corner.Y] == ' ')
    {
        pathI(start, corner, cordX, cordY);
        pathI(end, corner, cordX, cordY);
        pathCorner(start, corner, end, cordX, cordY);
        return true;
    }
    corner.X = end.X; corner.Y = start.Y;
    if (ICheck(start, corner, table) && ICheck(end, corner, table) && table[corner.X][corner.Y] == ' ')
    {
        pathI(start, corner, cordX, cordY);
        pathI(end, corner, cordX, cordY);
        pathCorner(start, corner, end, cordX, cordY);
        return true;
    }
    return false;
}

bool ZCheck(COORD start, COORD end, char** table, int cordX, int cordY)
{
    COORD corner1, corner2;
    //check ngang
    if (start.Y > end.Y)
    {
        for (int i = end.Y + 1; i < start.Y; i++)
        {
            corner1.X = end.X; corner1.Y = i; corner2.X = start.X; corner2.Y = i;
            if (ICheck(end, corner1, table) && ICheck(corner1, corner2, table) && ICheck(corner2, start, table) && table[corner1.X][corner1.Y] == ' ' && table[corner2.X][corner2.Y] == ' ')
            {
                pathI(start, corner2, cordX, cordY);
                pathI(end, corner1, cordX, cordY);
                pathI(corner2, corner1, cordX, cordY);
                pathCorner(start, corner2, corner1, cordX, cordY);
                pathCorner(corner2, corner1, end, cordX, cordY);
                return true;
            }
        }
    }
    if (start.Y < end.Y)
    {
        for (int i = start.Y + 1; i < end.Y; i++)
        {
            corner1.X = start.X; corner1.Y = i; corner2.X = end.X; corner2.Y = i;
            if (ICheck(start, corner1, table) && ICheck(corner1, corner2, table) && ICheck(corner2, end, table) && table[corner1.X][corner1.Y] == ' ' && table[corner2.X][corner2.Y] == ' ')
            {
                pathI(start, corner1, cordX, cordY);
                pathI(end, corner2, cordX, cordY);
                pathI(corner2, corner1, cordX, cordY);
                pathCorner(start, corner1, corner2, cordX, cordY);
                pathCorner(corner1, corner2, end, cordX, cordY);
                return true;
            }
        }
    }
    //check dọc
    if (start.X > end.X)
    {
        for (int i = end.X + 1; i < start.X; i++)
        {
            corner1.X = i; corner1.Y = end.Y; corner2.X = i; corner2.Y = start.Y;
            if (ICheck(end, corner1, table) && ICheck(corner1, corner2, table) && ICheck(corner2, start, table) && table[corner1.X][corner1.Y] == ' ' && table[corner2.X][corner2.Y] == ' ')
            {
                pathI(start, corner2, cordX, cordY);
                pathI(end, corner1, cordX, cordY);
                pathI(corner2, corner1, cordX, cordY);
                pathCorner(start, corner2, corner1, cordX, cordY);
                pathCorner(corner2, corner1, end, cordX, cordY);
                return true;
            }
        }
    }
    if (start.X < end.X)
    {
        for (int i = start.X + 1; i < end.X; i++)
        {
            corner1.X = i; corner1.Y = start.Y; corner2.X = i; corner2.Y = end.Y;
            if (ICheck(start, corner1, table) && ICheck(corner1, corner2, table) && ICheck(corner2, end, table) && table[corner1.X][corner1.Y] == ' ' && table[corner2.X][corner2.Y] == ' ')
            {
                pathI(start, corner1, cordX, cordY);
                pathI(end, corner2, cordX, cordY);
                pathI(corner2, corner1, cordX, cordY);
                pathCorner(start, corner1, corner2, cordX, cordY);
                pathCorner(corner1, corner2, end, cordX, cordY);
                return true;
            }
        }
    }
    return false;
}

bool validCheck(COORD corner, const int ROWS, const int COLS)
{
    return corner.X >= 0 && corner.X < ROWS && corner.Y >= 0 && corner.Y < COLS;
}

bool UCheck(COORD start, COORD end, char** table, const int ROWS, const int COLS, int cordX, int cordY)
{
    COORD corner1, corner2;
    //check start ở biên
    if (start.X == 0)
    {
        corner1.X = 0; corner1.Y = end.Y;
        if (validCheck(corner1, ROWS, COLS))
        {
            if (ICheck(end, corner1, table) && table[corner1.X][corner1.Y] == ' ')
            {
                marginPath(start, corner1, ROWS, COLS, cordX, cordY);
                corner1.X--;
                pathI(corner1, end, cordX, cordY);
                return true;
            }
        }
    }
    if (start.X == ROWS - 1)
    {
        corner1.X = ROWS - 1; corner1.Y = end.Y;
        if (validCheck(corner1, ROWS, COLS))
        {
            if (ICheck(end, corner1, table) && table[corner1.X][corner1.Y] == ' ')
            {
                marginPath(start, corner1, ROWS, COLS, cordX, cordY);
                corner1.X++;
                pathI(corner1, end, cordX, cordY);
                return true;
            }
        }
    }
    if (start.Y == 0)
    {
        corner1.X = end.X; corner1.Y = 0;
        if (validCheck(corner1, ROWS, COLS))
        {
            if (ICheck(end, corner1, table) && table[corner1.X][corner1.Y] == ' ')
            {
                marginPath(start, corner1, ROWS, COLS, cordX, cordY);
                corner1.Y--;
                pathI(corner1, end, cordX, cordY);
                return true;
            }
        }
    }
    if (start.Y == COLS - 1)
    {
        corner1.X = end.X; corner1.Y = COLS - 1;
        if (validCheck(corner1, ROWS, COLS))
        {
            if (ICheck(end, corner1, table) && table[corner1.X][corner1.Y] == ' ')
            {
                marginPath(start, corner1, ROWS, COLS, cordX, cordY);
                corner1.Y++;
                pathI(corner1, end, cordX, cordY);
                return true;
            }
        }
    }
    //check end ở biên
    if (end.X == 0)
    {
        corner1.X = 0; corner1.Y = start.Y;
        if (validCheck(corner1, ROWS, COLS))
        {
            if (ICheck(start, corner1, table) && table[corner1.X][corner1.Y] == ' ')
            {
                marginPath(end, corner1, ROWS, COLS, cordX, cordY);
                corner1.X--;
                pathI(corner1, start, cordX, cordY);
                return true;
            }
        }
    }
    if (end.X == ROWS - 1)
    {
        corner1.X = ROWS - 1; corner1.Y = start.Y;
        if (validCheck(corner1, ROWS, COLS))
        {
            if (ICheck(start, corner1, table) && table[corner1.X][corner1.Y] == ' ')
            {
                marginPath(end, corner1, ROWS, COLS, cordX, cordY);
                corner1.X++;
                pathI(corner1, start, cordX, cordY);
                return true;
            }
        }
    }
    if (end.Y == 0)
    {
        corner1.X = start.X; corner1.Y = 0;
        if (validCheck(corner1, ROWS, COLS))
        {
            if (ICheck(start, corner1, table) && table[corner1.X][corner1.Y] == ' ')
            {
                marginPath(end, corner1, ROWS, COLS, cordX, cordY);
                corner1.Y--;
                pathI(corner1, start, cordX, cordY);
                return true;
            }
        }
    }
    if (end.Y == COLS - 1)
    {
        corner1.X = start.X; corner1.Y = COLS - 1;
        if (validCheck(corner1, ROWS, COLS))
        {
            if (ICheck(start, corner1, table) && table[corner1.X][corner1.Y] == ' ')
            {
                marginPath(end, corner1, ROWS, COLS, cordX, cordY);
                corner1.Y++;
                pathI(corner1, start, cordX, cordY);
                return true;
            }
        }
    }
    //check ngang
    corner1.X = start.X; corner1.Y = 0; corner2.X = end.X; corner2.Y = 0;
    //check U ngang
    if (start.Y >= end.Y)
    {
        for (int i = 0; i < end.Y; i++)
        {
            corner1.X = end.X; corner1.Y = i; corner2.X = start.X; corner2.Y = i;
            if (validCheck(corner1, ROWS, COLS) && validCheck(corner2, ROWS, COLS))
            {
                if (ICheck(end, corner1, table) && ICheck(corner1, corner2, table) && ICheck(corner2, start, table) && table[corner1.X][corner1.Y] == ' ' && table[corner2.X][corner2.Y] == ' ')
                {
                    pathI(end, corner1, cordX, cordY);
                    pathCorner(end, corner1, corner2, cordX, cordY);
                    pathI(corner1, corner2, cordX, cordY);
                    pathCorner(corner1, corner2, start, cordX, cordY);
                    pathI(corner2, start, cordX, cordY);
                    return true;
                }
            }
        }
        for (int i = start.Y + 1; i < COLS; i++)
        {
            corner1.X = end.X; corner1.Y = i; corner2.X = start.X; corner2.Y = i;
            if (validCheck(corner1, ROWS, COLS) && validCheck(corner2, ROWS, COLS))
            {
                if (ICheck(end, corner1, table) && ICheck(corner1, corner2, table) && ICheck(corner2, start, table) && table[corner1.X][corner1.Y] == ' ' && table[corner2.X][corner2.Y] == ' ')
                {
                    pathI(end, corner1, cordX, cordY);
                    pathCorner(end, corner1, corner2, cordX, cordY);
                    pathI(corner1, corner2, cordX, cordY);
                    pathCorner(corner1, corner2, start, cordX, cordY);
                    pathI(corner2, start, cordX, cordY);
                    return true;
                }
            }
        }
    }
    if (start.Y <= end.Y)
    {
        for (int i = 0; i < start.Y; i++)
        {
            corner1.X = end.X; corner1.Y = i; corner2.X = start.X; corner2.Y = i;
            if (validCheck(corner1, ROWS, COLS) && validCheck(corner2, ROWS, COLS))
            {
                if (ICheck(end, corner1, table) && ICheck(corner1, corner2, table) && ICheck(corner2, start, table) && table[corner1.X][corner1.Y] == ' ' && table[corner2.X][corner2.Y] == ' ')
                {
                    pathI(end, corner1, cordX, cordY);
                    pathCorner(end, corner1, corner2, cordX, cordY);
                    pathI(corner1, corner2, cordX, cordY);
                    pathCorner(corner1, corner2, start, cordX, cordY);
                    pathI(corner2, start, cordX, cordY);
                    return true;
                }
            }
        }
        for (int i = end.Y + 1; i < COLS; i++)
        {
            corner1.X = end.X; corner1.Y = i; corner2.X = start.X; corner2.Y = i;
            if (validCheck(corner1, ROWS, COLS) && validCheck(corner2, ROWS, COLS))
            {
                if (ICheck(end, corner1, table) && ICheck(corner1, corner2, table) && ICheck(corner2, start, table) && table[corner1.X][corner1.Y] == ' ' && table[corner2.X][corner2.Y] == ' ')
                {
                    pathI(end, corner1, cordX, cordY);
                    pathCorner(end, corner1, corner2, cordX, cordY);
                    pathI(corner1, corner2, cordX, cordY);
                    pathCorner(corner1, corner2, start, cordX, cordY);
                    pathI(corner2, start, cordX, cordY);
                    return true;
                }
            }
        }
    }
    //check start tới biên và end tới biên
    corner1.X = start.X; corner1.Y = 0; corner2.X = end.X; corner2.Y = 0;
    if (validCheck(corner1, ROWS, COLS) && validCheck(corner2, ROWS, COLS))
    {
        if (ICheck(start, corner1, table) && ICheck(corner2, end, table) && table[corner1.X][corner1.Y] == ' ' && table[corner2.X][corner2.Y] == ' ')
        {
            pathI(start, corner1, cordX, cordY);
            pathI(corner2, end, cordX, cordY);
            marginPath(corner1, corner2, ROWS, COLS, cordX, cordY);
            gotoxy(cordX + 4 + 8 * (corner1.Y), cordY + 2 + 4 * (corner1.X));
            cout << char(196);
            gotoxy(cordX + 4 + 8 * (corner2.Y), cordY + 2 + 4 * (corner2.X));
            cout << char(196);
            return true;
        }
    }
    corner1.Y = COLS - 1; corner2.Y = COLS - 1;
    if (validCheck(corner1, ROWS, COLS) && validCheck(corner2, ROWS, COLS))
    {
        if (ICheck(start, corner1, table) && ICheck(corner2, end, table) && table[corner1.X][corner1.Y] == ' ' && table[corner2.X][corner2.Y] == ' ')
        {
            pathI(start, corner1, cordX, cordY);
            pathI(corner2, end, cordX, cordY);
            marginPath(corner1, corner2, ROWS, COLS, cordX, cordY);
            gotoxy(cordX + 4 + 8 * (corner1.Y), cordY + 2 + 4 * (corner1.X));
            cout << char(196);
            gotoxy(cordX + 4 + 8 * (corner2.Y), cordY + 2 + 4 * (corner2.X));
            cout << char(196);
            return true;
        }
    }
    //check dọc
    corner1.X = 0; corner1.Y = start.Y; corner2.X = 0; corner2.Y = end.Y;
    //check U dọc
    if (start.X >= end.X)
    {
        for (int i = 0; i < end.X; i++)
        {
            corner1.X = i; corner1.Y = end.Y; corner2.X = i; corner2.Y = start.Y;
            if (validCheck(corner1, ROWS, COLS) && validCheck(corner2, ROWS, COLS))
            {
                if (ICheck(end, corner1, table) && ICheck(corner1, corner2, table) && ICheck(corner2, start, table) && table[corner1.X][corner1.Y] == ' ' && table[corner2.X][corner2.Y] == ' ')
                {
                    pathI(end, corner1, cordX, cordY);
                    pathCorner(end, corner1, corner2, cordX, cordY);
                    pathI(corner1, corner2, cordX, cordY);
                    pathCorner(corner1, corner2, start, cordX, cordY);
                    pathI(corner2, start, cordX, cordY);
                    return true;
                }
            }
        }
        for (int i = start.X + 1; i < COLS; i++)
        {
            corner1.X = i; corner1.Y = end.Y; corner2.X = i; corner2.Y = start.Y;
            if (validCheck(corner1, ROWS, COLS) && validCheck(corner2, ROWS, COLS))
            {
                if (ICheck(end, corner1, table) && ICheck(corner1, corner2, table) && ICheck(corner2, start, table) && table[corner1.X][corner1.Y] == ' ' && table[corner2.X][corner2.Y] == ' ')
                {
                    pathI(end, corner1, cordX, cordY);
                    pathCorner(end, corner1, corner2, cordX, cordY);
                    pathI(corner1, corner2, cordX, cordY);
                    pathCorner(corner1, corner2, start, cordX, cordY);
                    pathI(corner2, start, cordX, cordY);
                    return true;
                }
            }
        }
    }
    if (start.X <= end.X)
    {
        for (int i = 0; i < start.X; i++)
        {
            corner1.X = i; corner1.Y = end.Y; corner2.X = i; corner2.Y = start.Y;
            if (validCheck(corner1, ROWS, COLS) && validCheck(corner2, ROWS, COLS))
            {
                if (ICheck(end, corner1, table) && ICheck(corner1, corner2, table) && ICheck(corner2, start, table) && table[corner1.X][corner1.Y] == ' ' && table[corner2.X][corner2.Y] == ' ')
                {
                    pathI(end, corner1, cordX, cordY);
                    pathCorner(end, corner1, corner2, cordX, cordY);
                    pathI(corner1, corner2, cordX, cordY);
                    pathCorner(corner1, corner2, start, cordX, cordY);
                    pathI(corner2, start, cordX, cordY);
                    return true;
                }
            }
        }
        for (int i = end.X + 1; i < COLS; i++)
        {
            corner1.X = i; corner1.Y = end.Y; corner2.X = i; corner2.Y = start.Y;
            if (validCheck(corner1, ROWS, COLS) && validCheck(corner2, ROWS, COLS))
            {
                if (ICheck(end, corner1, table) && ICheck(corner1, corner2, table) && ICheck(corner2, start, table) && table[corner1.X][corner1.Y] == ' ' && table[corner2.X][corner2.Y] == ' ')
                {
                    pathI(end, corner1, cordX, cordY);
                    pathCorner(end, corner1, corner2, cordX, cordY);
                    pathI(corner1, corner2, cordX, cordY);
                    pathCorner(corner1, corner2, start, cordX, cordY);
                    pathI(corner2, start, cordX, cordY);
                    return true;
                }
            }
        }
    }
    //check start tới biên và end tới biên
    corner1.X = 0; corner1.Y = start.Y; corner2.X = 0; corner2.Y = end.Y;
    if (validCheck(corner1, ROWS, COLS) && validCheck(corner2, ROWS, COLS))
    {
        if (ICheck(start, corner1, table) && ICheck(corner2, end, table) && table[corner1.X][corner1.Y] == ' ' && table[corner2.X][corner2.Y] == ' ')
        {
            pathI(start, corner1, cordX, cordY);
            pathI(corner2, end, cordX, cordY);
            marginPath(corner1, corner2, ROWS, COLS, cordX, cordY);
            gotoxy(cordX + 4 + 8 * (corner1.Y), cordY + 2 + 4 * (corner1.X));
            cout << char(179);
            gotoxy(cordX + 4 + 8 * (corner2.Y), cordY + 2 + 4 * (corner2.X));
            cout << char(179);
            return true;
        }
    }
    corner1.Y = ROWS - 1; corner2.Y = ROWS - 1;
    if (validCheck(corner1, ROWS, COLS) && validCheck(corner2, ROWS, COLS))
    {
        if (ICheck(start, corner1, table) && ICheck(corner2, end, table) && table[corner1.X][corner1.Y] == ' ' && table[corner2.X][corner2.Y] == ' ')
        {
            pathI(start, corner1, cordX, cordY);
            pathI(corner2, end, cordX, cordY);
            marginPath(corner1, corner2, ROWS, COLS, cordX, cordY);
            gotoxy(cordX + 4 + 8 * (corner1.Y), cordY + 2 + 4 * (corner1.X));
            cout << char(179);
            gotoxy(cordX + 4 + 8 * (corner2.Y), cordY + 2 + 4 * (corner2.X));
            cout << char(179);
            return true;
        }
    }
    return false;
}
 //path print
void pathI(COORD start, COORD end, int cordX, int cordY)
{
    if (start.X == end.X)
    {
        if (start.Y > end.Y)
        {
            for (int i = cordX + 4 + 8 * (end.Y) + 1; i < cordX + 4 + 8 * (start.Y); i++)
            {
                gotoxy(i, cordY + 2 + 4 * (start.X));
                cout << char(196);
            }
            return;
        }
        if (start.Y < end.Y)
        {
            for (int i = cordX + 4 + 8 * (start.Y) + 1; i < cordX + 4 + 8 * (end.Y); i++)
            {
                gotoxy(i, cordY + 2 + 4 * (start.X));
                cout << char(196);
            }
            return;
        }
    }
    if (start.Y == end.Y)
    {
        if (start.X > end.X)
        {
            for (int i = cordY + 2 + 4 * (end.X) + 1; i < cordY + 2 + 4 * (start.X); i++)
            {
                gotoxy(cordX + 4 + 8 * (start.Y), i);
                cout << char(179);
            }
            return;
        }
        if (start.X < end.X)
        {
            for (int i = cordY + 2 + 4 * (start.X) + 1; i < cordY + 2 + 4 * (end.X); i++)
            {
                gotoxy(cordX + 4 + 8 * (start.Y), i);
                cout << char(179);
            }
            return;
        }
    }
}
void marginPath(COORD coord, COORD coord1, const int ROWS, const int COLS, int cordX, int cordY)
{
    if (coord.X == 0 && coord1.X == 0)
    {
        COORD corner1, corner2;
        corner1.X = coord.X - 1; corner1.Y = coord.Y;
        corner2.X = coord1.X - 1; corner2.Y = coord1.Y;
        pathI(coord, corner1, cordX, cordY);
        pathI(coord1, corner2, cordX, cordY);
        pathI(corner2, corner1, cordX, cordY);
        pathCorner(coord, corner1, corner2, cordX, cordY);
        pathCorner(corner1, corner2, coord1, cordX, cordY);
        return;
    }
    if (coord.Y == 0 && coord1.Y == 0)
    {
        COORD corner1, corner2;
        corner1.X = coord.X; corner1.Y = coord.Y - 1;
        corner2.X = coord1.X; corner2.Y = coord1.Y - 1;
        pathI(coord, corner1, cordX, cordY);
        pathI(coord1, corner2, cordX, cordY);
        pathI(corner2, corner1, cordX, cordY);
        pathCorner(coord, corner1, corner2, cordX, cordY);
        pathCorner(corner1, corner2, coord1, cordX, cordY);
        return;
    }
    if (coord.X == ROWS - 1 && coord1.X == ROWS - 1)
    {
        COORD corner1, corner2;
        corner1.X = coord.X + 1; corner1.Y = coord.Y;
        corner2.X = coord1.X + 1; corner2.Y = coord1.Y;
        pathI(coord, corner1, cordX, cordY);
        pathI(coord1, corner2, cordX, cordY);
        pathI(corner2, corner1, cordX, cordY);
        pathCorner(coord, corner1, corner2, cordX, cordY);
        pathCorner(corner1, corner2, coord1, cordX, cordY);
        return;
    }
    if (coord.Y == COLS - 1 && coord1.Y == COLS - 1)
    {
        COORD corner1, corner2;
        corner1.X = coord.X; corner1.Y = coord.Y + 1;
        corner2.X = coord1.X; corner2.Y = coord1.Y + 1;
        pathI(coord, corner1, cordX, cordY);
        pathI(coord1, corner2, cordX, cordY);
        pathI(corner2, corner1, cordX, cordY);
        pathCorner(coord, corner1, corner2, cordX, cordY);
        pathCorner(corner1, corner2, coord1, cordX, cordY);
        return;
    }
}

void pathCorner(COORD start, COORD corner, COORD end, int cordX, int cordY)
{
    for (int i = 0; i < 2; i++)
    {
        if (corner.X > start.X && corner.Y > end.Y)
        {
            gotoxy(cordX + 4 + 8 * (corner.Y), cordY + 2 + 4 * (corner.X));
            cout << char(217);
            return;
        }
        if (corner.X > start.X && corner.Y < end.Y)
        {
            gotoxy(cordX + 4 + 8 * (corner.Y), cordY + 2 + 4 * (corner.X));
            cout << char(192);
            return;
        }
        if (corner.X < start.X && corner.Y > end.Y)
        {
            gotoxy(cordX + 4 + 8 * (corner.Y), cordY + 2 + 4 * (corner.X));
            cout << char(191);
            return;
        }
        if (corner.X < start.X && corner.Y < end.Y)
        {
            gotoxy(cordX + 4 + 8 * (corner.Y), cordY + 2 + 4 * (corner.X));
            cout << char(218);
            return;
        }
        swap(start.X, end.X);
        swap(start.Y, end.Y);
    }
}

//help move
bool L_Availability(COORD start, COORD end, char** table)
{
    COORD corner;
    corner.X = start.X, corner.Y = end.Y;
    if (ICheck(start, corner, table) && ICheck(end, corner, table) && table[corner.X][corner.Y] == ' ')
    {
        return true;
    }
    corner.X = end.X; corner.Y = start.Y;
    if (ICheck(start, corner, table) && ICheck(end, corner, table) && table[corner.X][corner.Y] == ' ')
    {
        return true;
    }
    return false;
}

bool Z_Availability(COORD start, COORD end, char** table)
{
    COORD corner1, corner2;
    //check ngang
    if (start.Y > end.Y)
    {
        for (int i = end.Y + 1; i < start.Y; i++)
        {
            corner1.X = end.X; corner1.Y = i; corner2.X = start.X; corner2.Y = i;
            if (ICheck(end, corner1, table) && ICheck(corner1, corner2, table) && ICheck(corner2, start, table) && table[corner1.X][corner1.Y] == ' ' && table[corner2.X][corner2.Y] == ' ')
            {
                return true;
            }
        }
    }
    if (start.Y < end.Y)
    {
        for (int i = start.Y + 1; i < end.Y; i++)
        {
            corner1.X = start.X; corner1.Y = i; corner2.X = end.X; corner2.Y = i;
            if (ICheck(start, corner1, table) && ICheck(corner1, corner2, table) && ICheck(corner2, end, table) && table[corner1.X][corner1.Y] == ' ' && table[corner2.X][corner2.Y] == ' ')
            {
                return true;
            }
        }
    }
    //check dọc
    if (start.X > end.X)
    {
        for (int i = end.X + 1; i < start.X; i++)
        {
            corner1.X = i; corner1.Y = end.Y; corner2.X = i; corner2.Y = start.Y;
            if (ICheck(end, corner1, table) && ICheck(corner1, corner2, table) && ICheck(corner2, start, table) && table[corner1.X][corner1.Y] == ' ' && table[corner2.X][corner2.Y] == ' ')
            {
                return true;
            }
        }
    }
    if (start.X < end.X)
    {
        for (int i = start.X + 1; i < end.X; i++)
        {
            corner1.X = i; corner1.Y = start.Y; corner2.X = i; corner2.Y = end.Y;
            if (ICheck(start, corner1, table) && ICheck(corner1, corner2, table) && ICheck(corner2, end, table) && table[corner1.X][corner1.Y] == ' ' && table[corner2.X][corner2.Y] == ' ')
            {
                return true;
            }
        }
    }
    return false;
}

bool U_Availability(COORD start, COORD end, char** table, const int ROWS, const int COLS)
{
    COORD corner1, corner2;
    //check start ở biên
    if (start.X == 0)
    {
        corner1.X = 0; corner1.Y = end.Y;
        if (validCheck(corner1, ROWS, COLS))
        {
            if (ICheck(end, corner1, table) && table[corner1.X][corner1.Y] == ' ')
            {
                return true;
            }
        }
    }
    if (start.X == ROWS - 1)
    {
        corner1.X = ROWS - 1; corner1.Y = end.Y;
        if (validCheck(corner1, ROWS, COLS))
        {
            if (ICheck(end, corner1, table) && table[corner1.X][corner1.Y] == ' ')
            {
                return true;
            }
        }
    }
    if (start.Y == 0)
    {
        corner1.X = end.X; corner1.Y = 0;
        if (validCheck(corner1, ROWS, COLS))
        {
            if (ICheck(end, corner1, table) && table[corner1.X][corner1.Y] == ' ')
            {
                return true;
            }
        }
    }
    if (start.Y == COLS - 1)
    {
        corner1.X = end.X; corner1.Y = COLS - 1;
        if (validCheck(corner1, ROWS, COLS))
        {
            if (ICheck(end, corner1, table) && table[corner1.X][corner1.Y] == ' ')
            {
                return true;
            }
        }
    }
    //check end ở biên
    if (end.X == 0)
    {
        corner1.X = 0; corner1.Y = start.Y;
        if (validCheck(corner1, ROWS, COLS))
        {
            if (ICheck(start, corner1, table) && table[corner1.X][corner1.Y] == ' ')
            {
                return true;
            }
        }
    }
    if (end.X == ROWS - 1)
    {
        corner1.X = ROWS - 1; corner1.Y = start.Y;
        if (validCheck(corner1, ROWS, COLS))
        {
            if (ICheck(start, corner1, table) && table[corner1.X][corner1.Y] == ' ')
            {
                return true;
            }
        }
    }
    if (end.Y == 0)
    {
        corner1.X = start.X; corner1.Y = 0;
        if (validCheck(corner1, ROWS, COLS))
        {
            if (ICheck(start, corner1, table) && table[corner1.X][corner1.Y] == ' ')
            {
                return true;
            }
        }
    }
    if (end.Y == COLS - 1)
    {
        corner1.X = start.X; corner1.Y = COLS - 1;
        if (validCheck(corner1, ROWS, COLS))
        {
            if (ICheck(start, corner1, table) && table[corner1.X][corner1.Y] == ' ')
            {
                return true;
            }
        }
    }
    //check ngang
    corner1.X = start.X; corner1.Y = 0; corner2.X = end.X; corner2.Y = 0;
    //check U ngang
    if (start.Y >= end.Y)
    {
        for (int i = 0; i < end.Y; i++)
        {
            corner1.X = end.X; corner1.Y = i; corner2.X = start.X; corner2.Y = i;
            if (validCheck(corner1, ROWS, COLS) && validCheck(corner2, ROWS, COLS))
            {
                if (ICheck(end, corner1, table) && ICheck(corner1, corner2, table) && ICheck(corner2, start, table) && table[corner1.X][corner1.Y] == ' ' && table[corner2.X][corner2.Y] == ' ')
                {
                    return true;
                }
            }
        }
        for (int i = start.Y + 1; i < COLS; i++)
        {
            corner1.X = end.X; corner1.Y = i; corner2.X = start.X; corner2.Y = i;
            if (validCheck(corner1, ROWS, COLS) && validCheck(corner2, ROWS, COLS))
            {
                if (ICheck(end, corner1, table) && ICheck(corner1, corner2, table) && ICheck(corner2, start, table) && table[corner1.X][corner1.Y] == ' ' && table[corner2.X][corner2.Y] == ' ')
                {
                    return true;
                }
            }
        }
    }
    if (start.Y <= end.Y)
    {
        for (int i = 0; i < start.Y; i++)
        {
            corner1.X = end.X; corner1.Y = i; corner2.X = start.X; corner2.Y = i;
            if (validCheck(corner1, ROWS, COLS) && validCheck(corner2, ROWS, COLS))
            {
                if (ICheck(end, corner1, table) && ICheck(corner1, corner2, table) && ICheck(corner2, start, table) && table[corner1.X][corner1.Y] == ' ' && table[corner2.X][corner2.Y] == ' ')
                {
                    return true;
                }
            }
        }
        for (int i = end.Y + 1; i < COLS; i++)
        {
            corner1.X = end.X; corner1.Y = i; corner2.X = start.X; corner2.Y = i;
            if (validCheck(corner1, ROWS, COLS) && validCheck(corner2, ROWS, COLS))
            {
                if (ICheck(end, corner1, table) && ICheck(corner1, corner2, table) && ICheck(corner2, start, table) && table[corner1.X][corner1.Y] == ' ' && table[corner2.X][corner2.Y] == ' ')
                {
                    return true;
                }
            }
        }
    }
    //check start tới biên và end tới biên
    corner1.X = start.X; corner1.Y = 0; corner2.X = end.X; corner2.Y = 0;
    if (validCheck(corner1, ROWS, COLS) && validCheck(corner2, ROWS, COLS))
    {
        if (ICheck(start, corner1, table) && ICheck(corner2, end, table) && table[corner1.X][corner1.Y] == ' ' && table[corner2.X][corner2.Y] == ' ')
        {
            return true;
        }
    }
    corner1.Y = COLS - 1; corner2.Y = COLS - 1;
    if (validCheck(corner1, ROWS, COLS) && validCheck(corner2, ROWS, COLS))
    {
        if (ICheck(start, corner1, table) && ICheck(corner2, end, table) && table[corner1.X][corner1.Y] == ' ' && table[corner2.X][corner2.Y] == ' ')
        {
            return true;
        }
    }
    //check dọc
    corner1.X = 0; corner1.Y = start.Y; corner2.X = 0; corner2.Y = end.Y;
    //check U dọc
    if (start.X >= end.X)
    {
        for (int i = 0; i < end.X; i++)
        {
            corner1.X = i; corner1.Y = end.Y; corner2.X = i; corner2.Y = start.Y;
            if (validCheck(corner1, ROWS, COLS) && validCheck(corner2, ROWS, COLS))
            {
                if (ICheck(end, corner1, table) && ICheck(corner1, corner2, table) && ICheck(corner2, start, table) && table[corner1.X][corner1.Y] == ' ' && table[corner2.X][corner2.Y] == ' ')
                {
                    return true;
                }
            }
        }
        for (int i = start.X + 1; i < COLS; i++)
        {
            corner1.X = i; corner1.Y = end.Y; corner2.X = i; corner2.Y = start.Y;
            if (validCheck(corner1, ROWS, COLS) && validCheck(corner2, ROWS, COLS))
            {
                if (ICheck(end, corner1, table) && ICheck(corner1, corner2, table) && ICheck(corner2, start, table) && table[corner1.X][corner1.Y] == ' ' && table[corner2.X][corner2.Y] == ' ')
                {
                    return true;
                }
            }
        }
    }
    if (start.X <= end.X)
    {
        for (int i = 0; i < start.X; i++)
        {
            corner1.X = i; corner1.Y = end.Y; corner2.X = i; corner2.Y = start.Y;
            if (validCheck(corner1, ROWS, COLS) && validCheck(corner2, ROWS, COLS))
            {
                if (ICheck(end, corner1, table) && ICheck(corner1, corner2, table) && ICheck(corner2, start, table) && table[corner1.X][corner1.Y] == ' ' && table[corner2.X][corner2.Y] == ' ')
                {
                    return true;
                }
            }
        }
        for (int i = end.X + 1; i < COLS; i++)
        {
            corner1.X = i; corner1.Y = end.Y; corner2.X = i; corner2.Y = start.Y;
            if (validCheck(corner1, ROWS, COLS) && validCheck(corner2, ROWS, COLS))
            {
                if (ICheck(end, corner1, table) && ICheck(corner1, corner2, table) && ICheck(corner2, start, table) && table[corner1.X][corner1.Y] == ' ' && table[corner2.X][corner2.Y] == ' ')
                {
                    return true;
                }
            }
        }
    }
    //check start tới biên và end tới biên
    corner1.X = 0; corner1.Y = start.Y; corner2.X = 0; corner2.Y = end.Y;
    if (validCheck(corner1, ROWS, COLS) && validCheck(corner2, ROWS, COLS))
    {
        if (ICheck(start, corner1, table) && ICheck(corner2, end, table) && table[corner1.X][corner1.Y] == ' ' && table[corner2.X][corner2.Y] == ' ')
        {
            return true;
        }
    }
    corner1.Y = ROWS - 1; corner2.Y = ROWS - 1;
    if (validCheck(corner1, ROWS, COLS) && validCheck(corner2, ROWS, COLS))
    {
        if (ICheck(start, corner1, table) && ICheck(corner2, end, table) && table[corner1.X][corner1.Y] == ' ' && table[corner2.X][corner2.Y] == ' ')
        {
            return true;
        }
    }
    return false;
}

bool moveAvailability(char** table, const int ROWS, const int COLS)
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            for (int a = 0; a < ROWS; a++)
            {
                for (int b = 0; b < COLS; b++)
                {
                    if (table[i][j] == table[a][b] && table[i][j] != ' ')
                    {
                        if (i == a && j == b)
                        {
                            continue;
                        }
                        COORD coord, coord1;
                        coord.X = i; coord.Y = j; coord1.X = a; coord1.Y = b;
                        if (ICheck(coord, coord1, table))
                        {
                            return true;
                        }
                        else if (i == 0 && a == 0 || i == ROWS - 1 && a == ROWS - 1 || j == 0 && b == 0 || j == COLS - 1 && b == COLS - 1)
                        {
                            return true;
                        }
                        else if (L_Availability(coord, coord1, table))
                        {
                            return true;
                        }
                        else if (Z_Availability(coord, coord1, table))
                        {
                            return true;
                        }
                        else if (U_Availability(coord, coord1, table, ROWS, COLS))
                        {
                            return true;
                        }
                    }
                }
            }
        }
    }
    return false;
}

int Help(char** table,const int ROWS, const int COLS, int DifX,int DifY)
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            for (int a = 0; a < ROWS; a++)
            {
                for (int b = 0; b < COLS; b++)
                {
                    if (table[i][j] == table[a][b] && table[i][j] != ' ')
                    {
                        if (i == a && j == b)
                        {
                            continue;
                        }
                        COORD coord, coord1;
                        coord.X = i; coord.Y = j; coord1.X = a; coord1.Y = b;
                        int curX = DifY + 2 + 4 * j, curY = DifX + 4 + 8 * i, cur1X = DifY + 2 + 4 * b, cur1Y = DifX + 4 + 8 * a;
                        if (ICheck(coord, coord1, table))
                        {
                            pathI(coord, coord1, DifX, DifY);
                            Sleep(1000);
                            return 1;
                        }
                        else if (i == 0 && a == 0 || i == ROWS - 1 && a == ROWS - 1 || j == 0 && b == 0 || j == COLS - 1 && b == COLS - 1)
                        {
                            marginPath(coord, coord1, ROWS, COLS, DifX, DifY);
                            Sleep(1000);
                            return 1;
                        }
                        else if (LCheck(coord, coord1, table, DifX, DifY))
                        {
                            Sleep(1000);
                            return 1;
                        }
                        else if (ZCheck(coord, coord1, table, DifX, DifY))
                        {
                            Sleep(1000);
                            return 1;
                        }
                        else if (UCheck(coord, coord1, table, ROWS, COLS, DifX, DifY))
                        {
                            Sleep(1000);
                            return 1;
                        }
                    }
                }
            }
        }
    }
    return 0;
}

//ASIAN Difficulty
void swapChar(char &a, char &b)
{
    char temp = a;
    a = b;
    b = temp;
}
void asianDif(char** &table, const int ROWS, const int COLS)
{
    for (int j = 0; j < COLS; j++)
    {
        for (int i = 0; i < ROWS - 1; i++)
        {
            if (table[i][j] != ' ' && table[i + 1][j] == ' ')
            {
                swapChar(table[i][j], table[i + 1][j]);
                i = -1;
            }
        }
    }
}

//timer
