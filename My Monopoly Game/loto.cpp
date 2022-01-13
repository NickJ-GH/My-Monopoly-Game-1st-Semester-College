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
    this gives a random int 1-5 for the lottery

*/

int lotto(){

    int num;

    srand (time(NULL));

    num = rand() % 5 + 1;

    return num;
}