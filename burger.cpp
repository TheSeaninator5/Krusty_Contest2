
#include "customer.h"
#include "burgermeister.h"
#include "burger.h"

using namespace std;

//Burger Functions
int burger::getburgCode()const
{
  return m_burgCode;
}
bool burger::setPattie(const int pattie)
{
  bool ret = false;
  if(pattie > 0 && pattie < 5)
  {
    m_numPatties = pattie;
    ret = true;
  }
  return ret;
}

int burger::getPattie()const
{
  return m_numPatties;
}

bool burger::setBacon(const int bacon)
{
  bool ret = false;
  if(bacon >= 0 && bacon < 5)
  {
    m_numBacon = bacon;
    ret = true;
  }
  return ret;
}

int burger::getBacon()const
{
  return m_numBacon;
}

bool burger::setPickle(const int pickle)
{
  bool ret = false;
  if(pickle >= 0 && pickle < 5)
  {
    m_numPickles = pickle;
    ret = true;
  }
  return ret;
}

int burger::getPickle()const
{
  return m_numPickles;
}

bool burger::setCheese(const bool cheese)
{
  m_hasCheese = cheese;
  return cheese;
}

bool burger::getCheese()const
{
  return m_hasCheese;
}

bool burger::setSauce(const bool sauce)
{
  m_hasSauce = sauce;
  return sauce;
}

bool burger::getSauce()const
{
  return m_hasSauce;
}

bool burger::setPathogen(const bool pathogen)
{
  m_hasPathogen = pathogen;
  return pathogen;
}

bool burger::getPathogen()const
{
  return m_hasPathogen;
}

float burger::getPrice()const
{
  return m_price;
}

string burger::getburgName()const
{
  return m_burgName;
}

ostream &operator<<(ostream& os, burger b)
{
  os << b.getburgName();
  return os;
}
