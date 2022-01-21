// CS1300 Fall 2021
// Author: Nicholas Johns
// Recitation: 315 – Teo Price-Broncucia
// Project 3 

#include <fstream>
#include <iostream>
#include <array>

using namespace std;

/*
    This function goes loads all of the information into the board for the start of the game

*/

string formatSpotLine(string line){
    string returnedString;
    int length = line.length();

    switch(length){
        case 0:
            returnedString = "         ";
            break;
        case 1:
            returnedString = "    " + line + "    ";
            break;
        case 2:
            returnedString = "   " + line + "    ";
            break;
        case 3:
            returnedString = "   " + line + "   ";
            break;
        case 4:
            returnedString = "  " + line + "   ";
            break;
        case 5:
            returnedString = "  " + line + "  ";
            break;
        case 6:
            returnedString = " " + line + "  ";
            break;
        case 7:
            returnedString = " " + line + " ";
            break;
        case 8:
            returnedString = line + " ";
            break;
        case 9:
            returnedString = line;
            break;
        default:
            break;
    }

    return returnedString;
}