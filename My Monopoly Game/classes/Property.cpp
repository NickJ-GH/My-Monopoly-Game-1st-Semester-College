#include <iostream>
#include <array>
#include <vector>
#include "Property.h"

using namespace std;

/*
    this includes the constructors for the Bank class

    this also conatians the setters and getter fot the Bank class

*/

// default constructor
Property::Property(){
    propertyName = "";
    group = "";
    bankPrice = 0;
    rent = 0;
    amountOfHouses = 0;
    owner = 6;
}

//parameterized constructor
Property::Property(string name, string gp, int price, bool own, int in_rent){
    propertyName = name;
    group = gp;
    bankPrice = price;
    owned = false;
    rent = in_rent;
    amountOfHouses = 0;
    owner = 6;
}

//getters/setters

string Property::getPropertyName(){
    return propertyName;
}


string Property::getGroup(){
    return group;
}

int Property::getBankPrice(){
    return bankPrice;
}

int Property::getMortgagePrice(){
    return .6 * bankPrice;
}

bool Property::isOwned(){
    return owned;
}

void Property::setOwned(){
    owned = true;
}

void Property::setUnOwned(){
    owned = false;
}

int Property::getRent(){
    return rent;
}

int Property::getAmountOfHouses(){
    return amountOfHouses;
}

void Property::addAmountOfHouses(int am){
    amountOfHouses += am;
}

string Property::getLineOne(){
    return lineOne;
}

void Property::setLineOne(string line){
    lineOne = line;
}

string Property::getLineTwo(){
    return lineTwo;
}

void Property::setLineTwo(string line){
    lineTwo = line;
}

string Property::getLineThree(){
    return lineThree;
}

void Property::setLineThree(string line){
    lineThree = line;
}

string Property::getLineFour(){
    return lineFour;
}

void Property::setLineFour(string line){
    lineFour = line;
}

int Property::getOwner(){
    return owner;
}

void Property::setOwner(int own){
    owner = own;
}