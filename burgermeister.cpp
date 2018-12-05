
#include "customer.h"
#include "burgermeister.h"
#include "burger.h"

using namespace std;

burgermeister operator+=(burgermeister& Krusty, const float money)
{
    Krusty.m_montHold+=money;
    return Krusty;
}
burgermeister operator-=(burgermeister& Krusty, const float money)
{
    Krusty.m_montHold-=money;
    return Krusty;
}
    
int burgermeister::getMontHold()const
{
  return m_montHold;	
}
