#include "Funcs.h"
#include <iostream>

#include <windows.h>
#pragma comment (lib,"Winmm.lib")
using namespace std;


void ShowConsoleCursor(bool showFlag) //hide cursor ref:https://stackoverflow.com/questions/18028808/remove-blinking-underscore-on-console-cmd-prompt
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO     cursorInfo;

    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag; // set the cursor visibility
    SetConsoleCursorInfo(out, &cursorInfo);
}

void playBG(bool flag)
{
    mciSendString(L" open \"music\\BG.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
    if (flag)
    {
        mciSendString(L"setaudio mp3 volume to 250", NULL, 0, NULL);
        mciSendString(L"play mp3 repeat", NULL, 0, NULL);
    }
    if (!flag)
    {
        mciSendString(L"close mp3", NULL, 0, NULL);
    }
}