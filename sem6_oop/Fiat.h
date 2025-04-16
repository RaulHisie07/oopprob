#ifndef FIAT_H
#define FIAT_H
#include "car.h"

class Fiat: public Car
{
public:
  Fiat();
  void init_masina();
  float race(float lungime,Vreme vreme);
};
#endif