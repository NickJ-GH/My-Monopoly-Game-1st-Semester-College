// CS1300 Fall 2021
// Author: Nicholas Johns
// Recitation: 315 – Teo Price-Broncucia
// Project 3 

#include <fstream>
#include <iostream>
#include <array>
#include <vector>
#include "Card.h"

using namespace std;

/*
    this includes the constructors for the Card class

    this also conatians the setters and getter fot the Card class

*/

//default constructor
Card::Card(){
    directions = "";
    cardNum = 0;
}

//parameterized constructor 
Card::Card(string inputDirections, int num){
    directions = inputDirections;
    cardNum = num;
}

//getters/setters
string Card::getDirections(){
    return directions;
}

int Card::getCardNum(){
    return cardNum;
}