#include <iostream>
#include "map.h"
int main()
{
    map<int,const char*>m;
    m[10] = "C++";
    m[20] = "test";
    m[30] = "Poo";
    m="test";
    for (auto[key, value, index] : m)
    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }
    m[20] = "result";
    for (auto[key, value, index] : m)
    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }
    //m.print();

    return 0;
}