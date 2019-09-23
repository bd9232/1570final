//Programmer: Brendan Dunne   Date: 29 April 2017
//Description: Definitions of Bully-class functions
#include <iostream>
#include <cstring>
#include <fstream>
#include "bullyclass.h"
using namespace std;

Bully :: Bully()
{
  ifstream fin;
  fin.open("bullies.dat");
  int temp = randVal(1,4);
  //gets bully a random name from the file
  for(int i=1;i<=temp;i++)
  {	
    getline(fin,bully_name,'\n');
  }
  bully_power=randVal(30, 50);
  bully_chance=80;
}

bool Bully :: punch(Tailor &tailor, Town &town)
{
  ifstream fin;
  bool didPunch;
  int chance = randVal(1,100);
  float force = bully_power;
  //determines how much money the bully will take, depending on bully's power
  float moneytake =force/100;
  if (chance<=bully_chance)
  {
    didPunch = true;
    tailor.t_health=tailor.t_health-10;
    tailor.t_money=tailor.t_money-(moneytake*tailor.t_money);
    tailor.placeMe(town);
      cout<<tailor.t_name<<": Ouch! That really hurt!  ";
    //checks and see how many PhantomPant objects currently are in the town
    //if there are less than 3, it will remove one pair of pants from the
    //Tailor to allow placement of a PhantomPant object
    int pantscounter=0;
    for(int i=0; i<MAX; i++)
    {
      for(int j=0; j<MAX; j++)
      {
        if(town.size[i][j].what=='P')
        {
          pantscounter++;
        }
      }
    }  
    if (pantscounter<3)
    {
      tailor.t_pants--;
    }
  }
  else
  {
    didPunch = false;
    fin.open("messages.dat");
    char sentence[100];
    int temp = randVal(1,7);
    //chooses random message for bully to say
    for(int i=1;i<=temp;i++)
    {
      fin.getline(sentence, 100);
    }
    int length=strlen(sentence);
    cout<<bully_name<<": ";
    for(int i=0;i<length;i++)
    {
      cout<<sentence[i];
    }
  }
  return didPunch;
}
