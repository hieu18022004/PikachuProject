
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

    ofstream outFile("savegame.dat", ios::binary);
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