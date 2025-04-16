#include "Fiat.h"
#include <cstring>

Fiat::Fiat()
{
    init_masina();
}

void Fiat::init_masina()
{
    capacitate=40;
    consum=6;
    viteza[ploaie]=60;
    viteza[soare]=100;
    viteza[zapada]=50;
    strcpy(nume_masina, "Fiat");
}

float Fiat::race(float lungime_circuit, Vreme vreme)
{
    float carburant_necesar=(lungime_circuit/100)*consum;
    if(carburant_necesar>capacitate)
       return -1;
    return lungime_circuit/viteza[vreme];
    
}