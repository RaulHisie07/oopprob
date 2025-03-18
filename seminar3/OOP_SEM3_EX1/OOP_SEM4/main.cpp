#include <iostream>
#include "Sort.h"
using namespace std;
int main()
{
    cout<<"exemplu pentru constructorul 1"<<endl;
    Sort function1(7,10,31);
    function1.Print();
    cout<<"nr de elemente este " << function1.GetElementsCount()<< endl;
    cout<<"elementul de la indexul 4 este " << function1.GetElementFromIndex(4)<<endl;
    function1.InsertSort(false);
    function1.Print();

    return 0;
}