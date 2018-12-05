// Programmer: Colton Walker // Date: 11/8/2018
// instructor Name: Price // Section: 1B
// File: hw10.cpp // Description: two classes of a burger and customer



#include "customer.h"
#include "burgermeister.h"
#include "burger.h"

using namespace std;

int main()
{
  srand(time(NULL));
  customer contest[15];
  burgermeister krusty;
  bool main_loop = true;
  int x;
  do{
	  static int round = 1;
	  //Display contestants
	  for(int i = 0; i < 15; i++)
      {
        cout<<contest[i]<<endl;
      }
	  //Display round
	  cout<<"------------ROUND "<<round<<"--------------"<<endl; 
	  //Start round eating burgers
	  for(int i = 0; i < 15; i++)
	  {
	    contest[i].eat(krusty);
		contest[i].vomit(i, contest, krusty);
		contest[i].checkAlive();
	  }
	  for(int i = 14; i >=0; i--)
	  {
        contest[i].eat(krusty);
		contest[i].vomit(i, contest, krusty);
		contest[i].checkAlive();
	  }
	  cout<<"Krusty's Money: "<<krusty.getMontHold()<<endl;
	  round++;
	  if((x = findWinner(contest, krusty)) == 1)
	  {
		main_loop = false;  
	  }
  }while(main_loop);


  return 0;	
}