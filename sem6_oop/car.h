#ifndef CAR_H
#define CAR_H
#include <cstring>


enum Vreme {ploaie,soare,zapada} ;

class Car{
protected:
   float capacitate, consum, viteza[3];
   char nume_masina[20];
public:
   virtual void init_masina()=0;
   virtual float race(float lungime_circuit,Vreme vreme)=0;
   const char* GetName();
   virtual ~Car() {};
};

#endif //CAR_H