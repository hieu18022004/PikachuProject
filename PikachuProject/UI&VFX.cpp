#include "Functions.h"
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

void matchMusic()
{
    mciSendString(TEXT(" open \"music\\match.wav\" type waveaudio alias match"), NULL, 0, NULL);
    mciSendString(TEXT("setaudio match volume to 1000"), NULL, 0, NULL);
    mciSendString(TEXT("play match wait"), NULL, 0, NULL);
    mciSendString(TEXT("close match"), NULL, 0, NULL);
}

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
        bg = new char* [28];
        for (int i = 0; i < 28; i++)
        {
            bg[i] = new char[59];
        }
        outfile.open("data\\bgMED.txt", ios::in);
        for (int i = 0; i < 28; i++)
        {
            string g;
            getline(outfile, g);
            for (int j = 0; j < 59; j++)
            {
                bg[i][j] = g[j];
            }
        }
        outfile.close();
    }
    if (mode == "HARD")
    {
        bg = new char* [36];
        for (int i = 0; i < 36; i++)
        {
            bg[i] = new char[69];
        }
        outfile.open("data\\bgHARD.txt", ios::in);
        for (int i = 0; i < 36; i++)
        {
            string g;
            getline(outfile, g);
            for (int j = 0; j < 69; j++)
            {
                bg[i][j] = g[j];
            }
        }
        outfile.close();
    }
    if (mode == "A+")
    {
        bg = new char* [39];
        for (int i = 0; i < 39; i++)
        {
            bg[i] = new char[72];
        }
        outfile.open("data\\bgA.txt", ios::in);
        for (int i = 0; i < 39; i++)
        {
            string g;
            getline(outfile, g);
            for (int j = 0; j < 72; j++)
            {
                bg[i][j] = g[j];
            }
        }
        outfile.close();
    }
    return bg;
}

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
        for (int j = 0; j < COLS - 1; j++)
        {
            if (table[i][j] == table[i][j + 1] && table[i][j] == ' ')
            {
                gotoxy(curX + (j + 1) * 8, curY + 1 + i * 4);
                cout << bg[i * 3][7 * (j + 1) + j];
                gotoxy(curX + (j + 1) * 8, curY + 2 + i * 4);
                cout << bg[i * 3 + 1][7 * (j + 1) + j];
                gotoxy(curX + (j + 1) * 8, curY + 3 + i * 4);
                cout << bg[i * 3 + 2][7 * (j + 1) + j];
            }
            if (table[i][j] == table[i + 1][j])
            {
                gotoxy(curX + 1 + j * 8, curY + 4 + i * 4);
                for (int k = 0; k < 7; k++)
                {
                    cout << bg[4 * i + 2][j * 8 + k];
                }
            }
        }
    }
}