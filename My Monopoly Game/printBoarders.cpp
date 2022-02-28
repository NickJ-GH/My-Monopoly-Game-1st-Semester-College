// CS1300 Fall 2021
// Author: Nicholas Johns
// Recitation: 315 – Teo Price-Broncucia
// Project 3 

#include <fstream>
#include <iostream>
#include <array>

using namespace std;

/*
    These function help with printing the boarder

*/

void wholeBoarder(){
    cout << "|";
    for(int i = 0; i < 149; i++){
        cout << "-";
    }
    cout << "|" << endl;
}

void partBoarder(){
    cout << "|---------|";
    for(int i = 0; i < 129; i++){
        cout << " ";
    }
    cout << "|---------|" << endl;
}