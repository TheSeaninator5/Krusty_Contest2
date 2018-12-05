#ifndef BURGERMEISTER_H
#define BURGERMEISTER_H
#include <iostream>
#include <cmath>
#include <fstream>

#include "customer.h"
#include "burger.h"
using namespace std;
class burgermeister
{
	private:
	string m_name;
	float m_montHold;
	
	
	public:
	burgermeister()
	{
	  m_name = "Krusty";
	  m_montHold = 100.0;
	
	}
	
	burgermeister(string name, float mon)
    {
      m_name = name;
	  m_montHold = mon;
    }
	
	friend burgermeister operator+=(burgermeister& Krusty, 
	const float money);
	
	friend burgermeister operator-=(burgermeister& Krusty, 
	const float money);
	
	//Desc: gets the montHold in the burgermeister 
	//Pre:none
	//Post: returned the montHold
	int getMontHold();
	
};


#endif