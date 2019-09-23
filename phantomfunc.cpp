//Programmer: Brendan Dunne   Date: 29 April 2017
//Description: Definitions of PhantomPant-class functions
#include <iostream>
#include "phantomclass.h"
using namespace std;

PhantomPant :: PhantomPant()
{
  pant_row = -1;
  pant_column = -1;
  pant_represent ='P';
  pant_inPlay = false;
}

void PhantomPant :: placeMe(Town &town)
{
  pant_inPlay = true;
  bool placed = false;
  int rand_Row, rand_Col;
  do
  {
    rand_Row = randVal(1, town.town_actualSize-1);
    rand_Col = randVal(1, town.town_actualSize-1);
    //checks if random coordinates chosen are acceptable
    if(town.size[rand_Row][rand_Col].what == ' ')
    {
      //this to ensure that when pants spawn or are relocated, the never land
	  //next to the tailor
	  if(town.size[rand_Row+1][rand_Col].what!='M' &&
	     town.size[rand_Row-1][rand_Col].what!='M' &&
		 town.size[rand_Row][rand_Col+1].what!='M' &&
		 town.size[rand_Row][rand_Col-1].what!='M')
	  {
        town.size[rand_Row][rand_Col].what=pant_represent;
	     if((pant_row>=0) && (pant_column>=0))
          town.size[pant_row][pant_column].what=' ';
        pant_row=rand_Row;
        pant_column=rand_Col;
        placed=true;
	  }
    }
  }while(!placed);
  return;  
}

bool PhantomPant :: checkInPlay()
{
  return pant_inPlay;
}  
  
void PhantomPant :: chase(Tailor &tailor, Town &town)
{
  int count=0;
  int move_chance = randVal(1,4);
  bool getRekt;
  //determines pants' position relative to the tailor
  int up_or_down = pant_row-tailor.t_row;
  int left_or_right = pant_column-tailor.t_column;
  if (move_chance==1)
  {
    do
    {
      if (up_or_down<0)//chase in downward direction
      {
        if (town.size[pant_row+1][pant_column].what==' ')//check down
        {
          town.size[pant_row+1][pant_column].what=pant_represent;
	  town.size[pant_row][pant_column].what=' ';
	  pant_row=pant_row+1;
	  count++;
        }
        //if pants can't move down, check which horizontal direction to move
        else if (left_or_right<0)//check if need to go right
        {
	  if (town.size[pant_row][pant_column+1].what==' ')//check right
	  {
            town.size[pant_row][pant_column+1].what=pant_represent;
	    town.size[pant_row][pant_column].what=' ';
	    pant_column=pant_column+1;
	    count++;
	  }
	  else
	    count++;
        }
        else if (left_or_right>0)//check if need to go left
        {
          if (town.size[pant_row][pant_column-1].what==' ')
	  {
            town.size[pant_row][pant_column-1].what=pant_represent;
	    town.size[pant_row][pant_column].what=' ';
	    pant_column=pant_column-1;
	    count++;
	  }
	  else
	    count++;
        }
        else//if no movement can be done, end step
	  count++;
      }

      else if (up_or_down>0)//chase in upward direction
      {
        if (town.size[pant_row-1][pant_column].what==' ')//check up
        {
          town.size[pant_row-1][pant_column].what=pant_represent;
	  town.size[pant_row][pant_column].what=' ';
	  pant_row=pant_row-1;
	  count++;
        }
        //if pants can't move up, check which horizontal direction to move
        else if (left_or_right<0)//check if need to go right
        {
	  if (town.size[pant_row][pant_column+1].what==' ')
	  {
            town.size[pant_row][pant_column+1].what=pant_represent;
	    town.size[pant_row][pant_column].what=' ';
	    pant_column=pant_column+1;
	    count++;
	  }
	  else
	    count++;
        }
        else if (left_or_right>0)//check if need to go left
        {
	  if (town.size[pant_row][pant_column-1].what==' ')
	  {
            town.size[pant_row][pant_column-1].what=pant_represent;
	    town.size[pant_row][pant_column].what=' ';
	    pant_column=pant_column-1;
	    count++;
	  }
	  else
	    count++;
        }
        else//if no movement can be done, end step
          count++;
      }

      else if (up_or_down==0)//vertical movement is not needed
      {
        if (left_or_right>0)//check if need to go left
        {
          if (town.size[pant_row][pant_column-1].what==' ')
	  {
            town.size[pant_row][pant_column-1].what=pant_represent;
	    town.size[pant_row][pant_column].what=' ';
	    pant_column=pant_column-1;
	    count++;
	  }
	  else
	    count++;
        }
        else if (left_or_right<0)//check if need to go right
        {
	  if (town.size[pant_row][pant_column+1].what==' ')
	  {
            town.size[pant_row][pant_column+1].what=pant_represent;
	    town.size[pant_row][pant_column].what=' ';
	    pant_column=pant_column+1;
	    count++;
	  }
	  else
	    count++;
        }
        else//no movement can be done, end step
          count++;
      }
    }while (!count);
  }
  
  getRekt=check(town);
  if(!getRekt)
  {
    //attempts to kill tailor, success depends on tailor location relative
    //to pants
    kill(tailor, town);
    //bullyKill(town);//remove comment to turn on bully killing
  }
  return;
}

void PhantomPant :: kill(Tailor &tailor, Town &town)
{
  //extra content: if the tailor is next to a shrine, pants cannot kill
  bool tailorProtected;
  if (town.size[tailor.t_row-1][tailor.t_column].what=='S')
    tailorProtected=true;
  if (town.size[tailor.t_row+1][tailor.t_column].what=='S')
    tailorProtected=true;
  if(town.size[tailor.t_row][tailor.t_column-1].what=='S')
    tailorProtected=true;
  if(town.size[tailor.t_row][tailor.t_column+1].what=='S')
    tailorProtected=true;
  if(!tailorProtected)
  {
    //checks if tailor is adjacent to any pair of pants
    if(town.size[pant_row-1][pant_column].what==tailor.t_represent)
      tailor.t_alive=false;
    if(town.size[pant_row+1][pant_column].what==tailor.t_represent)
      tailor.t_alive=false;
    if(town.size[pant_row][pant_column-1].what==tailor.t_represent)
      tailor.t_alive=false;
    if(town.size[pant_row][pant_column+1].what==tailor.t_represent)
      tailor.t_alive=false;
  }
  return;
}

//extra content from here on down
void PhantomPant :: bullyKill(Town &town)
{
  // generates chance of attempting to kill any nearby bullies
  if (randVal(0,3) == 0)
  {	  
    if(town.size[pant_row-1][pant_column].what=='B')
    {
      town.size[pant_row-1][pant_column].what=' ';
      cout<<"~A poor young bully, gone. He would've made a great politician.. ";
    }   
    if(town.size[pant_row+1][pant_column].what=='B')
    {   
      town.size[pant_row+1][pant_column].what=' ';
      cout<<"~Honestly, if ghost pants can kill you, you've earned it... ";
    }   
    if(town.size[pant_row][pant_column-1].what=='B')
    { 
      town.size[pant_row][pant_column-1].what=' ';
      cout<<"~The pants got him? I mean come on, he kinda deserved it.. ";
    }
    if(town.size[pant_row][pant_column+1].what=='B')
    {     
      town.size[pant_row][pant_column+1].what=' ';
      cout<<"~The pants have claimed a victim!! But he was ugly anyway, soo.. ";
    }
  }
  return;
}

bool PhantomPant :: check(Town &town)
{
    //looks to see if any fans are adjacent to any pants
    if(town.size[pant_row+1][pant_column].what=='F')
    {
      placeMe(town);
      cout<<"~WOOOSH! Take that!  ";
      return true;
    }
    if(town.size[pant_row-1][pant_column].what=='F')
    {
      placeMe(town);
      cout<<"~WOOOSH! Take that!  ";
      return true;
    }
    if(town.size[pant_row][pant_column+1].what=='F')
    {
      placeMe(town);
      cout<<"~WOOOSH! Take that!  ";
      return true;
    }
    if(town.size[pant_row][pant_column-1].what=='F')
    {
      placeMe(town);
      cout<<"~WOOOSH! Take that!  ";
      return true;  
    }	
    else
      return false;
}
