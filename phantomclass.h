//Programmer: Brendan Dunne   Date: 29 April 2017
//Description: Declaration of PhantomPant class
#ifndef PHANTOMCLASS_H
#define PHANTOMCLASS_H
#include <iostream>
#include "header.h"
#include "townclass.h"
#include "tailorclass.h"
using namespace std;

class PhantomPant
{
  private:
    int pant_row;
    int pant_column;
    char pant_represent;
    bool pant_inPlay;
  public:
  
    //Pre: none 
    //Description: constructor that creates a PhantomPant-type object, sets its
    //             location, representing character, and in-play variables
    //Post: PhantomPant-type object is created and values are set
    PhantomPant();

    //Pre: PhantomPant object must exist, and a Bully must have successfully 
    //     punched the Tailor
    //Description: places the PhantomPant in a random location in the Town
    //Post: PhantomPant is placed randomly in the Town
    void placeMe(Town &town);

    //Pre: PhantomPant object must exist
    //Description: returns the in-play state of a PhantomPant object
    //Post: if true, the PhantomPant can chase the Tailor. If not, no chase 
    //      can occur
    bool checkInPlay();

    //Pre: PhantomPant object must exist and be in play
    //Description: 25% chance the PhantomPant object will attempt to walk 
    //             towards the Tailor object
    //Post:  PhantomPant object chases Tailor, if allowed
    void chase(Tailor &tailor, Town &town);

    //Pre: PhantomPant object must have attempted to chase the Tailor
    //Description: checks if Tailor is adjacent to the PhantomPant
    //Post: if so, Tailor's alive state is set to false. If not, no action
    void kill(Tailor &tailor, Town &town);

    	
    //Pre: PhantomPant object must have attempted to chase the Tailor
    //Description: checks if a bully is adjacent to the PhantomPant
    //Post: if so, there is a 25% chance the bully will be "killed" and
    //      removed from the town
    void bullyKill(Town &town);
	
    //Pre: PhantomPant object must be in play
    //Description: checks any fans are adjacent to the PhantomPant
    //Post: if so, the PhantomPant's placeMe function is called, and it is
    //      unable to step or kill for the remainder of step
    bool check(Town &town);
};

#endif
