#include "Functions.h"
using namespace std;
//print the logo and title
void printLogo()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	cout << R"(




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
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}
//print the log in and sign up menu
int joinMenu()
{
	{
		{
			gotoxy(0, 0);
			int choice = 1;
			printLogo();
			while (true)
			{
				gotoxy(103, 24);
				cout << "   LOG IN   ";
				gotoxy(103, 25);
				cout << "   SIGN UP   ";
				gotoxy(100, 26);
				cout << "   Play as Guest   ";
				switch (choice)
				{
				case 1:
				{
					gotoxy(103, 24);
					cout << char(196) << char(196) << char(16);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 9 + 0);
					cout << "LOG IN";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
					cout << char(17) << char(196) << char(196);
					break;
				}
				case 2:
				{
					gotoxy(103, 25);
					cout << char(196) << char(196) << char(16);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 9 + 0);
					cout << "SIGN UP";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
					cout << char(17) << char(196) << char(196);
					break;
				}
				case 3:
				{
					gotoxy(100, 26);
					cout << char(196) << char(196) << char(16);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 9 + 0);
					cout << "Play as Guest";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
					cout << char(17) << char(196) << char(196);
					break;
				}
				}
				switch (_getch())
				{
				case KEY_DOWN:
				{
					if (choice == 3)
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
						choice = 3;
						break;
					}
					choice--;
					break;
				}
				case KEY_RETURN:
				{
					selectMusic();
					return choice;
				}
				}
			}
		}
	}
}
//print the game main menu
int launchMenu(string displayname)
{
	int choice = 1;
	gotoxy(0, 0);
	printLogo();
	gotoxy(106 - (13 + displayname.length()) / 2, 23);
	cout << "Welcome back, " << displayname << "!";
	while (true)
	{
		gotoxy(101, 24);
		cout << "   START   ";
		gotoxy(98, 25);
		cout << "   LEADERBOARD   ";
		gotoxy(101, 26);
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
		case 3:
		{
			gotoxy(101, 26);
			cout << char(196) << char(196) << char(16);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 9 + 0);
			cout << "EXIT";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			cout << char(17) << char(196) << char(196);
			break;
		}
		}
		switch (_getch())
		{
		case KEY_DOWN:
		{
			if (choice == 3)
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
				choice = 3;
				break;
			}
			choice--;
			break;
		}
		case KEY_RETURN:
		{
			selectMusic();
			return choice;
		}
		}
	}
}
//print the menu to choose difficulty
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
				selectMusic();
				return choice;
			}
			}
		}
	}
}
//print the announcement when finished the game and game completing time
void gameFinishAnnounce(chrono::duration<double> elapsed_seconds)
{
	gotoxy(0, 0);
	printLogo();
	gotoxy(106 - 7, 24);
	cout << "CONGRATULATION!\n";
	gotoxy(106 - 16, 25);
	cout << "THE GAME TOOK YOU " << elapsed_seconds.count() << "s TO FINISH IT!";
	playBG(false);
	playBGAsian(false);
	gameFinishMusic();
	playBG(true);
	_getch();
}
//print the leaderboard
void displayLeaderboard(pair <string, chrono::duration<double>> leaderboard[], int size)
{
	system("cls");
	printLogo();
	gotoxy(90, 18);
	for (int i = 90; i < 145; i++)
	{
		cout << char(205);
	}
	Sleep(5);
	gotoxy(90, 18);
	cout << char(201);
	gotoxy(106, 18);
	cout << char(203);
	gotoxy(145, 18);
	cout << char(187);
	gotoxy(96, 19);
	Sleep(5);
	cout << "NAME";
	gotoxy(108, 19);
	cout << "TIME";
	Sleep(5);
	gotoxy(90, 20);
	for (int i = 90; i < 145; i++)
	{
		cout << char(205);
	}
	Sleep(5);
	for (int i = 1; i < size + 4; i++)
	{
		gotoxy(106, 18 + i);
		cout << char(186);
		gotoxy(90, 18 + i);
		cout << char(186);
		gotoxy(145, 18 + i);
		cout << char(186);
		Sleep(5);
	}
	gotoxy(90, 20);
	for (int i = 90; i < 145; i++)
	{
		cout << char(205);
	}
	Sleep(5);
	gotoxy(90, 20);
	cout << char(204);
	gotoxy(106, 20);
	cout << char(206);
	gotoxy(145, 20);
	cout << char(185);
	Sleep(5);
	gotoxy(90, 31);
	for (int i = 90; i < 145; i++)
	{
		cout << char(205);
	}
	Sleep(5);
	gotoxy(90, 31);
	cout << char(200);
	gotoxy(106, 31);
	cout << char(202);
	gotoxy(145, 31);
	cout << char(188);
	Sleep(5);
	for (int i = 0; i < size; i++)
	{
		gotoxy(91, 21 + i);
		cout << leaderboard[i].first;
		gotoxy(108, 21 + i);
		cout << fixed << setprecision(2) << leaderboard[i].second.count() << "s";
		Sleep(5);
	}

	_getch();
}
//print the exit menu
void goodbyeMenu()
{
	gotoxy(0, 0);
	system("cls");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	cout << R"(




								      ________  ___  ___  __    ________  ________  ___  ___  ___  ___     
								     |\   __  \|\  \|\  \|\  \ |\   __  \|\   ____\|\  \|\  \|\  \|\  \    
								     \ \  \|\  \ \  \ \  \/  /|\ \  \|\  \ \  \___|\ \  \\\  \ \  \\\  \   
								      \ \   ____\ \  \ \   __\_ \ \   __  \ \  \    \ \   __  \ \  \\\  \  
								       \ \  \___|\ \  \ \  \\ \  \ \  \ \  \ \  \____\ \  \ \  \ \  \\\  \ 
								        \ \__\    \ \__\ \__\\ \__\ \__\ \__\ \_______\ \__\ \__\ \_______\
								         \|__|     \|__|\|__| \|__|\|__|\|__|\|_______|\|__|\|__|\|_______|)";

	cout << "\n\n\n\n\n\n\n";
	
	cout << R"(
									 ___  ___  ___       __   __  ___   _   _        ___   ___  ___  ___  _  _ 
									/ __|| __|| __|      \ \ / / / _ \ | | | |      /   \ / __|/   \|_ _|| \| |
									\__ \| _| | _|        \   / | (_) || |_| |      | - || (_ || - | | | | .  |
									|___/|___||___|        |_|   \___/  \___/       |_|_| \___||_|_||___||_|\_|
)";
	Sleep(2500);
}

