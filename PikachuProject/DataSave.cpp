
#include <iostream>
#include <fstream>
#include "Funcs.h"
#include <cstring>

using namespace std;

void saveGameData() 
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
}

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


void displayMainMenu() 
{
    cout << "==== GAME MENU ====" << endl;
    cout << "1. Log In" << endl;
    cout << "2. Register" << endl;
    cout << "3. Exit" << endl;
    cout << "===================" << endl;
}

void displayDifficultyMenu() 
{
    cout << "==== DIFFICULTY MENU ====" << endl;
    cout << "1. Easy" << endl;
    cout << "2. Medium" << endl;
    cout << "3. Hard" << endl;
    cout << "4. Exit" << endl;
    cout << "========================" << endl;
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