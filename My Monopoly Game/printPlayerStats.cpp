// CS1300 Fall 2021
// Author: Nicholas Johns
// Recitation: 315 – Teo Price-Broncucia
// Project 3 

#include <fstream>
#include <iostream>
#include <array>
#include <string>
#include <sstream>
#include "formatStatsLine.cpp"

using namespace std;

/*
    This function goes and prints the stats out for the players

*/

void printPlayerStats(){
    const int numPlayers = players.size();
    int numPropertiesToPrint = 0;

    for(int i = 0; i < numPlayers; i++){
        if (players[i].getAmmountOfProperties() > numPropertiesToPrint){
            numPropertiesToPrint = players[i].getAmmountOfProperties();
        }
    }

    for(int i = 0; i < numPlayers; i++){
        string name(1, players[i].getPlayerName());
        cout << formatStatsLine("player: " + name);
        cout << "                   ";
    }
    cout << endl;

    for(int i = 0; i < numPlayers; i++){
        cout << "cash: $" << players[i].getAmountOfCash(); 
        if(((players[i].getAmountOfCash()) / 10) == 0){
            cout << "      ";
        } else if(((players[i].getAmountOfCash()) / 100) == 0){
            cout << "     ";
        } else if(((players[i].getAmountOfCash()) / 1000) == 0){
            cout << "    ";
        } else if(((players[i].getAmountOfCash()) / 10000) == 0){
            cout << "   ";
        } else if(((players[i].getAmountOfCash()) / 100000) == 0){
            cout << "  ";
        } else if(((players[i].getAmountOfCash()) / 100000) == 0){
            cout << " ";
        } 
        cout << "                   ";  
    }
    cout << endl;

    for(int i = 0; i < numPlayers-1; i++){
        cout << formatStatsLine("properties:"); 
        cout << "                   "; 
    }
    cout << formatStatsLine("properties:") << endl;

    for(int i = 0; i < numPropertiesToPrint; i++){
        for(int a = 0; a < numPlayers; a++){
            if(players[a].getAmmountOfProperties() -1 < i){
                cout << formatStatsLine("  ");
            } else {
                cout << formatStatsLine(boardMap[players[a].getPropertyAt(i)].getPropertyName());
            }
            cout << "                   ";
        }
        cout << endl;
    }
    cout << endl;
}