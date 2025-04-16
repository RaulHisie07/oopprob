#ifndef BMW_H
#define BMW_H
#include "car.h"

class BMW: public Car
{
public:
  BMW();
  void init_masina();
  float race(float lungime,Vreme vreme);
};
#endif