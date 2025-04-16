#include "RangeRover.h"
#include <cstring>

RangeRover::RangeRover()
{
    init_masina();
}

void RangeRover::init_masina()
{
    capacitate=80;
    consum=12;
    viteza[ploaie]=100;
    viteza[soare]=130;
    viteza[zapada]=00;
    strcpy(nume_masina, "RangeRover");
}

float RangeRover::race(float lungime_circuit, Vreme vreme)
{
    float carburant_necesar=(lungime_circuit/100)*consum;
    if(carburant_necesar>capacitate)
       return -1;
    return lungime_circuit/viteza[vreme];
    
}