#ifndef CIRCUIT_H
#define CIRCUIT_H

#include "car.h"
#include <iostream>

class Circuit
{
private:
  float lungime;
  Vreme vreme;
  Car* cars[10];
  int nr_masini;
public:
   Circuit();
   void SetLenght(float l);
   void SetWeather(Vreme w);
   void AddCar(Car* c);
   void Race();
   void ShowFinalRanks();
   void ShowWhoDidNotFinish();
   

};

#endif //CIRCUIT_H