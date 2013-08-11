#include<stdexcept>
#include "Human.h"
using namespace std;

Human* Human::clone() const
{
  return new Human(*this);
}

