#include "Functions.h"
using namespace std;
//time <chrono> ref:https://www.geeksforgeeks.org/chrono-in-c/
int main()
{
	// y: 0->48 || x: 0 -> 210 center x=106 y=25
	HWND hWnd = GetConsoleWindow(); //console full screen ref: https://www.daniweb.com/programming/software-development/threads/31665/how-to-make-console-programs-full-screen.
	ShowWindow(hWnd, SW_SHOWMAXIMIZED);
	ShowConsoleCursor(false);
	playBG(true);
	pair <string, chrono::duration<double>> leaderboard[10];
	leaderboardInit(leaderboard, 10);
	saveScoreLeaderboard(leaderboard, 10);
	loadScoreLeaderboard(leaderboard, 10);
	bool exitFlag = false;
	string username = "Guest";
	/*while (true)
	{
		bool signInCheck = SignIn(username);
		if (signInCheck == true) break;
		else continue;
	}*/
	chrono::time_point<std::chrono::system_clock> start, end;
	while (exitFlag == false)
	{
		switch (launchMenu(username))
		{
		case 1:
		{
			system("cls");
			switch (difficultyMenu())
			{
			case 1:
			{
				start = chrono::system_clock::now();
				system("cls");
				if (gameInit(username, 0, 0, EZ_ROWS, EZ_COLS) == 1)
				{
					end = chrono::system_clock::now();
					chrono::duration<double> elapsed_seconds = end - start;
					gameFinishAnnounce(elapsed_seconds);
					leaderboard[0] = { username,elapsed_seconds };
					//saveScoreLeaderboard(leaderboard, 10);
				}
				break;
			}
			case 2:
			{
				start = chrono::system_clock::now();
				system("cls");
				if (gameInit(username, 0, 0, MED_ROWS, MED_COLS) == 1)
				{
					end = chrono::system_clock::now();
					chrono::duration<double> elapsed_seconds = end - start;
					gameFinishAnnounce(elapsed_seconds);
				}
				break;
			}
			case 3:
			{
				start = chrono::system_clock::now();
				system("cls");
				if (gameInit(username, 0, 0, HARD_ROWS, HARD_COLS) == 1)
				{
					end = chrono::system_clock::now();
					chrono::duration<double> elapsed_seconds = end - start;
					gameFinishAnnounce(elapsed_seconds);
				}
				break;
			}
			case 4:
			{
				start = chrono::system_clock::now();
				system("cls");
				if (gameInit(username, 0, 0, ASIAN_ROWS, ASIAN_COLS) == 1)
				{
					end = chrono::system_clock::now();
					chrono::duration<double> elapsed_seconds = end - start;
					gameFinishAnnounce(elapsed_seconds);
				}
				break;
			}
			case 5:
			{
				break;
			}
			}
			system("cls");
			break;
		}
		case 3:
		{
			return 1;
		}
		case 2:
		{
			displayLeaderboard(leaderboard, 10);
			break;
		}
		}
		return 1;
	}
}


