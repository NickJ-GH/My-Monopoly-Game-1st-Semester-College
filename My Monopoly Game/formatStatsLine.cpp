// CS1300 Fall 2021
// Author: Nicholas Johns
// Recitation: 315 – Teo Price-Broncucia
// Project 3 

#include <fstream>
#include <iostream>
#include <array>

using namespace std;

/*
    This function makes sure all of the stats have a good amount of sepertation between them

*/

string formatStatsLine(string line){
    string returnedString = line;
    int length = line.length();

    for (int i = 0; i < (14 - length); i++){
        returnedString = returnedString + " ";
    }

    return returnedString;
}