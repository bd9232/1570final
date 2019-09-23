//Programmer: Brendan Dunne   Date: 29 April 2017
//Description: Declaration of Tailor class
#ifndef TAILORCLASS_H
#define TAILORCLASS_H
#include <iostream>
#include <cstring>
#include "header.h"
#include "townclass.h"
using namespace std;

class Tailor
{
  private:
    string t_name;
    float t_money;
    int t_row;
    int t_column;
    char t_represent;
    bool t_alive;
    short t_health;
    short t_pants;
  public:
    //Pre: none 
    //Description: constructor that creates a Tailor object, and initializes
    //             its values, taking arguments for its name and character
    //Post: Tailor object is created with name and character provided
    Tailor(const string name, const char rep);
	
    //Pre: a Town and Tailor object both exist
    //Description: takes the Tailor object, and places its representing 
    //             character in a random open location in the Town
    //Post: Tailor is placed randomly in the Town
    void placeMe(Town &town);
	
    //Pre: a Town and Tailor both exist, and Tailor has been placed
    //Description: attempts to move the Tailor's representing character to a
    //             a random, open, adjacent spot to its current location
    //Post: if possible, Tailor is moved randomly by one space either
    //      horizontally or vertically
    void randWalk(Town &source);
	
    //Pre: a Town and Tailor both exist, and there are no Bullies next to
    //     the Tailor
    //Description: Tailor checks for houses around its character, and if
    //             houses are discovered, a trade attempt is made
    //Post: if possible, Tailor engages in attempted trade with an adjacent
    //      house
    void trade(Town &source);
	
    //Pre: a Town and Tailor both exist, and Tailor has been placed
    //Description: Tailor object checks to see if and bullies are adjacent to
    //             its character
    //Post: if Tailor finds a Bully, interaction occurs
    bool check(Town &source);
	
    //Pre: a Town and Tailor both exist, and Tailor has been placed
    //Description: Tailor object checks to see if any shrines are adjacent
    //Post: if true, for remainder of step, Tailor cannot be hurt, killed, and
    //      receives 10 health. PhantomPants also do not move
    bool shrineCheck (Town &town);
	
    //Pre: a Tailor exists in a Town
    //Description: checks to see if the conditions to end the simulation have
    //             been met
    //Post: if end conditions have been met, returns false. If not, 
    //      returns true
    bool keepSim();
	
    //Pre: end conditions have been met, and simulation has stopped
    //Description: checks what conditions were met, and prints out results
    //Post: depending on ending conditions, final results are printed out
    string endReport();
	
    //Pre: none 
    //Description: defines how to print out a Tailor-class object
    //Post: how to print out a Tailor-class object is defined
    friend ostream& operator <<(ostream &out, Tailor &source);
    friend class Bully;
    friend class PhantomPant;
};

#endif
