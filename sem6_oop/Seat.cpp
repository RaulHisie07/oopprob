#include "Seat.h"
#include <cstring>

Seat::Seat()
{
    init_masina();
}

void Seat::init_masina()
{
    capacitate=55;
    consum=9;
    viteza[ploaie]=70;
    viteza[soare]=110;
    viteza[zapada]=60;
    strcpy(nume_masina,"Seat");

}

float Seat::race(float lungime_circuit,Vreme vreme)
{
    float carburant_necesar=(lungime_circuit/100)*consum;
    if(carburant_necesar>capacitate)
       return -1;
    return lungime_circuit/viteza[vreme];
}