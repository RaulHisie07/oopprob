#include "Number.h"
#include <iostream>

int main() 
{

    Number num1("110101", 2); // 110101 in baza 2 (53 in baza 10)
    Number num2("1F4", 16);   // 1F4 in baza 16 (500 in baza 10)
    num1.Print();
    num2.Print();
    
    // Compararea numerelor
    std::cout << "num1 > num2: " << (num1 > num2) << std::endl;
    std::cout << "num1 < num2: " << (num1 < num2) << std::endl;
    std::cout << "num1 == num2: " << (num1 == num2) << std::endl;
    
    // baza si nr de cifre
    std::cout << "Baza num1: " << num1.GetBase() << std::endl;
    std::cout << "nr litere num1: " << num1.GetDigitsCount() << std::endl;
    
    // schimbarea bazei si prima cifra
    num1.SwitchBase(10);
    num1.Print();
    std::cout << "prima cifra: " << num1[0] << std::endl;
    
    Number sum = num2 + num1;
    std::cout << "Suma: ";
    sum.Print();

    Number diff = num2 - num1;
    std::cout << "Diferenta: ";
    diff.Print();

    // operatorii postfixat si prefixat
    --num1;
    std::cout << "aplicarea lui --num1 (prefix): ";
    num1.Print();
    num1--;
    std::cout << "aplicarea lui num1-- (postfix): ";
    num1.Print();
    return 0;
}
