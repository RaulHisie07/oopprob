#include <iostream>
#include "elev.h"
using namespace std;

int main()
{
    elev elev1;
    elev elev2;
    elev1.set_nume("maria");
    elev2.set_nume("popescu");
    elev1.set_notamate(8.4);
    elev2.set_notamate(8.9);
    elev1.set_notaengleza(10);
    elev2.set_notaengleza(9.5);
    elev1.set_notaistorie(9.4);
    elev2.set_notaistorie(8.2);
    cout<<elev1.get_medie();


    return 0;
}
