// CS1300 Fall 2021
// Author: Nicholas Johns
// Recitation: 315 – Teo Price-Broncucia
// Project 3 

#include <fstream>
#include <iostream>
#include <array>
#include <vector>
#include "Player.h"

using namespace std;

/*
    this includes the constructors for the Player class

    this also conatians the setters and getter fot the Player class

*/

//default constructor
Player::Player(){
    playerName = 'a';
    position = 0;
    amountOfCash = 0;
    numberOfRolls = 0;
}

//parameterized constructor
Player::Player(char name, int cash){
    playerName = name;
    position = 0;
    amountOfCash = cash;
    numberOfRolls = 0;
}

//getters/setters

char Player::getPlayerName(){
    return playerName;
}

int Player::getPosition(){
    return position;
}

void Player::setPosition(int pos){
    position = pos;
}

void Player::addPosition(int adder){
    position += adder;
    position = position%36;
}

int Player::getAmountOfCash(){
    return amountOfCash;
}

void Player::addAmountOfCash(int amount){
    amountOfCash += amount;
}

void Player::addProperty(int adding){
    playerProperties.push_back(adding);
}

int Player::getAmmountOfProperties(){
    return playerProperties.size();
}

void Player::removePoperty(int prop){
    for (int i = 0; i < playerProperties.size(); i++){
        if(playerProperties[i] == prop){
            playerProperties.erase(playerProperties.begin()+i);
        }
    }
}

int Player::getPropertyAt(int spot){
    return playerProperties[spot];
}