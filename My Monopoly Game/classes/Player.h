// CS1300 Fall 2021
// Author: Nicholas Johns
// Recitation: 315 – Teo Price-Broncucia
// Project 3 

#ifndef Player_H 
#define Player_H

#include <fstream>
#include <iostream>
#include <array>
#include <vector>
//#include "/Users/nikojohns/Desktop/CSCI 1300/Monopoly Game/classes/Property.cpp"

using namespace std;

/*
    this class is for players

*/

class Player {
    public: 

        //default constructor
        Player();

        // parameterized constructor
        Player(char name, int cash);

        // gettrs and setters
        char getPlayerName();
        int getPosition();
        void setPosition(int pos);
        void addPosition(int adder);
        int getAmountOfCash();
        void addAmountOfCash(int amount);
        void addProperty(int adding);
        int getAmmountOfProperties();
        void removePoperty(int prop);
        int getPropertyAt(int spot);

    private:
        char playerName;
        int position;
        int amountOfCash;
        int numberOfRolls;
        vector <int> playerProperties;
};

#endif