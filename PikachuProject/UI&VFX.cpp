#include "Functions.h"
using namespace std;

//whether or not displaying the console cursor
void ShowConsoleCursor(bool showFlag) //hide cursor ref:https://stackoverflow.com/questions/18028808/remove-blinking-underscore-on-console-cmd-prompt
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO     cursorInfo;

    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag; // set the cursor visibility
    SetConsoleCursorInfo(out, &cursorInfo);
}
//play normal background music
void playBG(bool flag)
{
    mciSendString(TEXT(" open \"music\\BG.mp3\" type mpegvideo alias mp3"), NULL, 0, NULL);
    if (flag)
    {
        mciSendString(TEXT("setaudio mp3 volume to 250"), NULL, 0, NULL);
        mciSendString(TEXT("play mp3 repeat"), NULL, 0, NULL);
    }
    if (!flag)
    {
        mciSendString(TEXT("close mp3"), NULL, 0, NULL);
    }
}
//play asian mode's background music
void playBGAsian(bool flag)
{
    mciSendString(TEXT(" open \"music\\asian.mp3\" type mpegvideo alias mp3"), NULL, 0, NULL);
    if (flag)
    {
        mciSendString(TEXT("setaudio mp3 volume to 250"), NULL, 0, NULL);
        mciSendString(TEXT("play mp3 repeat"), NULL, 0, NULL);
    }
    if (!flag)
    {
        mciSendString(TEXT("close mp3"), NULL, 0, NULL);
    }
}
//play the sound when successfully match a pair
void matchMusic()
{
    mciSendString(TEXT(" open \"music\\match.mp3\" type mpegvideo alias match"), NULL, 0, NULL);
    mciSendString(TEXT("setaudio match volume to 1000"), NULL, 0, NULL);
    mciSendString(TEXT("play match wait"), NULL, 0, NULL);
    mciSendString(TEXT("close match"), NULL, 0, NULL);
}
//play the sound when you select an item in menu
void selectMusic()
{
    mciSendString(TEXT(" open \"music\\select.mp3\" type mpegvideo alias select"), NULL, 0, NULL);
    mciSendString(TEXT("setaudio select volume to 1000"), NULL, 0, NULL);
    mciSendString(TEXT("play select wait"), NULL, 0, NULL);
    mciSendString(TEXT("close select"), NULL, 0, NULL);
}
//play music when a player finishes the game
void gameFinishMusic()
{
    playBG(false);
    mciSendString(TEXT(" open \"music\\endgame.mp3\" type mpegvideo alias endgame"), NULL, 0, NULL);
    mciSendString(TEXT("setaudio endgame volume to 1000"), NULL, 0, NULL);
    mciSendString(TEXT("play endgame wait"), NULL, 0, NULL);
    mciSendString(TEXT("close endgame"), NULL, 0, NULL);
    playBG(true);
}
//play music when a game start
void roundstartMusic()
{
    playBG(false);
    mciSendString(TEXT(" open \"music\\roundstart.mp3\" type mpegvideo alias start"), NULL, 0, NULL);
    mciSendString(TEXT("setaudio start volume to 1000"), NULL, 0, NULL);
    mciSendString(TEXT("play start wait"), NULL, 0, NULL);
    mciSendString(TEXT("close start"), NULL, 0, NULL);
    playBG(true);
}
//print the mascots
void printCharizardMascot()
{
    gotoxy(0, 0);
    cout << "\n\n\n\n\n\n\n\n\n";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
    cout << R"(
                 ."-,.__
                 `.     `.  ,
              .--'  .._,'"-' `.
             .    .'         `'
             `.   /          ,'
               `  '--.   ,-"'
                `"`   |  \
                   -. \, |
                    `--Y.'      ___.
                         \     L._, \
               _.,        `.   <  <\                _
             ,' '           `, `.   | \            ( `
          ../, `.            `  |    .\`.           \ \_
         ,' ,..  .           _.,'    ||\l            )  '".
        , ,'   \           ,'.-.`-._,'  |           .  _._`.
      ,' /      \ \        `' ' `--/   | \          / /   ..\
    .'  /        \ .         |\__ - _ ,'` `        / /     `.`.
    |  '          ..         `-...-"  |  `-'      / /        . `.
    | /           |L__           |    |          / /          `. `.
   , /            .   .          |    |         / /             ` `
  / /          ,. ,`._ `-_       |    |  _   ,-' /               ` \
 / .           \"`_/. `-_ \_,.  ,'    +-' `-'  _,        ..,-.    \`.
.  '         .-f    ,'   `    '.       \__.---'     _   .'   '     \ \
' /          `.'    l     .' /          \..      ,_|/   `.  ,'`     L`
|'      _.-""` `.    \ _,'  `            \ `.___`.'"`-.  , |   |    | \
||    ,'      `. `.   '       _,...._        `  |    `/ '  |   '     .|
||  ,'          `. ;.,.---' ,'       `.   `.. `-'  .-' /_ .'    ;_   ||
|| '              V      / /           `   | `   ,'   ,' '.    !  `. ||
||/            _,-------7 '              . |  `-'    l         /    `||
. |          ,' .-   ,' ||               | .-.        `.      .'     ||
 `'        ,'    `".'    |               |    `.        '. -.'       `'
          /      ,'      |               |,'    \-.._,.'/'
          .     /        .               .       \    .''
        .`.    |         `.             /         :_,'.'
          \ `...\   _     ,'-.        .'         /_.-'
           `-.__ `,  `'   .  _.>----''.  _  __  /
                .'        /"'          |  "'   '_
               /_|.-'\ ,".             '.'`__'-( \
                 / ,"'"\,'               `/  `-.|" )";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}
void printVenusaurMascot()
{
    gotoxy(0, 0);
    cout << "\n\n\n\n\n\n\n\n";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
    cout << R"(
                            _._       _,._
                        _.'   `. ' .'   _`.
                ,"""/`""-.-.,/. ` V'\-,`.,--/"""."-..
              ,'    `...,' . ,\-----._|     `.   /   \
             `.            .`  -'`"" .._   :> `-'   `.
            ,'  ,-.  _,.-'| `..___ ,'   |'-..__   .._ L
           .    \_ -'   `-'     ..      `.-' `.`-.'_ .|
           |   ,',-,--..  ,--../  `.  .-.    , `-.  ``.
           `.,' ,  |   |  `.  /'/,,.\/  |    \|   |
                `  `---'    `j   .   \  .     '   j
              ,__`"        ,'|`'\_/`.'\'        |\-'-, _,.
       .--...`-. `-`. /    '- ..      _,    /\ ,' .--"'  ,'".
     _'-""-    --  _`'-.../ __ '.'`-^,_`-""""---....__  ' _,-`
   _.----`  _..--.'        |  "`-..-" __|'"'         .""-. ""'--.._
  /        '    /     ,  _.+-.'  ||._'   """". .          `     .__\
 `---    /        /  / j'       _/|..`  -. `-`\ \   \  \   `.  \ `-..
," _.-' /    /` ./  /`_|_,-"   ','|       `. | -'`._,   L  \ .  `.   |
`"' /  /  / ,__...-----| _.,  ,'            `|----.._`-.|' |. .` ..  .
   /  '| /.,/   \--.._ `-,' ,          .  '`.'  __,., '  ''``._ \ \`,'
  /_,'---  ,     \`._,-` \ //  / . \    `._,  -`,  / / _   |   `-L -
   /       `.     ,  ..._ ' `_/ '| |\ `._'       '-.'   `.,'     |
  '         /    /  ..   `.  `./ | ; `.'    ,"" ,.  `.    \      |
   `.     ,'   ,'   | |\  |       "        |  ,'\ |   \    `    ,L
   /|`.  /    '     | `-| '                  /`-' |    L    `._/  \
  / | .`|    |  .   `._.'                   `.__,'   .  |     |  (`
 '-""-'_|    `. `.__,._____     .    _,        ____ ,-  j     ".-'"'
        \      `-.  \/.    `"--.._    _,.---'""\/  "_,.'     /-'
         )        `-._ '-.        `--"      _.-'.-""        `.
        ./            `,. `".._________...""_.-"`.          _j
       /_\.__,"".   ,.'  "`-...________.---"     .".   ,.  / \
              \_/"""-'                           `-'--(_,`"`-`)";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}
void printBlastoiseMascot()
{
    gotoxy(0, 0);
    cout << "\n\n\n\n\n\n\n\n";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
    cout << R"(
                      _
            _,..-"""--' `,.-".
          ,'      __.. --',  |
        _/   _.-"' |    .' | |       ____
  ,.-""'    `-"+.._|     `.' | `-..,',--.`.
 |   ,.                      '    j 7    l \__
 |.-'                            /| |    j||  .
 `.                   |         / L`.`""','|\  \
   `.,----..._       ,'`"'-.  ,'   \ `""'  | |  l
     Y        `-----'       v'    ,'`,.__..' |   .
      `.                   /     /   /     `.|   |
        `.                /     l   j       ,^.  |L
          `._            L       +. |._   .' \|  | \
            .`--...__,..-'""'-._  l L  """    |  |  \
          .'  ,`-......L_       \  \ \     _.'  ,'.  l
       ,-"`. / ,-.---.'  `.      \  L..--"'  _.-^.|   l
 .-"".'"`.  Y  `._'   '    `.     | | _,.--'"     |   |
  `._'   |  |,-'|      l     `.   | |"..          |   l
  ,'.    |  |`._'      |      `.  | |_,...---"""""`    L
 /   |   j _|-' `.     L       | j ,|              |   |
`--,"._,-+' /`---^..../._____,.L',' `.             |\  |
   |,'      L                   |     `-.          | \j
            .                    \       `,        |  |
             \                __`.Y._      -.     j   |
              \           _.,'       `._     \    |  j
              ,-"`-----""""'           |`.    \  7   |
             /  `.        '            |  \    \ /   |
            |     `      /             |   \    Y    |
            |      \    .             ,'    |   L_.-')
             L      `.  |            /      ]     _.-^._
              \   ,'  `-7         ,-'      / |  ,'      `-._
             _,`._       `.   _,-'        ,',^.-            `.
          ,-'     v....  _.`"',          _:'--....._______,.-'
        ._______./     /',,-'"'`'--.  ,-'  `.
                 """""`.,'         _\`----...'
                        --------""' )";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}
//get corresponding background from file
char** getBackground( string mode)
{
    char** bg = NULL;
    fstream outfile;
    if (mode == "EZ")
    {
        bg = new char* [15];
        for (int i = 0; i < 15; i++)
        {
            bg[i] = new char[68];
        }
        outfile.open("data\\bgEZ.txt", ios::in);
        for (int i = 0; i < 15; i++)
        {
            string g;
            getline(outfile,g);
            for (int j = 0; j < 68; j++)
            {
                bg[i][j] = g[j];
            }
        }
        outfile.close();
    }
    if (mode == "MED")
    {
        bg = new char* [33];
        for (int i = 0; i < 33; i++)
        {
            bg[i] = new char[90];
        }
        outfile.open("data\\bgMED.txt", ios::in);
        for (int i = 0; i < 33; i++)
        {
            string g;
            getline(outfile, g);
            for (int j = 0; j < 90; j++)
            {
                bg[i][j] = g[j];
            }
        }
        outfile.close();
    }
    if (mode == "HARD")
    {
        bg = new char* [42];
        for (int i = 0; i < 42; i++)
        {
            bg[i] = new char[120];
        }
        outfile.open("data\\bgHARD.txt", ios::in);
        for (int i = 0; i < 42; i++)
        {
            string g;
            getline(outfile, g);
            for (int j = 0; j < 120; j++)
            {
                bg[i][j] = g[j];
            }
        }
        outfile.close();
    }
    if (mode == "A+")
    {
        bg = new char* [42];
        for (int i = 0; i < 42; i++)
        {
            bg[i] = new char[132];
        }
        outfile.open("data\\bgA.txt", ios::in);
        for (int i = 0; i < 42; i++)
        {
            string g;
            getline(outfile, g);
            for (int j = 0; j < 132; j++)
            {
                bg[i][j] = g[j];
            }
        }
        outfile.close();
    }
    return bg;
}
//delete the background
void deleteBackground(char** bg, string mode)
{
    if (mode == "EZ")
    {
        for (int i = 0; i < 15; i++)
        {
            delete[] bg[i];
        }
        delete[] bg;
    }
    if (mode == "MED")
    {
        for (int i = 0; i < 33; i++)
        {
            delete[] bg[i];
        }
        delete[] bg;
    }
    if (mode == "HARD")
    {
        for (int i = 0; i < 42; i++)
        {
            delete[] bg[i];
        }
        delete[] bg;
    }
    if (mode == "A+")
    {
        for (int i = 0; i < 42; i++)
        {
            delete[] bg[i];
        }
        delete[] bg;
    }
}
//display background when pairs disappear
void displayBackground(char** table, const int ROWS, const int COLS, int curX, int curY, char** bg)
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (table[i][j] == ' ')
            {
                gotoxy(curX + 1 + j * 8, curY + 1 + i * 4);
                for (int k = 0; k < 7; k++)
                {
                    cout << bg[4 * i][j * 8 + k];
                }
                gotoxy(curX + 1 + j * 8, curY + 2 + i * 4);
                for (int k = 0; k < 7; k++)
                {
                    cout << bg[4 * i + 1][j * 8 + k];
                }

                gotoxy(curX + 1 + j * 8, curY + 3 + i * 4);
                for (int k = 0; k < 7; k++)
                {
                    cout << bg[4 * i + 2][j * 8 + k];
                }
            }
        }
    }
    for (int i = 0; i < ROWS - 1; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (table[i][j] == table[i + 1][j] && table[i][j] == ' ')
            {
                if (j == COLS - 1)
                {
                    gotoxy(curX + 1 + j * 8, curY + 4 + i * 4);
                    for (int k = 0; k < 6; k++)
                    {
                        cout << bg[4 * i + 3][j * 8 + k];
                    }
                    break;
                }
                gotoxy(curX + 1 + j * 8, curY + 4 + i * 4);
                for (int k = 0; k <= 7; k++)
                {
                    cout << bg[4 * i + 3][j * 8 + k];
                }
            }
        }
    }
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS - 1; j++)
        {
            if (table[i][j] == table[i][j + 1] && table[i][j] == ' ')
            {
                gotoxy(curX + (j + 1) * 8, curY + 1 + i * 4);
                cout << bg[i * 4][8 * (j + 1) - 1];
                gotoxy(curX + (j + 1) * 8, curY + 2 + i * 4);
                cout << bg[i * 4 + 1][8 * (j + 1) - 1];
                gotoxy(curX + (j + 1) * 8, curY + 3 + i * 4);
                cout << bg[i * 4 + 2][8 * (j + 1) - 1];
            }
        }
    }
}