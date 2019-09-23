//Programmer: Brendan Dunne   Date: 29 April 2017
//Description: Definition of random number generation function
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "header.h"
using namespace std;

int randVal(const int lower, const int upper)
{
    return (lower > upper) ? 0 : lower + rand() % (upper - lower + 1);
}
