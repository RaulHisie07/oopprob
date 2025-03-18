#include <iostream>
#include "elev.h"

void elev::set_nume(std::string n)
{
    nume=n;
}
void elev::set_notamate(float nota)
{
    if(nota>=1 && nota<=10)
      notamate=nota;
}
void elev::set_notaengleza(float nota)
{
    if(nota>=1 && nota<=10)
       notaengleza=nota;
}
void elev::set_notaistorie(float nota)
{
    if(nota>=1 && nota<=10)
        notaistorie=nota;
}
std::string elev::get_nume()
{
    return nume;
}
float elev::get_notamate()
{
    return notamate;
}
float elev::get_notaengleza()
{
    return notaengleza;
}
float elev::get_notaistorie()
{
    return notaistorie;
}
float elev::get_medie()
{
    return (notamate+notaengleza+notaistorie)/3.0;
}
