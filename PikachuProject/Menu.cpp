#include "Funcs.h"
#include <iomanip>
#include <chrono>
#include <windows.h>
#include <conio.h>
#include <iostream>
#include <cwchar>
#include <random>
using namespace std;
void printLogo()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	cout<< R"(




								      ________  ___  ___  __    ________  ________  ___  ___  ___  ___     
								     |\   __  \|\  \|\  \|\  \ |\   __  \|\   ____\|\  \|\  \|\  \|\  \    
								     \ \  \|\  \ \  \ \  \/  /|\ \  \|\  \ \  \___|\ \  \\\  \ \  \\\  \   
								      \ \   ____\ \  \ \   __\_ \ \   __  \ \  \    \ \   __  \ \  \\\  \  
								       \ \  \___|\ \  \ \  \\ \  \ \  \ \  \ \  \____\ \  \ \  \ \  \\\  \ 
								        \ \__\    \ \__\ \__\\ \__\ \__\ \__\ \_______\ \__\ \__\ \_______\
								         \|__|     \|__|\|__| \|__|\|__|\|__|\|_______|\|__|\|__|\|_______|)";
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> distr(1, 3);
	switch (distr(gen))
	{
	case 1:
	{
		cout << "\n\n\n\n\n\n\n\n";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
		cout << R"(
                                           /
                        _,.------....___,.' ',.-.
                     ,-'          _,.--"        |
                   ,'         _.-'              .
                  /   ,     ,'                   `
                 .   /     /                     ``.
                 |  |     .                       \.\
       ____      |___._.  |       __               \ `.
     .'    `---""       ``"-.--"'`  \               .  \
    .  ,            __               `              |   .
    `,'         ,-"'  .               \             |    L
   ,'          '    _.'                -._          /    |
  ,`-.    ,".   `--'                      >.      ,'     |
 . .'\'   `-'       __    ,  ,-.         /  `.__.-      ,'
 ||:, .           ,'  ;  /  / \ `        `.    .      .'/
 j|:D  \          `--'  ' ,'_  . .         `.__, \   , /
/ L:_  |                 .  "' :_;                `.'.'
.    ""'                  """""'                    V
 `.                                 .    `.   _,..  `
   `,_   .    .                _,-'/    .. `,'   __  `
    ) \`._        ___....----"'  ,'   .'  \ |   '  \  .
   /   `. "`-.--"'         _,' ,'     `---' |    `./  |
  .   _  `""'--.._____..--"   ,             '         |
  | ." `. `-.                /-.           /          ,
  | `._.'    `,_            ;  /         ,'          .
 .'          /| `-.        . ,'         ,           ,
 '-.__ __ _,','    '`-..___;-...__   ,.'\ ____.___.'
 `"^--'..'   '-`-^-'"--    `-^-'`.''"""""`.,^.`.--' )";
		break;
	}
	case 2:
	{
		cout << "\n\n\n\n";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << R"(
               _,........__
            ,-'            "`-.
          ,'                   `-.
        ,'                        \
      ,'                           .
      .'\               ,"".       `
     ._.'|             / |  `       \
     |   |            `-.'  ||       `.
     |   |            '-._,'||       | \
     .`.,'             `..,'.'       , |`-.
     l                       .'`.  _/  |   `.
     `-.._'-   ,          _ _'   -" \  .     `
`."""""'-.`-...,---------','         `. `....__.
.'        `"-..___      __,'\          \  \     \
\_ .          |   `""""'    `.           . \     \
  `.          |              `.          |  .     L
    `.        |`--...________.'.        j   |     |
      `._    .'      |          `.     .|   ,     |
         `--,\       .            `7""' |  ,      |
            ` `      `            /     |  |      |    _,-'"""`-.
             \ `.     .          /      |  '      |  ,'          `.
              \  v.__  .        '       .   \    /| /              \
               \/    `""\"""""""`.       \   \  /.''                |
                `        .        `._ ___,j.  `/ .-       ,---.     |
                ,`-.      \         ."     `.  |/        j     `    |
               /    `.     \       /         \ /         |     /    j
              |       `-.   7-.._ .          |"          '         /
              |          `./_    `|          |            .     _,'
              `.           / `----|          |-............`---'
                \          \      |          |
               ,'           )     `.         |
                7____,,..--'      /          |
                                  `---.__,--.')";
		break;
	}
	case 3:
	{
		cout << "\n\n";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		cout << R"(
              _.--""`-..
            ,'          `.
          ,'          __  `.
         /|          " __   \
        , |           / |.   .
        |,'          !_.'|   |
      ,'             '   |   |
     /              |`--'|   |
    |                `---'   |
     .   ,                   |                       ,".
      ._     '           _'  |                    , ' \ `
  `.. `.`-...___,...---""    |       __,.        ,`"   L,|
  |, `- .`._        _,-,.'   .  __.-'-. /        .   ,    \
-:..     `. `-..--_.,.<       `"      / `.        `-/ |   .
  `,         """"'     `.              ,'         |   |  ',,
    `.      '            '            /          '    |'. |/
      `.   |              \       _,-'           |       ''
        `._'               \   '"\                .      |
           |                '     \                `._  ,'
           |                 '     \                 .'|
           |                 .      \                | |
           |                 |       L              ,' |
           `                 |       |             /   '
            \                |       |           ,'   /
          ,' \               |  _.._ ,-..___,..-'    ,'
         /     .             .      `!             ,j'
        /       `.          /        .           .'/
       .          `.       /         |        _.'.'
        `.          7`'---'          |------"'_.'
       _,.`,_     _'                ,''-----"'
   _,-_    '       `.     .'      ,\
   -" /`.         _,'     | _  _  _.|
    ""--'---"""""'        `' '! |! /
                            `" " -' )";
		break;
	}
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}
int launchMenu()
{
	int choice = 1;
	printLogo();
	while (true)
	{
		gotoxy(101, 24);
		cout << "   START   ";
		gotoxy(98, 25);
		cout << "   LEADERBOARD   ";
		gotoxy(98, 26);
		cout << "   BEST SCORES   ";
		gotoxy(101, 27);
		cout << "   EXIT   ";
		switch (choice)
		{
		case 1:
		{
			gotoxy(101, 24);
			cout << char(196) << char(196) << char(16);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 9 + 0);
			cout << "START";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			cout << char(17) << char(196) << char(196);
			break;
		}
		case 2:
		{
			gotoxy(98, 25);
			cout << char(196) << char(196) << char(16);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 9 + 0);
			cout << "LEADERBOARD";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			cout << char(17) << char(196) << char(196);
			break;
		}
		case 4:
		{
			gotoxy(101, 27);
			cout << char(196) << char(196) << char(16);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 9 + 0);
			cout << "EXIT";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			cout << char(17) << char(196) << char(196);
			break;
		}
		case 3:
		{
			gotoxy(98, 26);
			cout << char(196) << char(196) << char(16);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 9 + 0);
			cout << "BEST SCORES";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			cout << char(17) << char(196) << char(196);
			break;
		}
		}
		switch (_getch())
		{
		case KEY_DOWN:
		{
			if (choice == 4)
			{
				choice = 1;
				break;
			}
			choice++;
			break;
		}
		case KEY_UP:
		{
			if (choice == 1)
			{
				choice = 4;
				break;
			}
			choice--;
			break;
		}
		case KEY_RETURN:
		{
			matchMusic();
			Sleep(250);
			return choice;
		}
		}
	}
}
int difficultyMenu()
{
	{
		gotoxy(0, 0);
		int choice = 1;
		printLogo();
		gotoxy(106-8,23);
		cout << "SELECT DIFFICULTY";
		while (true)
		{
			gotoxy(101, 24);
			cout << "   EASY   ";
			gotoxy(100, 25);
			cout << "   MEDIUM   ";
			gotoxy(101, 26);
			cout << "   HARD   ";
			gotoxy(100, 27);
			cout << "   ASIAN:)   ";
			gotoxy(100, 28);
			cout << "   RETURN   ";
			switch (choice)
			{
			case 1:
			{
				gotoxy(101, 24);
				cout << char(196) << char(196) << char(16);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 9 + 0);
				cout << "EASY";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				cout << char(17) << char(196) << char(196);
				break;
			}
			case 2:
			{
				gotoxy(100, 25);
				cout << char(196) << char(196) << char(16);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 9 + 0);
				cout << "MEDIUM";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				cout << char(17) << char(196) << char(196);
				break;
			}
			case 3:
			{
				gotoxy(101, 26);
				cout << char(196) << char(196) << char(16);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 9 + 0);
				cout << "HARD";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				cout << char(17) << char(196) << char(196);
				break;
			}
			case 4:
			{
				gotoxy(100, 27);
				cout << char(196) << char(196) << char(16);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 9 + 0);
				cout << "ASIAN:)";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				cout << char(17) << char(196) << char(196);
				break;
			}
			case 5:
			{
				gotoxy(100, 28);
				cout << char(196) << char(196) << char(16);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 9 + 0);
				cout << "RETURN";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				cout << char(17) << char(196) << char(196);
				break;
			}
			}
			switch (_getch())
			{
			case KEY_DOWN:
			{
				if (choice == 5)
				{
					choice = 1;
					break;
				}
				choice++;
				break;
			}
			case KEY_UP:
			{
				if (choice == 1)
				{
					choice = 5;
					break;
				}
				choice--;
				break;
			}
			case KEY_RETURN:
			{
				matchMusic();
				Sleep(250);
				return choice;
			}
			}
		}
	}
}
void gameFinishAnnounce(chrono::duration<double> elapsed_seconds)
{
	gotoxy(0, 0);
	printLogo();
	gotoxy(106 - 7, 24);
	cout << "CONGRATULATION!\n";
	gotoxy(106 - 12, 25);
	cout << "THE GAME TOOK YOU " << elapsed_seconds.count() << " TO FINISH IT!";
	_getch();
}