// CS1300 Fall 2021
// Author: Nicholas Johns
// Recitation: 315 – Teo Price-Broncucia
// Project 3 

#ifndef Card_H 
#define Card_H

#include <fstream>
#include <iostream>
#include <array>
#include <vector>

using namespace std;

/*
    this class is for Cards

*/

class Card {
    public: 
        // default constructor
        Card();

        // parameterized constructor
        Card(string inputDirections, int num);

        // gettrs and setters
        string getDirections();
        int getCardNum();

    private:
        string directions;
        int cardNum;
};

#endif