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

int checkGame(int num){

    int number = num;
    int prop = 0;

    for(int i = 0; i < num; i++){
        if(players[i].getAmountOfCash() <= 0){
            for (int a = 0; a < players[i].getAmmountOfProperties(); a++){
                prop += boardMap[players[i].getPropertyAt(a)].getBankPrice();
            }
            if(prop == 0){
                return 0;
            }
        }
    }

    return number;
}