// CS1300 Fall 2021
// Author: Nicholas Johns
// Recitation: 315 – Teo Price-Broncucia
// Project 3 

#include <fstream>
#include <iostream>
#include <array>
#include <vector>
#include <string>
#include "split.cpp"
#include "formatSpotLine.cpp"

using namespace std;

/*
    this sets up everything before the game is started

*/

vector <Property> boardMap;
vector <Player> players;
vector <Card> Community;
vector <Card> Chance;
Bank theBank = Bank();

void create(int numberOfPlayers, int cash){
    ifstream myStream;
    string line;
    string arrayPlaceholder [3];
    string holder [2];
    string secondholder [2];
    int spot = 1;
    int vectorSpot = 0;

    myStream.open("info.txt");

    if(myStream.fail()){
        cout << "opening the file with spot information failed" << endl;
    } else {
        while (getline(myStream, line)){
            split(line, '|', arrayPlaceholder, 3);
            if(arrayPlaceholder[2].length() > 1){
                boardMap.push_back(Property(arrayPlaceholder[0], arrayPlaceholder[1], stoi(arrayPlaceholder[2]), false, (stoi(arrayPlaceholder[2]) / 5)));
                boardMap[vectorSpot].setLineOne(formatSpotLine(arrayPlaceholder[0]));
                boardMap[vectorSpot].setLineTwo(formatSpotLine(arrayPlaceholder[1]));
                boardMap[vectorSpot].setLineThree(formatSpotLine(formatSpotLine(to_string(spot)+ "   $" + arrayPlaceholder[2])));
                boardMap[vectorSpot].setLineFour(formatSpotLine(" "));
            } else {
                boardMap.push_back(Property(arrayPlaceholder[0], arrayPlaceholder[1], 0, true, 0));
                boardMap[vectorSpot].setLineOne(formatSpotLine(arrayPlaceholder[0]));
                boardMap[vectorSpot].setLineTwo(formatSpotLine(arrayPlaceholder[1]));
                boardMap[vectorSpot].setLineThree(formatSpotLine(formatSpotLine(to_string(spot) + "      ")));
                boardMap[vectorSpot].setLineFour(formatSpotLine(" "));
            }
            vectorSpot++;
            spot++;
        }
    } 

    myStream.close();


    players.push_back( Player('$', cash) );
    players.push_back( Player('#', cash) );
    players.push_back( Player('@', cash) );
    if(numberOfPlayers >= 4){
        players.push_back( Player('&', cash) );
    }
    if(numberOfPlayers == 5){
        players.push_back( Player('^', cash) );
    }





    myStream.open("/Users/nikojohns/Desktop/project3_Johns/chance.txt");

    if(myStream.fail()){
        cout << "opening the file with spot information failed" << endl;
    } else {
        while (getline(myStream, line)){
            split(line, '|', holder, 2);
            Chance.push_back( Card(holder[1], stoi(holder[0])));
        }
    } 

    myStream.close();




    myStream.open("/Users/nikojohns/Desktop/project3_Johns/community.txt");

    if(myStream.fail()){
        cout << "opening the file with spot information failed" << endl;
    } else {
        while (getline(myStream, line)){
            split(line, '|', secondholder, 2);
            Community.push_back( Card(secondholder[1], stoi(secondholder[0])));
        }
    } 

    myStream.close();
}