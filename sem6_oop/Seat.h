#ifndef SEAT_H
#define SEAT_H
#include "car.h"

class Seat: public Car
{
public:
  Seat();
  void init_masina();
  float race(float lungime_circuit,Vreme vreme);
};
#endif