// CS1300 Fall 2021
// Author: Nicholas Johns
// Recitation: 315 – Teo Price-Broncucia
// Project 3 

#include <fstream>
#include <iostream>
#include <array>

using namespace std;

/*
    this is the split funtion which takes a line that is a string and splits it up

*/

int split(string split, char separator, string array [], int size){
    
    const int splitLength = split.length();

    if (splitLength == 0){
        return 0;
    }

    int whereToSplit [size-1];
    int spotIn_whereToSplit = 0;
    int howManySplits = 0;

    for (int i = 0; i < splitLength; i++){
        if (split.at(i) == separator){
            whereToSplit [spotIn_whereToSplit] = i;
            spotIn_whereToSplit ++;
            howManySplits ++;
        }
    }

    if (howManySplits == 0){
        array [0] = split;
        return 1;
    } else if (howManySplits > (size-1)){

        array [0] = split.substr(0, whereToSplit [0]);

        for (int i = 1; i < size; i++){ 
            array [i] = split.substr(whereToSplit [i-1]+1, whereToSplit [i]-whereToSplit [i-1]-1);
        }

        return -1;
    }

    array [0] = split.substr(0, whereToSplit [0]);

    for (int i = 1; i < size-1; i++){ 
        array [i] = split.substr(whereToSplit [i-1]+1, whereToSplit [i]-whereToSplit [i-1]-1);
    }

    array [size-1] = split.substr(whereToSplit [size-2]+1);

    return (howManySplits+1);
}