
#include "Functions.h"

using namespace std;
//signing up and save account to a file
void SignUp() 
{
    string username, password;
    system("cls");
    gotoxy(0, 0);
    printLogo();
    gotoxy(99, 24);
    cout << "Enter username: ";
    getline(cin, username);
    gotoxy(99, 25);
    cout << "Enter password: ";
    getline(cin, password);

    LogIn newPlayer;
    newPlayer.username = username;
    newPlayer.password = password;

    // Save player information to binary file
    ofstream outfile("data\\players.bin", ios::binary | ios::app);
    outfile.write(newPlayer.username.c_str(), newPlayer.username.size() + 1);
    outfile.write(newPlayer.password.c_str(), newPlayer.password.size() + 1);
    //outfile.write(reinterpret_cast<const char*>(&newPlayer.password[0]), newPlayer.password.size() + 1);
    outfile.close();
    system("cls");
    printLogo();
    gotoxy(106 - 17, 25);
    cout << "Player account created successfully!" << endl;
    cin.get();
    cin.ignore();
}
//signing in using accounts in a file
bool SignIn(string &displayname)
{
    string username, password;
    system("cls");
    gotoxy(0, 0);
    printLogo();
    gotoxy(99, 24);
    cout << "Enter username: ";
    getline(cin, username);
    gotoxy(99, 25);
    cout << "Enter password: ";
    getline(cin, password);

    LogIn player;
    bool found = false;

    // Open the binary file to search for the player
    ifstream infile("data\\players.bin", ios::binary);
    while (getline(infile, player.username, '\0') && getline(infile, player.password, '\0'))
    {
        if (player.username == username && player.password == password)
        {
            found = true;
            break;
        }
    }
    infile.close();

    if (found)
    {
        displayname = username;
        return true;
    }
    else
    {
        system("cls");
        printLogo();
        gotoxy(106 - 20, 25);
        cout << "Incorrect username or password. Please try again!" << endl;
        cin.get();
        cin.ignore();
        return false;
    }
}
//save score to the leaderboard of corresponding mode to a specific file
void saveScoreLeaderboard(pair<string, chrono::duration<double>> leaderboard[], int size, string mode)
{
    //ref: https://www.geeksforgeeks.org/reinterpret_cast-in-c-type-casting-operators/
    fstream outfile;
    if (mode == "EZ") outfile.open("data\\scoreleaderboard1.bin", ios::binary | ios::out);
    if (mode == "MED") outfile.open("data\\scoreleaderboard2.bin", ios::binary | ios::out);
    if (mode == "HARD") outfile.open("data\\scoreleaderboard3.bin", ios::binary | ios::out);
    if (mode == "A+") outfile.open("data\\scoreleaderboard4.bin", ios::binary | ios::out);
    for (int i = 0; i < size; i++)
    {
        const string& name = leaderboard[i].first.c_str();
        double score = leaderboard[i].second.count();
        //reinterpret_cast : convert a pointer of some data type into a pointer of another data type
        outfile.write(reinterpret_cast<const char*>(&name[0]), name.size() + 1);
        outfile.write(reinterpret_cast<const char*>(&score), sizeof(score));
    }
    outfile.close();
}
//save score to the leaderboard of corresponding mode to a specific file
void loadScoreLeaderboard(pair <string, chrono::duration<double>> leaderboard[], int size, string mode)
{
    fstream infile;
    if (mode == "EZ") infile.open("data\\scoreleaderboard1.bin", ios::binary | ios::in);
    if (mode == "MED") infile.open("data\\scoreleaderboard2.bin", ios::binary | ios::in);
    if (mode == "HARD") infile.open("data\\scoreleaderboard3.bin", ios::binary | ios::in);
    if (mode == "A+") infile.open("data\\scoreleaderboard4.bin", ios::binary | ios::in);
    for (int i = 0; i < size; i++)
    {
        string name;
        char namePart;
        while (infile.get(namePart) && namePart != '\0')
        {
            name = name + namePart;
        }
        double score;
        infile.read(reinterpret_cast<char*>(&score), sizeof(score));
        leaderboard[i] = make_pair(name, chrono::duration<double>(score));
    }
    infile.close();
}
//initiate the leaderboard (first time uses only)
void leaderboardInit(pair <string, chrono::duration<double>> leaderboard[], int size)
{
    for (int i = 0; i < size; i++)
    {
        leaderboard[i].first = "Nemo";
        leaderboard[i].second = 99999999999999999s;
    }
}
//update the leaderboard after a game
int updateLeaderboard(pair<string, chrono::duration<double>> leaderboard[], int size, string name, chrono::duration<double> time_elapsed)
{
    if (time_elapsed.count() > leaderboard[size - 1].second.count())
    {
        return 0;
    }
    pair <string, chrono::duration<double>> newboard[10] ;
    int rankindex = 0;
    for (int i = 0; i < size; i++)
    {
        if (time_elapsed.count() < leaderboard[i].second.count())
        {
            rankindex = i;
            break;
        }
    }
    for (int i = 0; i < rankindex; i++)
    {
        newboard[i] = leaderboard[i];
    }
    newboard[rankindex] = { name,time_elapsed };
    for (int i = rankindex + 1; i < size; i++)
    {
        newboard[i] = leaderboard[i - 1];
    }
    for (int i = 0; i < size; i++)
    {
        leaderboard[i] = newboard[i];
    }
}
//convert ascii art in file txt to file .bin
//ascii_art.txt & ascii_art.bin
void convertTxtToBin(const char* txtFileName, const char* binFileName) 
{
    ifstream input(txtFileName); 
    if (!input) 
    {
        cerr << "Error!" << endl;
        return;
    }

    string asciiArt; 
    char c;
    while (input.get(c)) 
    {
        asciiArt += c; 
    }

    input.close(); 

    ofstream output(binFileName, ios::out | ios::binary); 
    if (!output) {
        cerr << "Error!" << endl;
        return;
    }

    output.write(asciiArt.c_str(), asciiArt.size()); 

    output.close(); 
}
void displayAsciiArt(const char* fileName) 
{
    ifstream file(fileName, ios::in | ios::binary);
    if (!file) 
    {
        cerr << "Error!" << endl;
        return;
    }

    string asciiArt;
    char c;
    while (file.get(c)) 
    {
        asciiArt += c;
    }

    file.close();

    for (int i = 0; i < asciiArt.size(); i++) 
    {
        if (asciiArt[i] == '\n') 
        {
            cout << endl; 
        }
        else 
        {
            cout << asciiArt[i]; 
        }
    }
}

