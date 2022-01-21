// CS1300 Fall 2021
// Author: Nicholas Johns
// Recitation: 315 – Teo Price-Broncucia
// Project 3 

#include <fstream>
#include <iostream>
#include <array>
#include <vector>
#include <string>
#include <stdlib.h>
#include <time.h>

#include "proposetrade.cpp"

using namespace std;

/*
    this is a function which allows you to make trades

    these are trades proposed by the cpu

*/

void cpuOfferTrade(int numplayers, int tradeMaker){
    int inputInt;
    char inputChar;
    int shouldItTrade;
    int playerTradeWith;
    int numPropsTradeFor;
    bool propFound = false;
    int cashTradeFor = 0;
    int cashTrade = 0;
    int propNum;
    bool newProp = true;
    vector <int> tradeForProperties;
    vector <int> tradeProperties;

    srand (time(NULL));

    shouldItTrade = rand() % 8;
    
    if (shouldItTrade == 3){
        playerTradeWith = rand() % numplayers;

        if (playerTradeWith != tradeMaker){
            if (players[playerTradeWith].getAmmountOfProperties() > 0){
                numPropsTradeFor = rand() % players[playerTradeWith].getAmmountOfProperties() + 1;

                propNum = players[playerTradeWith].getPropertyAt(rand() % players[playerTradeWith].getAmmountOfProperties());
                for(int i = 0; i < numPropsTradeFor; i++){
                    for(int a = 0; a < tradeForProperties.size(); i++){
                        if (tradeForProperties[a] == propNum){
                            newProp = false;
                        }
                    }
                    tradeForProperties.push_back(propNum);
                }

                propNum = players[tradeMaker].getPropertyAt(rand() % players[tradeMaker].getAmmountOfProperties());
                for(int i = 0; i < numPropsTradeFor; i++){
                    for(int a = 0; a < tradeProperties.size(); i++){
                        if (tradeProperties[a] == propNum){
                            newProp = false;
                        }
                    }
                    tradeProperties.push_back(propNum);
                }
            }

            if (tradeValue (tradeForProperties, cashTradeFor, tradeProperties, cashTrade) < 80){
                cashTradeFor += 95;
            } else if ( tradeValue (tradeForProperties, cashTradeFor, tradeProperties, cashTrade) > 128) {
                cashTrade += 95;
            }

            newProp = true;

            if(playerTradeWith == 0){
                cout << endl << endl << endl << players[tradeMaker].getPlayerName() << " wants to make a trade with you!" << endl << endl;

                cout << "The proposed trade is:" << endl;
                for(int i = 0; i < tradeForProperties.size(); i++){
                    cout << boardMap[tradeForProperties[i]].getPropertyName() << endl;
                }
                if (cashTradeFor > 0){
                    cout << "And $" << cashTradeFor << endl;
                }
                cout << endl << endl << endl << "For:" << endl;
                for(int i = 0; i < tradeProperties.size(); i++){
                    cout << boardMap[tradeProperties[i]].getPropertyName() << endl;
                }
                if (cashTrade > 0){
                    cout << "And $" << cashTrade << endl;
                }

                cout << "Do you want to make this trade? (Y/N)" << cashTrade << endl;
                do {
                    cin >> inputChar;
                } while (inputChar != 'Y' && inputChar != 'N');

                if(inputChar == 'Y'){
                    for(int i = 0; i < tradeForProperties.size(); i++){
                        players[tradeMaker].addProperty(tradeForProperties[i]);
                    }
                    players[tradeMaker].addAmountOfCash(cashTradeFor);
                    players[tradeMaker].addAmountOfCash(-1 * cashTrade);
                    for(int i = 0; i < tradeProperties.size(); i++){
                        players[tradeMaker].removePoperty(tradeProperties[i]);
                    }

                    for(int i = 0; i < tradeProperties.size(); i++){
                        players[0].addProperty(tradeProperties[i]);
                    }
                    players[0].addAmountOfCash(cashTrade);
                    players[0].addAmountOfCash(-1 * cashTradeFor);
                    for(int i = 0; i < tradeForProperties.size(); i++){
                        players[0].removePoperty(tradeForProperties[i]);
                    }
                } else {
                    cout << "Sorry, this trade has been denied." << endl;
                    cout << "Enter C to continue" << endl;
                    cin >> inputChar;
                }
            } else {
                if (tradeValue(tradeForProperties, cashTradeFor, tradeProperties, cashTrade) >= approveTradeAmount()){
                    for(int i = 0; i < tradeForProperties.size(); i++){
                        players[tradeMaker].addProperty(tradeForProperties[i]);
                    }
                    players[tradeMaker].addAmountOfCash(cashTradeFor);
                    players[tradeMaker].addAmountOfCash(-1 * cashTrade);
                    for(int i = 0; i < tradeProperties.size(); i++){
                        players[tradeMaker].removePoperty(tradeProperties[i]);
                    }

                    for(int i = 0; i < tradeProperties.size(); i++){
                        players[playerTradeWith].addProperty(tradeProperties[i]);
                    }
                    players[playerTradeWith].addAmountOfCash(cashTrade);
                    players[playerTradeWith].addAmountOfCash(-1 * cashTradeFor);
                    for(int i = 0; i < tradeForProperties.size(); i++){
                        players[playerTradeWith].removePoperty(tradeForProperties[i]);
                    }
                } 
            }
        }     
    }
}