//Programmer: Brendan Dunne   Date: 29 April 2017
//Description: Declaring constants, structs, and random number generation prototype
#ifndef HEADER_H
#define HEADER_H
#include <iostream>
using namespace std;

const int MAX = 25;
const int PANTS = 3;
const int BULLIES = 4;
const int BULLYMAX = 10;
const int HOUSEMAX = 40;
const int SIZE = 17;
const int STEPMAX = 1000;
//const int SYMPATHY_FOR_HARDCODING_VALUES = 0;

struct loc
{
  char what;
  bool havePants;
};

//Pre: values given for lower and upper must be valid integers
//Description: generates a random integer of a value from lower to upper
//Post: random integer is generated, from lower to upper, inclusive
int randVal(const int lower, const int upper);



#endif
