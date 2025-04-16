#ifndef VOLVO_H
#define VOLVO_H
#include "car.h"

class Volvo: public Car
{
public:
   Volvo();
   void init_masina();
   float race(float lungime_circuit, Vreme vreme);
};
#endif