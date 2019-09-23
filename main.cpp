//Programmer: Brendan Dunne   Date: 29 April 2017
//Description: Creates town, tailor walks around town selling pants, being
//             punched by bullies and chased by phantom pants
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include "header.h"
#include "townclass.h"
#include "tailorclass.h"
#include "bullyclass.h"
#include "phantomclass.h"
using namespace std;
  /*
  EXTRA FEATURES not in the rubric have been implemented. To turn
  them on, remove the comments in front of town1.extraStuff(), and go to
  the end of the chase() function in phantomfunc.cpp. Thanks! Enjoy.*/

int main()
{
  srand(time(NULL));
  Town town1(MAX, SIZE, HOUSEMAX, BULLYMAX);
  Tailor tailor1("Millhouse", 'M');
  Bully bully[BULLIES];
  PhantomPant pant[PANTS];
  tailor1.placeMe(town1);
  //town1.extraStuff(2,5);//remove comment to give Millhouse a chance out here
  int counter=1;
  int pantCount=0;
  cout<<"STARTING TOWN"<<endl;
  cout<<town1;
  cout<<tailor1;
  cout<<"------------------------------------------------"<<endl;
  
  do
  {
    if(counter>35)
      cout<<endl<<counter<<") ";
    tailor1.randWalk(town1);
    bool magicGaurd = tailor1.shrineCheck(town1);
    if (tailor1.check(town1))
    {
      int b = randVal(0,3);
      if(!magicGaurd)
      {
        if((pantCount<PANTS) && bully[b].punch(tailor1, town1))
        {
          pant[pantCount].placeMe(town1);
          pantCount++;
        }
      }
    }
    
    else
      tailor1.trade(town1);
    
    if(!magicGaurd)
    {		
      for(int i = 0;i<PANTS;i++)
      {
        if(pant[i].checkInPlay())
          pant[i].chase(tailor1, town1);
      }
    }
	
    if(counter<=35)
    {
      cout<<"\nSHOWING RESULTS OF STEP: "<<counter<<endl;
      cout<<town1;
      cout<<tailor1;
      cout<<"------------------------------------------------\n";
    }
    counter++;
  }while(counter<=1000 && tailor1.keepSim()==true);
  
  cout<<"TERMINATED ON STEP: "<<counter-1<<endl;
  cout<<town1;
  cout<<"\e[96mAt the time of termination:"<<endl;
  cout<<tailor1;
  cout<<(tailor1.endReport())<<"\e[0m"<<endl;
  
  return 0;
}
