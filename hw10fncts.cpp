// Programmer: Colton Walker // Date: 11/8/2018
// instructor Name: Price // Section: 1B
// File: hw10fncts.cpp // Description: two classes of a burger and customer



#include "customer.h"
#include "burgermeister.h"
#include "burger.h"

using namespace std;
//Functions6

string makeName()
{
  string name = "";
  ifstream fin;
  fin.open("simpson_names.dat");
  static int line = 1;
  for(int i = 0; i < line; i++)
  {
    getline(fin, name);
  }
  fin.close();
  line++;
  return name;
}

string burgName(const int burgCode, const bool cheese, const bool sauce)
{
  const string KRUSTY = "Krusty ";
  const string BURGER= "Burger";
  const string SINGLE = "Single ";
  const string DOUBLE = "Double ";
  const string TRIUMPH = "Triumph ";
  const string MEATMASTER = "Meatmaster ";
  const string HEALTHMASTER = "Health-Master ";
  const string BACON = "Bacon ";
  const string WILBUR = "Wilbur ";
  const string KLOGGER = "Klogger ";
  const string FATTY = "Fatty ";
  const string TASTELESS = "Tasteless ";
  const string PICKLY = "Pickly ";
  const string GARDENFRESH = "Garden-Fresh ";
  const string KERMIT = "Kermit ";
  const string GREEN = "Green ";
  const string SAUCED = "Sauced ";
  const string CHEESY = "Cheesy ";
  int patties, bacon, pickles;
  string namePatties, nameBacon, namePickles, nameCheese, nameSauce;
  getBurgNum(burgCode, patties, bacon, pickles);
  if(cheese == true)
  {
    nameCheese = CHEESY;	  
  }
  if(sauce == true)
  {
	nameSauce = SAUCED;
  }
  //Name based on number patties
  if(patties == 1)
  {
    namePatties = SINGLE;
  }else if(patties == 2)
   {
     namePatties = DOUBLE;
   }else if(patties == 3)
    {
      namePatties = TRIUMPH;
    }else if(patties == 4)
	 {
	   namePatties = MEATMASTER;
	 }
  //Name based on oz of Bacon
  if(bacon == 1)
  {
    nameBacon = BACON;
  }else if(bacon == 2)
   {
     nameBacon = WILBUR;
   }else if(bacon == 3)
    {
      nameBacon = KLOGGER;
    }else if(bacon == 0)
     {
       nameBacon = HEALTHMASTER;
     }else if(bacon == 4)
	  {
	    nameBacon = FATTY;	  
	  }
  //Name based on number of pickles
  if(pickles  == 1)
  {
    namePickles = PICKLY;
  }else if(pickles == 2)
   {
     namePickles = GARDENFRESH;
   }else if(pickles == 3)
    {
      namePickles = KERMIT;
    }else if(pickles == 0)
     {
       namePickles = TASTELESS;
     }else if(pickles == 4)
	 {
	   namePickles = GREEN; 
	 }
  return KRUSTY + nameCheese + nameSauce + namePatties + nameBacon +
         namePickles + BURGER;
}

void getBurgNum(const int burgCode, int & pat, int & bac, int & pic)
{
  pat = burgCode / 100;
  bac = (burgCode / 10) % 10;
  pic = burgCode % 10;
  return;
}



ostream &operator<<(ostream& os, burger b)
{
  os << b.getburgName();
  return os;
}

ostream &operator<<(ostream& os, customer c)
{
  os << c.getName()<<" money: "<<c.getMoney() <<
        "\n weight: "<<c.getWeight()<<" Cholesterol: "<<
		c.getCholesterol() << " Health: "<<c.getHealth() <<
		" Weight Gain: "<<c.getWeightGain()<<"\n roundsBurgNotEtn: "<<
		c.getBurgNotEaten()<<" numBurgEtn: "<<c.getNumBurgEaten()<<" isContestant: ";
		if(c.isContestant() == true)
		{
		  os<<" True ";	
		}else
		{
		  os<<" False ";  	
		}
        if(c.getAlive() == true)
        {
        os<<" Is ALIVE";
        }else
         {
         os<<" Is DEAD";
         }
  return os;
}


