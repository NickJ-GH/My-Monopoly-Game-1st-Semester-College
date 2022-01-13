#ifndef Property_H 
#define Property_H

#include <fstream>
#include <iostream>
#include <array>
#include <vector>

using namespace std;

/*
    this class is for properties

*/

class Property {
    public: 

        // default constructor
        Property();

        // parameterized constructor
        Property(string name, string gp, int price, bool own, int in_rent);

        // gettrs and setters
        string getPropertyName();
        string getGroup();
        int getBankPrice();
        int getMortgagePrice();
        bool isOwned();
        void setOwned();
        void setUnOwned();
        int getRent();
        int getAmountOfHouses();
        void addAmountOfHouses(int am);
        string getLineOne();
        void setLineOne(string line);
        string getLineTwo();
        void setLineTwo(string line);
        string getLineThree();
        void setLineThree(string line);
        string getLineFour();
        void setLineFour(string line);
        int getOwner();
        void setOwner(int own);

    private:
        string propertyName;
        string group;
        int bankPrice;
        bool owned;
        int rent;
        int amountOfHouses;
        string lineOne;
        string lineTwo;
        string lineThree;
        string lineFour;
        int owner;
};

#endif