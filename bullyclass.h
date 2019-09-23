//Programmer: Brendan Dunne   Date: 29 April 2017
//Description: Declaration of Bully class
#ifndef BULLYCLASS_H
#define BULLYCLASS_H
#include <iostream>
#include <cstring>
#include "header.h"
#include "townclass.h"
#include "tailorclass.h"
using namespace std;

class Bully
{
  private:
    string bully_name;
    short bully_power;
    short bully_chance;
  public:
  
    //Pre: none
    //Description: constructor that creates a Bully object, and assigns it
    //             a random name and punching power
    //Post: Bully object is created, with variables set
    Bully();
	
    //Pre: Town and Tailor objects both exist, Tailor is adjacent to a Bully
    //Description: Bully attempts to punch the tailor, with 80% chance of
    //             success
    //Post: if successful, Tailor is relocated, Tailor health is reduced by 10,
    //      Bully takes power percentage of Tailor money, Bully's didPunch is
    //      set to true, and a PhantomPant object is possibly placed. Else, 
    //      Bully's name and a random message are output
    bool punch(Tailor &tailor, Town &town);
};

#endif
