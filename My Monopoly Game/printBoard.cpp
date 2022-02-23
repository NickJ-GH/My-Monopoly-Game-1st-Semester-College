// CS1300 Fall 2021
// Author: Nicholas Johns
// Recitation: 315 – Teo Price-Broncucia
// Project 3 

#include <fstream>
#include <iostream>
#include <array>
#include "printBoarders.cpp"
#include "creator.cpp"

using namespace std;

/*
    This function goes and prints the whole board

*/

void printBoard(){

    wholeBoarder();
    for(int i = 4; i < 19; i ++){
        cout << "|" << boardMap [i].getLineTwo();
    }
    cout << "|" << endl;
    for(int i = 4; i < 19; i ++){
        cout << "|" << boardMap [i].getLineOne();
    }
    cout << "|" << endl;
    for(int i = 4; i < 19; i ++){
        cout << "|" << boardMap [i].getLineThree();
    }
    cout << "|" << endl;
    for(int i = 4; i < 19; i ++){
        cout << "|" << boardMap [i].getLineFour();
    }
    cout << "|" << endl;
    wholeBoarder();
    cout << "|" << boardMap [3].getLineTwo() << "|";
    for(int i = 0; i < 129; i++){
        cout << " ";
    }
    cout << "|" << boardMap [19].getLineTwo() << "|" << endl;
    cout << "|" << boardMap [3].getLineOne() << "|";
    cout << "     $";
    for(int i = 0; i < 117; i++){
        cout << " ";
    }
    cout << "$     ";
    cout << "|" << boardMap [19].getLineOne() << "|" << endl;
    cout << "|" << boardMap [3].getLineThree() << "|";
    for(int i = 0; i < 129; i++){
        cout << " ";
    }
    cout << "|" << boardMap [19].getLineThree() << "|" << endl;
    cout << "|" << boardMap [3].getLineFour() << "|";
    for(int i = 0; i < 129; i++){
        cout << " ";
    }
    cout << "|" << boardMap [19].getLineFour() << "|" << endl;
    partBoarder();
    cout << "|" << boardMap [2].getLineTwo() << "|";
    for(int i = 0; i < 26; i++){
        cout << " ";
    }
    cout << "|\\   /|   |-----|   |\\    |   |-----|   |-----|   |-----|   |         \\     /";
    for(int i = 0; i < 26; i++){
        cout << " ";
    }
    cout << "|" << boardMap [20].getLineTwo() << "|" << endl;
    cout << "|" << boardMap [2].getLineOne() << "|";
    for(int i = 0; i < 26; i++){
        cout << " ";
    }
    cout << "| \\ / |   |     |   | \\   |   |     |   |     |   |     |   |          \\ _ / ";
    for(int i = 0; i < 26; i++){
        cout << " ";
    }
    cout << "|" << boardMap [20].getLineOne() << "|" << endl;
    cout << "|" << boardMap [2].getLineThree() << "|";
    for(int i = 0; i < 26; i++){
        cout << " ";
    }
    cout << "|  0  |   |     |   |   \\ |   |     |   |-----|   |     |   |            |   ";
    for(int i = 0; i < 26; i++){
        cout << " ";
    }
    cout << "|" << boardMap [20].getLineThree() << "|" << endl;
    cout << "|" << boardMap [2].getLineFour() << "|";
    for(int i = 0; i < 26; i++){
        cout << " ";
    }
    cout << "|     |   |-----|   |    \\|   |-----|   |         |-----|   |-----|      |   ";
    for(int i = 0; i < 26; i++){
        cout << " ";
    }
    cout << "|" << boardMap [20].getLineFour() << "|" << endl;
    partBoarder();
    cout << "|" << boardMap [1].getLineTwo() << "|";
    for(int i = 0; i < 129; i++){
        cout << " ";
    }
    cout << "|" << boardMap [21].getLineTwo() << "|" << endl;
    cout << "|" << boardMap [1].getLineOne() << "|";
    cout << "     $";
    for(int i = 0; i < 117; i++){
        cout << " ";
    }
    cout << "$     ";
    cout << "|" << boardMap [21].getLineOne() << "|" << endl;
    cout << "|" << boardMap [1].getLineThree() << "|";
    for(int i = 0; i < 129; i++){
        cout << " ";
    }
    cout << "|" << boardMap [21].getLineThree() << "|" << endl;
    cout << "|" << boardMap [1].getLineFour() << "|";
    for(int i = 0; i < 129; i++){
        cout << " ";
    }
    cout << "|" << boardMap [21].getLineFour() << "|" << endl;
    wholeBoarder();
    cout << "|" << boardMap [0].getLineTwo();
    for(int i = 35; i >21; i --){
        cout << "|" << boardMap [i].getLineTwo();
    }
    cout << "|" << endl;
    cout << "|" << boardMap [0].getLineOne();
    for(int i = 35; i >21; i --){
        cout << "|" << boardMap [i].getLineOne();
    }
    cout << "|" << endl;
    cout << "|" << boardMap [0].getLineThree();
    for(int i = 35; i >21; i --){
        cout << "|" << boardMap [i].getLineThree();
    }
    cout << "|" << endl;
    cout << "|" << boardMap [0].getLineFour();
    for(int i = 35; i >21; i --){
        cout << "|" << boardMap [i].getLineFour();
    }
    cout << "|" << endl;
    wholeBoarder();
}