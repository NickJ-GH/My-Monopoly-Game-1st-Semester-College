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
    this determines what ratio will be aloud on a trade amount

*/

int approveTradeAmount(){

    int approved;

    srand (time(NULL));

    approved = (rand() % 40) + 85;

    return approved;
}