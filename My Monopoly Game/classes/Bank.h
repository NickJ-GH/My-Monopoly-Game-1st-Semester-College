// CS1300 Fall 2021
// Author: Nicholas Johns
// Recitation: 315 – Teo Price-Broncucia
// Project 3 

#ifndef Bank_H 
#define Bank_H

#include <fstream>
#include <iostream>
#include <array>
#include <vector>

using namespace std;

/*
    this class is for players

*/

class Bank {
    public: 
        // default constructor
        Bank();

        // gettrs and setters
        void addProperty(int adding);
        int getAmmountOfProperties();
        void removePoperty(int prop);
        void addlottery(int adding);
        int getlottery();

    private:
        vector<int> bankProperties;
        int lottery;
        int getPropertyAt(int spot);
};

#endif