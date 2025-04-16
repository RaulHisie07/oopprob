#include "Number.h"
#include <iostream>
#include <cstring>
#include <cmath>


Number::Number(const char* sir, int baza)
{
    this->baza= baza;
    this->sir = new char[strlen(sir) + 1];
    strcpy(this->sir, sir);
}


Number::~Number()
{
    delete[] sir;
}

Number::Number(const Number& numar)
{
    baza=numar.baza;
    sir=new char[strlen(numar.sir)+1];
    strcpy(sir,numar.sir);
}

Number& Number::operator=(const Number& numar)
{
    if(this!=&numar)
    {
        delete[] sir;
        baza=numar.baza;
        sir=new char[strlen(numar.sir)+1];
        strcpy(sir,numar.sir);
    }
    return *this;
}

void Number::SwitchBase(int baza_noua)
{
    int valoare=0,temp=0;
    int lungime=strlen(sir);
    for(int i=0;i<lungime;i++)
    {
        char l=sir[i];
        if(l>='0' && l<='9')
          temp=l-'0';
        else temp=l-'A'+10;
        valoare=valoare*baza+temp;
    }

    // convertirea la baza noua

    char v[50];
    int index=0,rest;
    while(valoare>0)
    {
      rest=valoare%baza_noua;
      if(rest<10)
        v[index++]=rest+'0';
      else v[index++]=rest-10+'A';
      valoare/=baza_noua;
    }
    v[index]='\0';
    for(int i=0;i<index/2;i++)
    {
        std::swap(v[i],v[index-i-1]);
    }
    delete[] sir;
    sir=new char[index+1];
    strcpy(sir,v);
    baza=baza_noua;
}

void Number::Print() const
{
    std::cout<<"Numarul: "<<sir<<" in baza "<<baza<<std::endl;
}
int Number::GetDigitsCount() const 
{
    return strlen(sir);
}
int Number::GetBase() const
{
    return baza;
}
char Number::operator[](int index) const
{
    return (index>=0 && index< GetDigitsCount()) ? sir[index]: '\0';
}
bool Number::operator>(const Number& numar) const 
{
    return std::stoi(sir, nullptr, baza) > std::stoi(numar.sir, nullptr, numar.baza);
}

bool Number::operator<(const Number& numar) const
{
    return std::stoi(sir, nullptr, baza) < std::stoi(numar.sir, nullptr, numar.baza);
}

bool Number::operator>=(const Number& numar) const 
{
    return !(*this < numar);
}

bool Number::operator<=(const Number& numar) const 
{
    return !(*this > numar);
}

bool Number::operator==(const Number& numar) const 
{
    return std::stoi(sir, nullptr, baza) == std::stoi(numar.sir, nullptr, numar.baza);
}
// operatorul prefixat care elimina prima cifra
Number& Number::operator--() 
{
    if (strlen(sir)>1)
    {
        for (int i=0;i<strlen(sir)-1;i++) 
        {
            sir[i]=sir[i+1];
        }
        sir[strlen(sir)-1] = '\0';
        
    }
    else {
        strcpy(sir, "0");
    }
    return *this;
}
//operatorul postfixat care elimina ultima cifra
Number Number::operator--(int) 
{
    Number copie = *this; 
    if (strlen(sir) > 1)
     {
        sir[strlen(sir)-1]='\0'; 
    } 
    else {
        strcpy(sir, "0"); 
    }

    return copie; 
}
Number Number::operator+(const Number& numar) const {
    int val1=0,val2=0;
    int lungime1=strlen(sir),lungime2=strlen(numar.sir);

    for(int i=0;i<lungime1;i++) {
        char c=sir[i];
        if(c>='0'&&c<='9') val1=val1*baza+(c-'0');
        else val1=val1*baza+(c-'A'+10);
    }

    for(int i=0;i<lungime2;i++) {
        char c=numar.sir[i];
        if(c>='0'&&c<='9') val2=val2*numar.baza+(c-'0');
        else val2=val2*numar.baza+(c-'A'+10);
    }

    int suma=val1+val2,baza_rezultat=10, index=0;
    char rezultat[50];

    while(suma>0) {
        int cifra=suma%baza_rezultat;
        if(cifra<10) rezultat[index]=cifra+'0';
        else rezultat[index]=cifra-10+'A';
        suma/=baza_rezultat;
        index++;
    }

    rezultat[index]='\0';
    for(int i=0;i<index/2;i++) {
        char aux=rezultat[i];
        rezultat[i]=rezultat[index-i-1];
        rezultat[index-i-1]=aux;
    }

    return Number(rezultat,baza_rezultat);
}

Number Number::operator-(const Number& numar) const {
    int val1=0,val2=0;
    int lungime1=strlen(sir),lungime2=strlen(numar.sir);

    for(int i=0;i<lungime1;i++) {
        char c=sir[i];
        if(c>='0'&&c<='9') val1=val1*baza+(c-'0');
        else val1=val1*baza+(c-'A'+10);
    }

    for(int i=0;i<lungime2;i++) {
        char c=numar.sir[i];
        if(c>='0'&&c<='9') val2=val2*numar.baza+(c-'0');
        else val2=val2*numar.baza+(c-'A'+10);
    }

    int diferenta=val1-val2,baza_rezultat=10,index=0;
    char rezultat[50];

    while(diferenta>0) {
        int cifra=diferenta%baza_rezultat;
        if(cifra<10) rezultat[index]=cifra+'0';
        else rezultat[index]=cifra-10+'A';
        diferenta/=baza_rezultat;
        index++;
    }

    rezultat[index]='\0';
    for(int i=0;i<index/2;i++) {
        char aux=rezultat[i];
        rezultat[i]=rezultat[index-i-1];
        rezultat[index-i-1]=aux;
    }

    return Number(rezultat,baza_rezultat);
}

