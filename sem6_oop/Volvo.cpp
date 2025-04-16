#include "Volvo.h"
#include <cstring>

Volvo::Volvo()
{
    init_masina();
}

void Volvo::init_masina()
{
    capacitate=60;
    consum=8;
    viteza[ploaie]=80;
    viteza[soare]=120;
    viteza[zapada]=70;
    strcpy(nume_masina, "Volvo");
}

float Volvo::race(float lungime_circuit, Vreme vreme)
{
    float carburant_necesar=(lungime_circuit/100)*consum;
    if(carburant_necesar>capacitate)
       return -1;
    return lungime_circuit/viteza[vreme];
    
}