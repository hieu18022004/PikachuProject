﻿
#include "Functions.h"

using namespace std;

/*void saveGameData()
{
    Player player;
    cout << "Enter player name: ";
    cin.getline(player.name, 50);
    cout << "Enter year of birth: ";
    cin >> player.yearOfBirth;
    cout << "Enter records: ";
    cin >> player.records;
    cout << "Enter save stages: ";
    cin >> player.saveStages;

    ofstream outFile("savegame.bin", ios::binary);
    if (outFile) 
    {
        outFile.write(reinterpret_cast<char*>(&player), sizeof(player));
        //cout << "Game data saved successfully." << endl;
    }
    else 
    {
        //cout << "Error!" << endl;
    }
    outFile.close();
}*/

void SignUp() 
{
    string username, password;

    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    LogIn newPlayer;
    newPlayer.username = username;
    newPlayer.password = password;

    // Save player information to binary file
    ofstream outfile("players.bin", ios::binary | ios::app);
    outfile.write(reinterpret_cast<char*>(&newPlayer), sizeof(Player));
    outfile.close();

    cout << "Player account created successfully!" << endl;
}

bool SignIn(string &displayname)
{
    string username, password;
    system("cls");
    gotoxy(0, 0);
    printLogo();
    gotoxy(99, 24);
    cout << "Enter username: ";
    cin >> username;
    gotoxy(99, 25);
    cout << "Enter password: ";
    cin >> password;

    LogIn player;
    bool found = false;

    // Open the binary file to search for the player
    ifstream infile("players.bin", ios::binary);
    while (infile.read(reinterpret_cast<char*>(&player), sizeof(Player)))
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


void addUserToLeaderboard(const string& username)
{
    LogIn player = { username };
    ofstream outfile("userleaderboard.bin", ios::binary | ios::app);
    if (outfile.is_open())
    {
        // Ghi thông tin người chơi vào file binary
        outfile.write((char*)&player, sizeof(LogIn));
        outfile.close();
    }
}

void saveScoreLeaderboard(pair<string, chrono::duration<double>> leaderboard[], int size)
{
    //ref: https://www.geeksforgeeks.org/reinterpret_cast-in-c-type-casting-operators/
    fstream outfile;
    outfile.open("scoreleaderboard.bin", ios::binary | ios::out);
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

void loadScoreLeaderboard(pair <string, chrono::duration<double>> leaderboard[], int size)
{
    fstream infile;
    infile.open("scoreleaderboard.bin", ios::binary | ios::in);
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

void leaderboardInit(pair <string, chrono::duration<double>> leaderboard[], int size)
{
    for (int i = 0; i < size; i++)
    {
        leaderboard[i].first = "Nemo";
        leaderboard[i].second = 99999999999999999s;
    }
}

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

