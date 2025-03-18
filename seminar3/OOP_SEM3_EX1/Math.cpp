#include "Math.h"

int Math::Add(int a, int b) { return a+b; }
int Math::Add(int a, int b, int c) { return a+b+c;}

int Math::Add(double a, double b) {return a+b;}
int Math::Add(double a, double b, double c) { return a + b+ c;}
int Math::Mul(int a, int b) {
    return a * b;
}
int Math::Mul(int a, int b, int c) {
    return a * b * c;
}
int Math::Mul(double a,double b) {
    return a * b;
}
int Math::Mul(double a,double b, double c) {
    return a * b * c;
}
int Math::Add(int count, ...)
{
    va_list args;          // Declaram o variabilă de tip va_list
    va_start(args, count); // Inițializăm lista de argumente variabile

    int sum = 0;
    for (int i = 0; i < count; i++)
    {
        sum += va_arg(args, int); // Extragem următorul argument de tip int
    }

    va_end(args); // Încheiem utilizarea listei de argumente
    return sum;
}
char* Math::Add(const char* s1, const char* s2) {
    char *resString;
    if (!s1 || !s2) {
        return nullptr; // Dacă unul dintre string-uri este nullptr, returnăm nullptr
    }
    int l1 = strlen(s1);
    int l2 = strlen(s2);
    resString = new char[l1+l2+1];
    strcpy(resString, s1);
    strcat(resString, s2);

    return resString;
}