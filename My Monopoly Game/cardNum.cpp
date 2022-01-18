// CS1300 Fall 2021
// Author: Nicholas Johns
// Recitation: 315 – Teo Price-Broncucia
// Project 3 

#include <fstream>
#include <iostream>
#include <array>
#include <stdlib.h>
#include <time.h>

using namespace std;

/*
    this gets a random number for the card

*/

int cardNumber(){

    int output;

    srand (time(NULL));

    output = rand() % 4;

    return output;
}