#include "Functions.h"
using namespace std;
//time <chrono> ref:https://www.geeksforgeeks.org/chrono-in-c/
int main()
{
	// y: 0->48 || x: 0 -> 210 center x=106 y=25
	system("cls");
	HWND hWnd = GetConsoleWindow(); //console full screen ref: https://www.daniweb.com/programming/software-development/threads/31665/how-to-make-console-programs-full-screen.
	ShowWindow(hWnd, SW_SHOWMAXIMIZED);
	ShowConsoleCursor(false);
	playBG(true);
	pair <string, chrono::duration<double>> leaderboardEZ[10];
	pair <string, chrono::duration<double>> leaderboardMED[10];
	pair <string, chrono::duration<double>> leaderboardHARD[10];
	pair <string, chrono::duration<double>> leaderboardA[10];
	//this eight lines is to re-initiate the scoreleaderboard.bin do not uncomment these two unless you are sure about what you are doing
	/*leaderboardInit(leaderboardEZ, 10);
	leaderboardInit(leaderboardMED, 10);
	leaderboardInit(leaderboardHARD, 10);
	leaderboardInit(leaderboardA, 10);
	saveScoreLeaderboard(leaderboardEZ, 10, "EZ");
	saveScoreLeaderboard(leaderboardMED, 10, "MED");
	saveScoreLeaderboard(leaderboardHARD, 10, "HARD");
	saveScoreLeaderboard(leaderboardA, 10, "A+");*/
	loadScoreLeaderboard(leaderboardEZ, 10, "EZ");
	loadScoreLeaderboard(leaderboardMED, 10, "MED");
	loadScoreLeaderboard(leaderboardHARD, 10, "HARD");
	loadScoreLeaderboard(leaderboardA, 10, "A+");
	string username;
	bool exitFlag = false;
	//log in and sign up
	while (exitFlag == false)
	{
		switch (joinMenu())
		{
		case 1:
		{
			bool signInCheck = SignIn(username);
			if (signInCheck == true)
			{
				exitFlag = true;
				system("cls");
				break;
			}
			system("cls");
			break;
		}
		case 2:
		{
			SignUp();
			system("cls");
			break;
		}
		case 3:
		{
			username = "Guest";
			system("cls");
			exitFlag = true;
			break;
		}
		}
	}
	chrono::time_point<std::chrono::system_clock> start, end;
	while (true)
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
				char** bg = getBackground( "EZ");
				
				start = chrono::system_clock::now();
				system("cls");
				if (gameInit(username, "EASY", EZ_ROWS, EZ_COLS, bg) == 1)
				{
					end = chrono::system_clock::now();
					chrono::duration<double> elapsed_seconds = end - start;
					gameFinishAnnounce(elapsed_seconds);
					updateLeaderboard(leaderboardEZ, 10, username, elapsed_seconds);
				}
				break;
			}
			case 2:
			{
				char** bg = getBackground( "MED");
				
				start = chrono::system_clock::now();
				system("cls");
				if (gameInit(username, "MEDIUM", MED_ROWS, MED_COLS, bg) == 1)
				{
					end = chrono::system_clock::now();
					chrono::duration<double> elapsed_seconds = end - start;
					gameFinishAnnounce(elapsed_seconds);
					updateLeaderboard(leaderboardMED, 10, username, elapsed_seconds);
				}
				break;
			}
			case 3:
			{
				char** bg = getBackground( "HARD");
				
				start = chrono::system_clock::now();
				system("cls");
				if (gameInit(username, "HARD", HARD_ROWS, HARD_COLS, bg) == 1)
				{
					end = chrono::system_clock::now();
					chrono::duration<double> elapsed_seconds = end - start;
					gameFinishAnnounce(elapsed_seconds);
					updateLeaderboard(leaderboardHARD, 10, username, elapsed_seconds);
				}
				break;
			}
			case 4:
			{
				char** bg = getBackground( "A+");

				start = chrono::system_clock::now();
				system("cls");
				if (gameInit(username, "ASIAN", ASIAN_ROWS, ASIAN_COLS, bg) == 1)
				{
					end = chrono::system_clock::now();
					chrono::duration<double> elapsed_seconds = end - start;
					gameFinishAnnounce(elapsed_seconds);
					updateLeaderboard(leaderboardA, 10, username, elapsed_seconds);
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
			goodbyeMenu();
			saveScoreLeaderboard(leaderboardEZ, 10, "EZ");
			saveScoreLeaderboard(leaderboardMED, 10, "MED");
			saveScoreLeaderboard(leaderboardHARD, 10, "HARD");
			saveScoreLeaderboard(leaderboardA, 10, "A+");
			return 1;
		}
		case 2:
		{
			system("cls");
			switch (difficultyMenu())
			{
			case 1:
			{
				system("cls");
				displayLeaderboard(leaderboardEZ, 10);
				break;
			}
			case 2:
			{
				system("cls");
				displayLeaderboard(leaderboardMED, 10);
				break;
			}
			case 3:
			{
				system("cls");
				displayLeaderboard(leaderboardHARD, 10);
				break;
			}
			case 4:
			{
				system("cls");
				displayLeaderboard(leaderboardA, 10);
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
		}
	}
	goodbyeMenu();
	saveScoreLeaderboard(leaderboardEZ, 10, "EZ");
	saveScoreLeaderboard(leaderboardMED, 10, "MED");
	saveScoreLeaderboard(leaderboardHARD, 10, "HARD");
	saveScoreLeaderboard(leaderboardA, 10, "A+");
	return 1;
}



