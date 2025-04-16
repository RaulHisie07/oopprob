#include "Circuit.h"
#include <cstring>

Circuit::Circuit()
{
    nr_masini=0;
}
void Circuit::SetLenght(float l)
{
    lungime=l;
}
void Circuit::SetWeather(Vreme v)
{
    vreme=v;
}
void Circuit::AddCar(Car* c)
{
    if(nr_masini<10)
    {
        cars[nr_masini]=c;
        nr_masini++;
    }
}
void Circuit::Race()
{
    for(int i=0;i<nr_masini;i++)
    {
        cars[i]->race(lungime,vreme);
    }
}
void Circuit::ShowFinalRanks()
{
    for(int i=0;i<nr_masini-1;i++)
    {
        for(int j=i+1;j<nr_masini;j++)
        {
            float timp1=cars[i]->race(lungime,vreme);
            float timp2=cars[j]->race(lungime,vreme);
            if((timp1>0 && timp2>0) && (timp1>timp2))
            {
                Car* aux=cars[i];
                cars[i]=cars[j];
                cars[j]=aux;
            }
        }
    }
    std::cout<<"Clasamentul:\n";
    for(int i=0;i<nr_masini;i++)
    {
        float timp=cars[i]->race(lungime,vreme);
        if(timp>0)
           std::cout<<cars[i]->GetName()<<" - "<<timp<<" ore\n";
    }
}
void Circuit::ShowWhoDidNotFinish()
{
    std::cout<<"masinile care nu au terminat cursa:\n";
    for(int i=0;i<nr_masini;i++)
    {
        if(cars[i]->race(lungime,vreme)<0)
            std::cout<<cars[i]->GetName()<<"nu a avut suficient carburant\n";

    }
}