#ifndef RANGEROVER_H
#define RANGEROVER_H
#include "car.h"

class RangeRover: public Car
{
public:
  RangeRover();
  void init_masina();
  float race(float lungime,Vreme vreme);
};
#endif