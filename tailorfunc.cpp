//Programmer: Brendan Dunne   Date: 29 April 2017
//Description: Definitions of Tailor-class functions
#include <iostream>
#include <cstring>
#include <iomanip>
#include "tailorclass.h"
using namespace std;

Tailor :: Tailor(const string name, const char rep)
{
  t_name=name;
  t_money=randVal(20,40);
  t_row=-1;
  t_column=-1;
  t_represent=rep;
  t_alive=true;
  t_health=100;
  t_pants=30;
  return;
}  

void Tailor :: placeMe(Town &town)
{
  bool placed = false;
  int rand_Row, rand_Col;
  do
  {
    rand_Row = randVal(1, town.town_actualSize-1);
    rand_Col = randVal(1, town.town_actualSize-1);
    if(town.size[rand_Row][rand_Col].what == ' ')
    {
      town.size[rand_Row][rand_Col].what=t_represent;
      //if the tailor has moved since his initial placement, clears the space
      //where he previously was
      if((t_row>=0) && (t_column>=0))
        town.size[t_row][t_column].what=' ';
      //sets Tailor's variables for location to new values
      t_row=rand_Row;
      t_column=rand_Col;
      placed=true;
    }
  }while(!placed);
  return;
}

void Tailor :: randWalk(Town &source)
{
  int count;	
  do
  {
    int direction = randVal(1,4);
    if (direction == 1)//attempt to walk down first
    {	
      if(source.size[t_row+1][t_column].what==' ')//checks down
      {
        source.size[t_row+1][t_column].what=t_represent;
	source.size[t_row][t_column].what=' ';
	t_row=t_row+1;
	count++;
      }
      else if (source.size[t_row-1][t_column].what==' ')//if taken, checks up
      {
        source.size[t_row-1][t_column].what=t_represent;
	source.size[t_row][t_column].what=' ';
        t_row=t_row-1;
	count++;
      }
      else if (source.size[t_row][t_column+1].what==' ')//if taken, checks right
      {
        source.size[t_row][t_column+1].what=t_represent;
	source.size[t_row][t_column].what=' ';
        t_column=t_column+1;
	count++;
      }
      else if (source.size[t_row][t_column-1].what==' ')//if taken, checks left
      {
        source.size[t_row][t_column-1].what=t_represent;
	source.size[t_row][t_column].what=' ';
        t_column=t_column-1;
	count++;
      }
    }
    else if (direction == 2)//attempt to walk right first
    {	  
      if (source.size[t_row][t_column+1].what==' ')//checks right
      {
        source.size[t_row][t_column+1].what=t_represent;
	source.size[t_row][t_column].what=' ';
        t_column=t_column+1;
	count++;
      }
      else if (source.size[t_row][t_column-1].what==' ')//if taken, checks left
      {
        source.size[t_row][t_column-1].what=t_represent;
	source.size[t_row][t_column].what=' ';
        t_column=t_column-1;
	count++;
      }
      else if (source.size[t_row-1][t_column].what==' ')//if taken, checks up
      {
        source.size[t_row-1][t_column].what=t_represent;
	source.size[t_row][t_column].what=' ';
        t_row=t_row-1;
	count++;
      }
      else if (source.size[t_row+1][t_column].what==' ')//if taken, checks down
      {
        source.size[t_row+1][t_column].what=t_represent;
	source.size[t_row][t_column].what=' ';
	t_row=t_row+1;
	count++;
      }
	    
    }
    else if (direction == 3)//attempt to walk up first
    { 	 
      if (source.size[t_row-1][t_column].what==' ')//checks up
      {
        source.size[t_row-1][t_column].what=t_represent;
	source.size[t_row][t_column].what=' ';
	t_row=t_row-1;
	count++;
      }
      else if (source.size[t_row+1][t_column].what==' ')//if taken, checks down
      {
        source.size[t_row+1][t_column].what=t_represent;
	source.size[t_row][t_column].what=' ';
	t_row=t_row+1;
	count++;
      }
      else if (source.size[t_row][t_column-1].what==' ')//if taken, checks left
      {
        source.size[t_row][t_column-1].what=t_represent;
	source.size[t_row][t_column].what=' ';
        t_column=t_column-1;
	count++;
      }
      else if (source.size[t_row][t_column+1].what==' ')//if taken, checks right
      {
        source.size[t_row][t_column+1].what=t_represent;
	source.size[t_row][t_column].what=' ';
	t_column=t_column+1;
	count++;
      }
    }
    else if (direction == 4)//attempt to walk left first
    {
      if (source.size[t_row][t_column-1].what==' ')//checks left
      {
        source.size[t_row][t_column-1].what=t_represent;
	source.size[t_row][t_column].what=' ';
        t_column=t_column-1;
	count++;
      }
      else if (source.size[t_row][t_column+1].what==' ')//if taken, checks right
      {
        source.size[t_row][t_column+1].what=t_represent;
	source.size[t_row][t_column].what=' ';
        t_column=t_column+1;
	count++;
      }
      else if (source.size[t_row+1][t_column].what==' ')//if taken, checks down
      {
        source.size[t_row+1][t_column].what=t_represent;
	source.size[t_row][t_column].what=' ';
	t_row=t_row+1;
	count++;
      }
      else if (source.size[t_row-1][t_column].what==' ')//if taken, checks up
      {
        source.size[t_row-1][t_column].what=t_represent;
	source.size[t_row][t_column].what=' ';
	t_row=t_row-1;
	count++;
      }
    }	
  }while (!count);//repeat the loop as long as the tailor has not stepped
  return;
}

void Tailor :: trade(Town &source)
{
  if (source.size[t_row+1][t_column].what=='H')//checks down for house
  {
    if (source.size[t_row+1][t_column].havePants==true)
    {
      if (t_pants>0)
      {
        int tradeOff = randVal(1,10);
        //if trade is successful, changes Tailor variables accordingly
        if (tradeOff<=7)
        {
          source.size[t_row+1][t_column].havePants=false;
          t_pants = t_pants - 1;
          t_money = t_money + 10;
	}
      }
    }
  }

  if (source.size[t_row][t_column+1].what=='H')//checks right for house
  {
    if (source.size[t_row][t_column+1].havePants==true)
    {
      if (t_pants>0)
      {
        int tradeOff = randVal(1,10);
        //if trade is successful, changes Tailor variables accordingly
	if (tradeOff<=7)
        {
          source.size[t_row][t_column+1].havePants=false;
	  t_pants = t_pants - 1;
	  t_money = t_money + 10;
	}
      }
    }
  }
  
  if (source.size[t_row-1][t_column].what=='H')//checks up for house
  {
    if (source.size[t_row-1][t_column].havePants==true)
    {
      if (t_pants>0)
      {
  	int tradeOff = randVal(1,10);
        //if trade is successful, changes Tailor variables accordingly
	if (tradeOff<=7)
        {
          source.size[t_row-1][t_column].havePants=false;
	  t_pants = t_pants - 1;
	  t_money = t_money + 10;
        }
      }
    }
  }
  
  if (source.size[t_row][t_column-1].what=='H')//checks left for house
  {
    if (source.size[t_row][t_column-1].havePants==true)
    {
      if (t_pants>0)
      {
  	int tradeOff = randVal(1,10);
        //if trade is successful, changes Tailor variables accordingly
	if (tradeOff<=7)
        {
          source.size[t_row][t_column-1].havePants=false;
	  t_pants = t_pants - 1;
	  t_money = t_money + 10;
	}
      }
    }
  }
  return;
}  
    
bool Tailor :: check(Town &source)
{
  //looks if there is a bully next to the tailor
  if (source.size[t_row-1][t_column].what=='B')
    return true;

  else if (source.size[t_row+1][t_column].what=='B')
    return true;

  else if (source.size[t_row][t_column-1].what=='B')
    return true;

  else if (source.size[t_row][t_column+1].what=='B')
    return true;

  else
    return false;
}


bool Tailor :: keepSim()
{
  if (t_pants==0)
    return false;
  if (t_health==0)
    return false;
  if (t_alive==false)
    return false;
  else
    return true;
}

string Tailor :: endReport()
{
  string close;
  if((t_alive == false) && (t_health == 0))
    close="He was \e[91mPUNCHED TO DEATH!! \e[96mRIP.";
  else if((t_alive == false) && (t_health !=0)) 
    close="He was killed by.. \e[95mPHANTOM PANTS!! \e[96mRIP.";
  else if((t_alive == true) && (t_pants == 0))
    close="Overcoming all obstacles, he sold all his pants! \e[93mYEE!";
  else if((t_alive == true) && (t_pants != 0))
    close="He stepped the maximum number of times. \e[94mExciting.";
  else
    close="Some other combination of stuff happened.. Check again?";
  return close;
}

ostream& operator <<(ostream &out, Tailor &source)
{
  string condition;
  string tense;
  //determines if tailor is dead
  if(source.t_health==0)
    source.t_alive=false;
  //depending on state of tailor, changes words to print
  if ((source.t_alive==true))
  {
    condition = "alive";
    tense = "has";
  }
  else if ((source.t_alive==false))
  {
    condition = "dead";
    tense = "had";
  }
  out<<source.t_name<<" is "<<condition<<" at "<<source.t_row<<","
     <<source.t_column<<". "<<"He "<<tense<<" $"<<fixed<<setprecision(2)
     <<source.t_money<<", "<<source.t_health<<" health, and "<<source.t_pants
     <<" pairs of pants."<<endl; 
  return out;
}  

//extra content from here on down
bool Tailor :: shrineCheck(Town &town)
{
  //extra content: checks if there is a shrine next to the tailor
  if (town.size[t_row-1][t_column].what=='S')
  {
    cout<<"A voice, deep in the shrine: Don't worry "<<t_name
        <<", you're safe here!  ";
    if(t_health<100)
      t_health=t_health+10;
    return true;
  }
  else if (town.size[t_row+1][t_column].what=='S')
  {
    cout<<"A voice, deep in the shrine: Don't worry "<<t_name
        <<", you're safe here!  ";
    if(t_health<100)
      t_health=t_health+10;
    return true;
  }
  else if (town.size[t_row][t_column-1].what=='S')
  {
    cout<<"A voice, deep in the shrine: Don't worry "<<t_name
        <<", you're safe here!  ";
    if(t_health<100)
      t_health=t_health+10;
    return true;
  }
  else if (town.size[t_row][t_column+1].what=='S')
  {
    cout<<"A voice, deep in the shrine: Don't worry "<<t_name
        <<", you're safe here!  ";
    if(t_health<100)
      t_health=t_health+10;
    return true;
  }
  
  else
    return false;
}  
