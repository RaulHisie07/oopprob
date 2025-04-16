#include <iostream>
#include <cstring>
#include <cmath>
class Number
{
private:
  char* sir;
  int baza;
public:
   Number(const char * value, int base); 
   ~Number(); // destructorul
   Number(const Number& numar);//constr. de copiere
   Number& operator=(const Number& numar);


   void SwitchBase(int baza_noua);
   void Print() const;
   int  GetDigitsCount() const; 
   int  GetBase() const; 

   Number operator+(const Number& numar) const;
   Number operator-(const Number& numar) const;

   bool operator>(const Number& numar) const;
   bool operator<(const Number& numar) const;
   bool operator>=(const Number& numar) const;
   bool operator<=(const Number& numar) const;
   bool operator==(const Number& numar) const;

   char operator[](int index) const;

   Number& operator--(); // prefixata
   Number operator--(int); // postfixata

};
