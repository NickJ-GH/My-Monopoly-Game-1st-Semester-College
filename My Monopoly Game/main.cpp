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
#include "classes/Property.cpp"
#include "classes/Player.cpp"
#include "classes/Card.cpp"
#include "classes/Bank.cpp"
#include "startMenue.cpp"
#include "printBoard.cpp"
#include "printPlayerStats.cpp"
#include "rollDice.cpp"
#include "menueOptions.cpp"
#include "cpuOfferTrade.cpp"
#include "loto.cpp"
#include "cardNum.cpp"
#include "sort.cpp"
#include "checkGame.cpp"

using namespace std;

/*
    in this page, I simply import all of the functions and classes I hace and run the program through my main

    ^ this is the page with the main funtion that gets the code to work/run

    for this, there is a switch statment that calls a menut and all of the options

    the switch stamtent is in a do while so that it does in a continues loop until someone enters the quit number

*/

int main (){
    char inputChar;
    int inputInteger;
    int cash = 2500;
    int numberOfPlayers = 5;
    int playerTurn = 0;
    int cardNum = 0;

    startMenue();
    do {
        cin >> inputInteger;
    } while (inputInteger > 5 || inputInteger < 3);
    numberOfPlayers = inputInteger;

    create(numberOfPlayers, cash);

    //cout << Community[cardNum].getDirections() << endl;

    do {
        for (int i = 0; i < 12; i++){
            cout << endl;
        }
        
        cout << "Player Turn: " << players[playerTurn].getPlayerName() << endl;
 
        for(int i = 0; i < 36; i++){
            boardMap[i].setLineFour(formatSpotLine(""));
        }

        for(int i = 0; i < players.size(); i++){
            string name(1,players[i].getPlayerName());
            if(boardMap [players[i].getPosition()].getLineFour() == "         "){
                boardMap [players[i].getPosition()].setLineFour(name + "        ");
            } else {
                boardMap [players[i].getPosition()].setLineFour( name + "," + boardMap [players[i].getPosition()].getLineFour().substr(0, 7) );
            } 
        }

        printBoard();
        printPlayerStats();
        menueOptions ();
        
        cin >> inputInteger;

        switch(inputInteger){
            case 0:
                cout << "Game is Over"<< endl;
                return 0;
                break;
            case 1:
                players [playerTurn].addPosition(rollDice());
                //* the below is for the user
                if (playerTurn == 0){
                    //* the first if statment is for if the property is one that the user can buy and it is up for sale
                    if(boardMap[players[playerTurn].getPosition()].getBankPrice() != 0 && boardMap[players[playerTurn].getPosition()].isOwned() == false){
                        cout << endl << endl << "Do you want to buy the property?" << endl << "(Y/N)" << endl << endl;
                        do{
                            cin >> inputChar;
                        }while (inputChar != 'Y' && inputChar != 'N');

                        if (inputChar == 'Y'){
                            boardMap[players[playerTurn].getPosition()].setOwned();
                            boardMap[players[playerTurn].getPosition()].setOwner(playerTurn);
                            players[playerTurn].addAmountOfCash(- boardMap[players[playerTurn].getPosition()].getBankPrice());
                            players[playerTurn].addProperty(players[playerTurn].getPosition());
                            theBank.addlottery(boardMap[players[playerTurn].getPosition()].getBankPrice()*.8);

                            cout << endl << endl << "Do you want to make a trade?" << endl << "(Y/N)" << endl << endl;
                            do{
                                cin >> inputChar;
                            }while (inputChar != 'Y' && inputChar != 'N');
                            if (inputChar == 'Y'){
                                proposetrade(numberOfPlayers);
                            }
                        }
                    //* this if statment is the player has a community chest card
                    } else if ((players[playerTurn].getPosition()) == 5 || 14 || 24 || 30){
                        cout << endl << endl << endl << "You got a Community Chest Card" << endl << endl;
                        cardNum++;
                        cardNum = (cardNum%3);

                        cout << Community[cardNum].getDirections() << endl;

                        switch(cardNum){
                            case 0:
                                players[playerTurn].addAmountOfCash(50);
                                break;
                            case 1:
                                players[playerTurn].addAmountOfCash(75);
                                break;
                            case 2:
                                players[playerTurn].addAmountOfCash(20);
                                break;
                            case 3:
                                players[playerTurn].addAmountOfCash(18);
                                break;
                            default:
                                break;
                        }

                        cout << endl << "Press C to continue" << endl;
                        cin >> inputChar;

                    //* this if statment is the player has a chance card
                    } else if ((players[playerTurn].getPosition()) == 7 || 16 || 28 || 32){
                        cout << endl << endl << endl << "You got a Chance Card" << endl << endl;
                        cardNum++;
                        cardNum = (cardNum%3);

                        cout << Chance[cardNum].getDirections() << endl;

                        switch(cardNum){
                            case 0:
                                players[playerTurn].addAmountOfCash(100);
                                break;
                            case 1:
                                players[playerTurn].addAmountOfCash(-50);
                                break;
                            case 2:
                                players[playerTurn].addAmountOfCash(20);
                                break;
                            case 3:
                                players[playerTurn].addAmountOfCash(150);
                                players[playerTurn].setPosition(4);
                                break;
                            default:
                                break;
                        }

                        cout << endl << "Press C to continue" << endl;
                        cin >> inputChar;

                    //* this is if player is on tax spot
                    } else if ((players[playerTurn].getPosition()) == 34){
                        players[playerTurn].addAmountOfCash(- 75);

                    //* this is if the player lands on Go to jail
                    } else if ((players[playerTurn].getPosition()) == 22){
                        players[playerTurn].setPosition(4);
                        players[playerTurn].addAmountOfCash(-50);

                    //* this is if the player lands on free parking
                    } else if ((players[playerTurn].getPosition()) == 18){
                        cout << endl << "Guess a number between 1 and 5" << endl;
                        do{
                            cin >> inputInteger;
                        }while (inputInteger < 1 && inputInteger > 5);

                        if(inputInteger == lotto()){
                            players[0].addAmountOfCash(theBank.getlottery());
                            theBank.addlottery(-theBank.getlottery());
                            cout << "Congradulations! You won the Lotery! Press C to continue." << endl;
                            cin >> inputChar;
                        } else {
                            cout << "You didn't win the Lotery. Press C to continue." << endl;
                            cin >> inputChar;
                        }
                    //* this is if the property is owned by someone
                    } else {
                        if(boardMap[players[playerTurn].getPosition()].getAmountOfHouses() == 0){
                            players[playerTurn].addAmountOfCash(- boardMap[players[playerTurn].getPosition()].getRent());
                            players[boardMap[players[playerTurn].getPosition()].getOwner()].addAmountOfCash(boardMap[players[playerTurn].getPosition()].getRent());
                        } else {
                            players[playerTurn].addAmountOfCash((-1) * (boardMap[players[playerTurn].getPosition()].getRent()) * (1  + .2 * boardMap[players[playerTurn].getPosition()].getAmountOfHouses()));
                            players[boardMap[players[playerTurn].getPosition()].getOwner()].addAmountOfCash((boardMap[players[playerTurn].getPosition()].getRent()) * (1  + .2 * boardMap[players[playerTurn].getPosition()].getAmountOfHouses()));
                        }
                    }
                } else {
                //* the below is for the CPU Players
                    if(boardMap[players[playerTurn].getPosition()].getBankPrice() != 0 && boardMap[players[playerTurn].getPosition()].isOwned() == false){
                        //* the first if statment is for if the property is one that the user can buy and it is up for sale
                        if ((players[playerTurn].getAmountOfCash() - boardMap[players[playerTurn].getPosition()].getBankPrice()) >= 85){
                            boardMap[players[playerTurn].getPosition()].setOwned();
                            boardMap[players[playerTurn].getPosition()].setOwner(playerTurn);
                            players[playerTurn].addAmountOfCash(- boardMap[players[playerTurn].getPosition()].getBankPrice());
                            players[playerTurn].addProperty(players[playerTurn].getPosition());
                            theBank.addlottery(boardMap[players[playerTurn].getPosition()].getBankPrice()*.8);

                            cpuOfferTrade(numberOfPlayers, playerTurn);
                        }
                      //* this if statment is the player has a community chest card  
                    } else if ((players[playerTurn].getPosition()) == 5 || 14 || 24 || 30){
                        cardNum++;
                        cardNum = (cardNum%3);

                        switch(cardNum){
                            case 0:
                                players[playerTurn].addAmountOfCash(50);
                                break;
                            case 1:
                                players[playerTurn].addAmountOfCash(75);
                                break;
                            case 2:
                                players[playerTurn].addAmountOfCash(20);
                                break;
                            case 3:
                                players[playerTurn].addAmountOfCash(18);
                                break;
                            default:
                                break;
                        }

                    //* this if statment is the player has a chance card
                    } else if ((players[playerTurn].getPosition()) == 7 || 16 || 28 || 32){
                        cardNum++;
                        cardNum = (cardNum%3);

                        switch(cardNum){
                            case 0:
                                players[playerTurn].addAmountOfCash(100);
                                break;
                            case 1:
                                players[playerTurn].addAmountOfCash(-50);
                                break;
                            case 2:
                                players[playerTurn].addAmountOfCash(20);
                                break;
                            case 3:
                                players[playerTurn].addAmountOfCash(150);
                                players[playerTurn].setPosition(4);
                                break;
                            default:
                                break;
                        }
                    //* this is if player is on tax spot
                    } else if ((players[playerTurn].getPosition()) == 34){
                        players[playerTurn].addAmountOfCash(- 75);

                    //* this is if player lands on go to jail
                    } else if ((players[playerTurn].getPosition()) == 22){
                        players[playerTurn].setPosition(4);
                        players[playerTurn].addAmountOfCash(-50);

                    //* this is if the player lands on free parking
                    } else if ((players[playerTurn].getPosition()) == 18){
                        if(3 == lotto()){
                            players[playerTurn].addAmountOfCash(theBank.getlottery());
                            theBank.addlottery(-theBank.getlottery());
                            cin >> inputChar;
                        } 
                    } else {
                        if(boardMap[players[playerTurn].getPosition()].getAmountOfHouses() == 0){
                            players[playerTurn].addAmountOfCash(- boardMap[players[playerTurn].getPosition()].getRent());
                            players[boardMap[players[playerTurn].getPosition()].getOwner()].addAmountOfCash(boardMap[players[playerTurn].getPosition()].getRent());
                        } else {
                            players[playerTurn].addAmountOfCash((-1) * (boardMap[players[playerTurn].getPosition()].getRent()) * (1  + .2 * boardMap[players[playerTurn].getPosition()].getAmountOfHouses()));
                            players[boardMap[players[playerTurn].getPosition()].getOwner()].addAmountOfCash((boardMap[players[playerTurn].getPosition()].getRent()) * (1  + .2 * boardMap[players[playerTurn].getPosition()].getAmountOfHouses()));
                        }
                    }
                }

                playerTurn++;
                playerTurn = (playerTurn)%(numberOfPlayers);
                break;
            case 2:
                proposetrade(numberOfPlayers);
                break;
            case 3 :{
                vector<int> vectPlayerWealth;
                vector<int> vectPlayerWealthOutcome;
                vector<int> playerNamesvec;

                int player0 = players[0].getAmountOfCash();
                for (int i = 0; i < players[0].getAmmountOfProperties(); i++){
                    player0 += boardMap[players[0].getPropertyAt(i)].getBankPrice();
                }
                int player1 = players[1].getAmountOfCash();
                for (int i = 0; i < players[1].getAmmountOfProperties(); i++){
                    player0 += boardMap[players[1].getPropertyAt(i)].getBankPrice();
                }
                int player2 = players[2].getAmountOfCash();
                for (int i = 0; i < players[2].getAmmountOfProperties(); i++){
                    player0 += boardMap[players[2].getPropertyAt(i)].getBankPrice();
                }

                vectPlayerWealth.push_back(player0);
                vectPlayerWealth.push_back(player1);
                vectPlayerWealth.push_back(player2);

                switch(numberOfPlayers){
                    case 4: {
                        int player3 = players[3].getAmountOfCash();
                        for (int i = 0; i < players[2].getAmmountOfProperties(); i++){
                            player0 += boardMap[players[3].getPropertyAt(i)].getBankPrice();
                        }
                        vectPlayerWealth.push_back(player3);
                        } break; 
                    case 5: { 
                        int player3 = players[3].getAmountOfCash();
                        for (int i = 0; i < players[2].getAmmountOfProperties(); i++){
                            player0 += boardMap[players[3].getPropertyAt(i)].getBankPrice();
                        }
                        int player4 = players[4].getAmountOfCash();
                        for (int i = 0; i < players[2].getAmmountOfProperties(); i++){
                            player0 += boardMap[players[4].getPropertyAt(i)].getBankPrice();
                        }
                        vectPlayerWealth.push_back(player3);
                        vectPlayerWealth.push_back(player4);
                        } break; 
                    default:
                        break; 
                }

                vectPlayerWealthOutcome = sort(vectPlayerWealth);

                cout << "Here is the leaderboard:" << endl;
                for(int i = 0; i < (vectPlayerWealthOutcome.size()/2); i++){
                    cout << "#" << (i+1) << " -   " << players[vectPlayerWealthOutcome[i]].getPlayerName() << endl;
                }
                cout << endl ;

                cout << "Enter C to continue" << endl;
                cin >> inputChar;
                } break;
            case 4:
                cout << endl << endl << endl << endl << endl << "Your properties are:" << endl;
                for (int i = 0; i < players[0].getAmmountOfProperties(); i++){
                    cout << (players[0].getPropertyAt(i) +1 ) << "   " << boardMap[players[0].getPropertyAt(i)].getPropertyName() << endl;
                }
                cout << "Sorry, this trade has been denied." << endl;
                cout << "Enter C to continue" << endl;
                cin >> inputChar;
                break;
            case 5:
                cout << endl << endl << endl << endl << endl << "Your have:" << endl;
                cout << "$" << players[0].getAmountOfCash() << endl;
                cout << "Sorry, this trade has been denied." << endl;
                cout << "Enter C to continue" << endl;
                cin >> inputChar;
                break;
            case 6:
                cout << endl << endl << endl << endl << endl << "Your properties are:" << endl;
                for (int i = 0; i < players[0].getAmmountOfProperties(); i++){
                    cout << (players[0].getPropertyAt(i) +1 ) << "   " << boardMap[players[0].getPropertyAt(i)].getPropertyName() << endl;
                }
                cout << endl << "What property would you like to sell to the bank?" << endl;
                
                cin >> inputInteger;
                boardMap[inputInteger -1].setUnOwned();
                boardMap[inputInteger -1].setOwner(6);
                players[0].removePoperty(inputInteger -1);
                players[0].addAmountOfCash(boardMap[inputInteger -1].getBankPrice() * .8);  
                cout << "Sorry, this trade has been denied." << endl;
                cout << "Enter C to continue" << endl;
                cin >> inputChar;
                break;
            case 7:
                cout << endl << endl << endl << endl << endl << "The lottery amount is:" << endl;
                cout << "$" << theBank.getlottery() << endl;
                cout << "Sorry, this trade has been denied." << endl;
                cout << "Enter C to continue" << endl;
                cin >> inputChar;
                break;
            case 8: {
                int propertyToAddHouse;
                cout << "Enter a property you would like to add a house to:" << endl;
                cin >> propertyToAddHouse;

                if(inputInteger == 2 || 4 || 7){
                    if(boardMap[2 -1].getOwner() == playerTurn
                    && boardMap[4 -1].getOwner() == playerTurn
                    && boardMap[7 -1].getOwner() == playerTurn){
                        cout << "How many houses would you like to add?" << endl;
                        cin >> inputInteger;
                        boardMap[propertyToAddHouse-1].addAmountOfHouses(inputInteger);
                        players[playerTurn].addAmountOfCash(- boardMap[propertyToAddHouse-1].getBankPrice()*.25);
                    }
                    
                } else if (inputInteger == 9 || 10 || 12 ){
                    if(boardMap[9 -1].getOwner() == playerTurn
                    && boardMap[10 -1].getOwner() == playerTurn
                    && boardMap[12 -1].getOwner() == playerTurn){
                        cout << "How many houses would you like to add?" << endl;
                        cin >> inputInteger;
                        boardMap[propertyToAddHouse-1].addAmountOfHouses(inputInteger);
                        players[playerTurn].addAmountOfCash(- boardMap[propertyToAddHouse-1].getBankPrice()*.25);
                    }

                } else if (inputInteger == 13 || 14 || 16 ){
                    if(boardMap[13 -1].getOwner() == playerTurn
                    && boardMap[14 -1].getOwner() == playerTurn
                    && boardMap[16 -1].getOwner() == playerTurn){
                        cout << "How many houses would you like to add?" << endl;
                        cin >> inputInteger;
                        boardMap[propertyToAddHouse-1].addAmountOfHouses(inputInteger);
                        players[playerTurn].addAmountOfCash(- boardMap[propertyToAddHouse-1].getBankPrice()*.25);
                    }

                } else if (inputInteger == 18 || 20 || 22 ){
                    if(boardMap[18 -1].getOwner() == playerTurn
                    && boardMap[20 -1].getOwner() == playerTurn
                    && boardMap[22 -1].getOwner() == playerTurn){
                        cout << "How many houses would you like to add?" << endl;
                        cin >> inputInteger;
                        boardMap[propertyToAddHouse-1].addAmountOfHouses(inputInteger);
                        players[playerTurn].addAmountOfCash(- boardMap[propertyToAddHouse-1].getBankPrice()*.25);
                    }
                    
                } else if (inputInteger == 24 || 26 || 27 ){
                    if(boardMap[24 -1].getOwner() == playerTurn
                    && boardMap[26 -1].getOwner() == playerTurn
                    && boardMap[27 -1].getOwner() == playerTurn){
                        cout << "How many houses would you like to add?" << endl;
                        cin >> inputInteger;
                        boardMap[propertyToAddHouse-1].addAmountOfHouses(inputInteger);
                        players[playerTurn].addAmountOfCash(- boardMap[propertyToAddHouse-1].getBankPrice()*.25);
                    }

                } else if (inputInteger == 34 || 36){
                    if(boardMap[34 -1].getOwner() == playerTurn
                    && boardMap[26 -1].getOwner() == playerTurn){
                        cout << "How many houses would you like to add?" << endl;
                        cin >> inputInteger;
                        boardMap[propertyToAddHouse-1].addAmountOfHouses(inputInteger);
                        players[playerTurn].addAmountOfCash(- boardMap[propertyToAddHouse-1].getBankPrice()*.25);
                    }
                }
                } break;
            default:
                break;
        }

        if (checkGame(numberOfPlayers) == 0){
            return 0;
        }

    } while (inputInteger != 0);

    return 0;
}