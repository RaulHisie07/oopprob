#include "BMW.h"
#include <cstring>

BMW::BMW()
{
    init_masina();
}

void BMW::init_masina()
{
    capacitate=55;
    consum=9;
    viteza[ploaie]=90;
    viteza[soare]=140;
    viteza[zapada]=80;
    strcpy(nume_masina,"BMW");

}

float BMW::race(float lungime_circuit,Vreme vreme)
{
    float carburant_necesar=(lungime_circuit/100)*consum;
    if(carburant_necesar>capacitate)
       return -1;
    return lungime_circuit/viteza[vreme];
}