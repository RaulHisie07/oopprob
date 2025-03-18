#include <iostream>
#include "NumberList.h"
using namespace std;
int main()
{
    NumberList lista;
    lista.Init();
    lista.Add(5);
    lista.Add(4);
    lista.Add(8);
    lista.Add(9);
    lista.Add(1);
    lista.Add(6);
    lista.Print();
    cout<<endl;
    lista.Sort();
    lista.Print();
    return 0;
}
