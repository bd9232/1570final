//Programmer: Brendan Dunne   Date: 29 April 2017
//Description: Definitions of Town-class functions
#include <iostream>
#include "townclass.h"
using namespace std;

Town :: Town(const int MAX, const int SIZE, const int HOUSEMAX,
                       const int BULLYMAX)
{
  setMembers(SIZE, HOUSEMAX, BULLYMAX);
  clearTown(MAX);
  buildWall(MAX);
  fillTown();
  return;
}

void Town :: setMembers(const int SIZE, const int HOUSEMAX, const int BULLYMAX)
{
  town_actualSize=SIZE;
  town_houses=HOUSEMAX;
  town_bullies=BULLYMAX;  
  return;
}
  
void Town :: clearTown(const int MAX)
{
  //sets all grid locations equal to empty spaces
  for(int i=0; i<MAX; i++)
  {
    for(int j=0; j<MAX; j++)
    {
      size[i][j].what = ' ';
    }
  }
  return;
}

void Town :: buildWall(const int MAX)
{
  //builds the wall according to the town_actualSize value
  for(int i=0; i<MAX; i++) 
  {
    for(int j=0; j<MAX; j++)
    {
      if ((j == 0 )|| (j==(town_actualSize-1)))
      {
	if (i<=(town_actualSize-1))
	  size[i][j].what = 'W';
      }
      else if ((i==0) || (i==(town_actualSize-1)))
      {
        if (j<=(town_actualSize-1))
          size[i][j].what = 'W'; 
      }
    }
  }
  return;
}

void Town :: fillTown()
{
  //begins going through the grid and randomly placing houses
  int counter1=0;
  do
  {
    int rand_Row, rand_Col;
    if (counter1>=0)
    {
      rand_Row = randVal(1, town_actualSize-1);
      rand_Col = randVal(1, town_actualSize-1);
    }
     
    if(size[rand_Row][rand_Col].what == ' ')
    {
      size[rand_Row][rand_Col].what = 'H';
      size[rand_Row][rand_Col].havePants = true;
      counter1++;
      //if a house is successfully placed, tries to place another next to it
      int tempcount;
      do
      {
        int direction = randVal(1,4);
        if (direction == 1)  
	{
	  if(size[rand_Row+1][rand_Col].what == ' ')
	  {
	    (size[rand_Row+1][rand_Col].what = 'H');
	    (size[rand_Row+1][rand_Col].havePants = true);
            counter1++;
          }
          tempcount++;
	}
	
	else if (direction == 2)
	{
	  if(size[rand_Row][rand_Col+1].what == ' ')
	  {
	    (size[rand_Row][rand_Col+1].what = 'H');
	    (size[rand_Row][rand_Col+1].havePants = true);
            counter1++;
	  }
	  tempcount++;
        }
        
	else if (direction == 3)
	{
	  if(size[rand_Row-1][rand_Col].what == ' ')
	  {
            (size[rand_Row-1][rand_Col].what = 'H');
	    (size[rand_Row-1][rand_Col].havePants=true);
            counter1++;
	  }
	  tempcount++;
        }
        
	else if (direction == 4)
	{
	  if(size[rand_Row][rand_Col-1].what == ' ')
	  {
	    (size[rand_Row][rand_Col-1].what = 'H');
	    (size[rand_Row][rand_Col-1].havePants=true);
            counter1++;
	  }
          tempcount++;
        }
        
	else
	  tempcount++;
	  
      }while (!tempcount);
    }
  }while (counter1<town_houses);//ensure max-amount of houses isn't exceeded
  
  //begins going through the grid and placing bullies randomly
  int counter2=1;
  do
  {
    int rand_Row, rand_Col;
    if (counter2)
    {
      rand_Row = randVal(1, town_actualSize-1);
      rand_Col = randVal(1, town_actualSize-1);
    }  
    if(size[rand_Row][rand_Col].what == ' ')
    {
      size[rand_Row][rand_Col].what = 'B';
      counter2++;
    }
  }while (counter2<town_bullies+1);//ensure max-amount of bullies is't exceeded
  return;
}  

ostream& operator <<(ostream &out, Town &source)
{
  for(int i=0; i<MAX; i++)
  {
    for(int j=0; j<MAX; j++)
    {
      switch(source.size[i][j].what)
      {
	case'H':
          if(source.size[i][j].havePants==false)
            out<<"\e[37m"<<source.size[i][j].what<<"\e[0m"<<" ";
          else  
            out <<"\e[33m"<<source.size[i][j].what<<"\e[0m"<< " ";
	  break;
	case 'B':
          out <<"\e[31m"<<source.size[i][j].what<<"\e[0m"<< " ";
	  break;
        case 'W':
	    out<<"\e[32m"<<source.size[i][j].what<<"\e[0m"<< " ";
	  break;
        case 'P':
	  out<<"\e[35m"<<source.size[i][j].what<<"\e[0m"<< " ";
          break;
        case 'M':
	  out<<"\e[34m"<<source.size[i][j].what<<"\e[0m"<< " ";
          break;
        case 'S':
	  out<<"\e[36m"<<source.size[i][j].what<<"\e[0m"<<" ";
          break;
        case 'F':
          out<<"\e[90m"<<source.size[i][j].what<<"\e[0m"<<" ";
          break;
        default:
	  out <<source.size[i][j].what<<" ";
	  break;
      }
    }
    out << endl;
  }
  return out;
}

//extra content from here on down
void Town :: extraStuff(const int shrinenum, const int fannum)
{
  shrinePlace(shrinenum);
  fanPlace(fannum);
  return;
}

void Town :: shrinePlace(const int shrinenum)
{
  //randomly places magic shrines that can protect/heal the tailor
  int counter=0;
  do
  {
    int rand_Row, rand_Col;
    if(counter>=0)
    {
      rand_Row = randVal(1, town_actualSize-1);
      rand_Col = randVal(1, town_actualSize-1);
    }
	
    if(size[rand_Row][rand_Col].what == ' ')
    {
      size[rand_Row][rand_Col].what = 'S';
      counter++;
    }
  }while (counter<shrinenum);
  return;
}

void Town :: fanPlace(const int fannum)
{
  //randomly places fans that can blow away and confuse PhantomPants
  int counter=0;
  do
  {
    int rand_Row, rand_Col;
    if(counter>=0)
    {
      rand_Row = randVal(1, town_actualSize-1);
      rand_Col = randVal(1, town_actualSize-1);
    }
	
    if(size[rand_Row][rand_Col].what == ' ')
    {
      size[rand_Row][rand_Col].what = 'F';
      counter++;
    }
  }while (counter<fannum);
  return;
}
