#ifndef BURGER_H
#define BURGER_H
#include <iostream>
#include <cmath>
#include <fstream>

#include "customer.h"
#include "burgermeister.h"

using namespace std;
//Desc: burgName() will create a name for a burger based on the number of 
//pickles, patties, and bacon
//Pre: None
//Post: a string name will be returned
string burgName(const int burgCode, const bool cheese, const bool sauce);
//Desc: getBurgNum() will set the parameters for pat, bac, and pic
//Pre: burgCode must be a positive integer 
//Post: the parameters are set based on burgCode
void getBurgNum(const int burgCode, int & pat, int & bac, int & pic);

class burger
{
  private:
    int m_numPatties;
    int m_numBacon;
    int m_numPickles;
    bool m_hasCheese;
    bool m_hasSauce;
    bool m_hasPathogen;
    int m_burgCode;
    string m_burgName;
    int m_price;
    
  public:
    //default constructor
    burger() 
    { 
      m_numPatties = 1 + rand() % (4);
      m_numBacon = 1 + rand() % (4);
      m_numPickles = 1 + rand() % (4);
      m_hasCheese = rand() % 2;
      m_hasSauce = rand() % 2;
      if((rand() % 10) == 0)
      {
        m_hasPathogen = true;
      }else
      {
        m_hasPathogen = false;
      }
      
      m_burgCode = m_numPatties*100 + m_numBacon*10 + m_numPickles;
      m_burgName = burgName(m_burgCode, m_hasCheese, m_hasSauce);
      m_price = static_cast<float>(0.75 * m_numPatties) + 
            static_cast<float>(0.5 * m_numBacon) + 
            static_cast<float>(0.25 * m_numPickles) + 
        static_cast<float>(0.1 * m_hasCheese) + 
            static_cast<float>(0.25 * m_hasCheese) + (0.5); 
    }
    
    //constructor that takes patties, bacon, pickles, whether it has 
    //cheese and a pathagen
    burger(int pat, int bac, int pic, bool cheese, bool path)
    {
      m_numPatties = pat;
      m_numBacon = bac;
      m_numPickles = pic;
      m_hasCheese = cheese;
      m_hasPathogen = path;
      m_burgName = burgName(m_burgCode, m_hasCheese, m_hasSauce);
    }
    
    //Desc: gets the name from the burger
    //Pre: none
    //Post: the namefrom the burger was returned
    string getburgName()const;
    //Desc: gets the burgCode from the burger
    //Pre: none
    //Post: the burgCode from the burger was returned
    int getburgCode()const;
    //Desc: gets the num of patties from the burger
    //Pre: none
    //Post: the num of patties from the burger was returned
    int getPattie()const;
    //Desc: set the num of patties to the burger
    //Pre: none
    //Post: the num of patties is now given to the burger
    bool setPattie(const int pattie);
    //Desc: gets the num of oz of bacon from the burger
    //Pre: none
    //Post: the num of oz of bacon from the burger was returned
    int getBacon()const;
    //Desc: set the num of bacon to the burger
    //Pre: none
    //Post: the num of oz of bacon is now given to the burger
    bool setBacon(const int bacon);
    //Desc: gets the num of pickles from the burger
    //Pre: none
    //Post: the num of pickles from the burger was returned
    int getPickle()const;
    //Desc: set the num of pickles to the burger
    //Pre: none
    //Post: the num of pickles is now given to the burger
    bool setPickle(const int pickle);
    //Desc: gets whether cheese is on the burger
    //Pre: none
    //Post: whether cheese is from the burger was returned
    bool getCheese()const;
    //Desc: set whether there is cheese to the burger
    //Pre: none
    //Post: whether there is cheese is now given to the burger
    bool setCheese(const bool cheese);
    //Desc: gets whether sauce is on the burger
    //Pre: none
    //Post: whether sauce is from the burger was returned
    bool getSauce()const;
    //Desc: set whether there is sauce to the burger
    //Pre: none
    //Post: whether there is sauce is now given to the burger
    bool setSauce(const bool sauce);
    //Desc: gets whether a pathogen is on the burger
    //Pre: none
    //Post: whether a pathogen is on the burger was returned
    bool getPathogen()const;
    //Desc: set whether there is a pathogen on the burger
    //Pre: none
    //Post: whether there is a pathogen is now given to the burger
    bool setPathogen(const bool pathegen);
    //Desc: gets the price from the burger
    //Pre: none
    //Post: the price of burger was returned
    float getPrice()const;
};

ostream &operator<<(ostream &stream, burger b);
#endif
