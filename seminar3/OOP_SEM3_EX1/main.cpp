#include "Math.cpp"
int main () {
   
    
    int add1 = Math::Add(1,2);
    std::cout << add1<<"\n";
    int add2 = Math::Add(1.2, 3.5);
    std::cout << add2 <<"\n";

    int mul1 = Math::Mul(3,5);
    std::cout << mul1 <<"\n";

    int mul2 = Math::Mul(1.4, 5.3, 7.1);
    std::cout << mul2 <<"\n";

    int count = 5;
    int addVec = Math::Add(count, 1,2,3,4,5);
    std::cout << "sum vec "<< addVec <<"\n";


    char *s1 = "Imi place", *s2 = "ora de OOP!";
    char * res = Math::Add(s1, s2);
    std::cout << res <<"\n";
    return 0;
}