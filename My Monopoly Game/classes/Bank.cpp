// CS1300 Fall 2021
// Author: Nicholas Johns
// Recitation: 315 – Teo Price-Broncucia
// Project 3 

#include <fstream>
#include <iostream>
#include <array>
#include <vector>
#include "Bank.h"

using namespace std;

/*
    this includes the constructors for the Bank class

    this also conatians the setters and getter fot the Bank class

*/

//default constructor
Bank::Bank(){
    lottery = 0;
}

//getters/setters

void Bank::addProperty(int adding){
    bankProperties.push_back(adding);
}

int Bank::getAmmountOfProperties(){
    return bankProperties.size();
}

void Bank::removePoperty(int prop){
    for (int i = 0; i < bankProperties.size(); i++){
        if(bankProperties[i] == prop){
            bankProperties.erase(bankProperties.begin()+i);
        }
    }
}

int Bank::getPropertyAt(int spot){
    return bankProperties[spot];
}

void Bank::addlottery(int adding){
    lottery += adding;
}

int Bank::getlottery(){
    return lottery;
}