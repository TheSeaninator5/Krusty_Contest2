#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <cmath>
#include <fstream>

#include "burgermeister.h"
#include "burger.h"
using namespace std;

//Desc: getName() will return a name from the simpson_names.dat file
//Pre: none
//Post: a name was returned to the string
string makeName();

class customer
{
  private:
    string m_name;
    //This is their "local monetary holdings" in $
    float m_money;
    float m_weight;
    float m_cholesterol;
    bool m_alive;
	int m_health;
	bool m_vomit;
	bool m_isContestant;
	float m_weightGain;
	bool m_paidDeath;
	int m_burgEaten;
	int m_burgNotEaten;
	
  public:
    //default constructor
    //WILL DRAW NAME FROM A FILE OF NAMES!!!!!
    //MAKE GETNAME FUNCTIONNS LK&T)U@T*@&$* $W(*Y_($^_(*@
    customer()
    {
      m_name = makeName();
      m_money =  25 + rand() % (51);
      m_weight = 90 + rand() % (161);
	  m_cholesterol = 30 + rand() % (271);
      m_alive = true;
	  m_health = (1 + rand() % (100));
	  m_vomit = false;
	  m_isContestant = true;
	  m_weightGain = 0;
	  m_paidDeath = false;
	  m_burgEaten = 0;
	  m_burgNotEaten = 0;
    }
	//Desc: gets the number of burgers eaten
	//Pre: none
	//Post: returned the number of burgers eaten 
	int getNumBurgEaten()const;
	//Desc: gets the number of burgers not eaten
    //Pre: none
    //Post: returned the number of burgers not eaten 
	int getBurgNotEaten()const;
	//Desc: gets the ammount of weight gained by the customer
    //Pre:
    //Post: returned the ammount of weight gained by the customer 
	float getWeightGain()const;
    //Desc: gets the ammount of health a customer has
    //Pre: none
    //Post: returned the ammount of health a customer has
    int getHealth()const;
    //Desc: gets the name of the customer
    //Pre: none
    //Post: the name of the customer was returned
    string getName()const;
    //Desc: gets the amount of money the from customer
    //Pre: none
    //Post: the amount of money the customer has was returned
    float getMoney()const;
    //Desc: set money to the customer
    //Pre: none
    //Post: the money is now given to the customer
    bool setMoney(const float money);
    //Desc: gets the weight of the customer
    //Pre: none
    //Post: the weight of the customer was returned
    float getWeight()const;
    //Desc: set the weight to the customer
    //Pre: none
    //Post: the weight is now given to the customer
    bool setWeight(const float weight);
    //Desc: gets the cholesterol of the customer
    //Pre: none
    //Post: the cholesterol of the customer was returned
    short getCholesterol()const;
    //Desc: set the cholesterol to the customer
    //Pre: none
    //Post: the cholesterol is now given to the customer
    bool setCholesterol(const short cholesterol);
    //Desc: gets the aliveness of the customer
    //Pre: none
    //Post: the aliveness of the customer was returned
    bool getAlive()const;
    //Desc: set the aliveness to the customer
    //Pre: none
    //Post: the aliveness is now given to the customer
    bool setAlive(const bool alive);
	//Desc: return if customer is still contestant
    //Pre: none
    //Post: returned the customers contestant participation
	bool isContestant()const;
    //Desc: Will remove money, increase cholesterol, increase weight,
    //if a pathagen is present then will kill the customer
    //Pre: Customer must be alive
    //Post: Customers money, cholesterol, weight and aliveness were changed
    void eat(burgermeister& krusty);
	//Desc: Will throw a burger at a random person in the array or krusty
	//Pre: None
	//Post: A burger was throw at a random person or krusty
	void toss(customer contest[], burgermeister& krusty);
	//Desc: Will cause the person to vomit and then 50% chance 
	//for neighbor to vomit
	//Pre: None
	//Post: The customer vomited and possibly caused the neighbors to vomit
	void vomit(const int POS, customer contest[], burgermeister& krusty);
	//Desc: checks to see if the person is still alive
	//Pre: none
	//Post: sets the person as DEAD if they are not alive
	void checkAlive();
	//Desc: makes krusty pay for the death of a person
	//Pre: person must be DEAD
	//Post: krusty pays for the death of someone 
	void payDeath(burgermeister& krusty);
	
};

//Desc:
//Pre:
//Post:
int findWinner(customer contest[], burgermeister& krusty);
ostream &operator<<(ostream &stream, customer c);

#endif