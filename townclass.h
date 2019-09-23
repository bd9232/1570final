//Programmer: Brendan Dunne   Date: 29 April 2017
//Description: Declaration of Town class
#ifndef TOWNCLASS_H
#define TOWNCLASS_H
#include <iostream>
#include "header.h"
using namespace std;

class Town
{
  private:
    loc size[MAX][MAX];//the pointless variable name is leftover from hw9, once
	                   //I realized it was dumb it was too late
    short town_actualSize;
    short town_bullies;
    short town_houses;
	
    //Pre: a Town object is created
    //Description: sets the dimensons for the Town, including its actual size,
    //             the number of bullies, and the number of houses
    //Post: Town's dimensions are all set
    void setMembers(const int SIZE, const int HOUSEMAX, const int BULLYMAX);
	
    //Pre: a Town object is created and its dimensions set
    //Description: clears the grid (size[MAX][MAX]) of the created Town object
    //Post: the created Town object's grid is cleared
    void clearTown(const int MAX);
	
    //Pre: a Town object is created, dimensions set, and its grid is cleared
    //Description: builds a wall around the Town's actual size, less than MAX
    //Post: Town's wall is built
    void buildWall(const int MAX);
	
    //Pre: a Town object's dimensions are set, grid is cleared, and a wall
    //     built around the determined edges
    //Description: fills the inside of the Town with bullies, houses, and
    //             empty spaces
    //Post: Town's interior is filled with bullies, houses, spaces
    void fillTown();
	
	
  public:
    //Pre: none
    //Description: constructor that creates a Town object, calls setMembers, 
    //             clearTown, buildWall, and fillTown functions
    //Post: a Town object is created using the three functions listed above
    Town(const int MAX, const int SIZE, const int HOUSEMAX,
	     const int BULLYMAX);
		 
    //Pre: a Town object has been created and set properly
    //Description: calls functions to place shrines and fans in the town
    //Post: shrines and fans are placed in the town
    void extraStuff(const int shrinenum, const int fannum);
	
    //Pre: a Town object has been created and set properly
    //Description: places a number of "magic shrines" within the Town walls
    //Post: shrines are placed in the Town 
    void shrinePlace(const int shrinenum);
	
    //Pre: a Town object has been created and set properly
    //Description: places a number of fans within the town walls
    //Post: fans are placed in the town
    void fanPlace(const int fannum);

    //Pre: none
    //Description: defines how to print out a Town object
    //Post: how to print out a Town object is defined
    friend ostream& operator <<(ostream &out, Town &source);
    friend class Tailor;
    friend class Bully;
    friend class PhantomPant;
};
	
#endif
