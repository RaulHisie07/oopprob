#include <iostream>

class elev
{
    std::string nume;
    float notamate;
    float notaengleza;
    float notaistorie;
public:
    void set_nume(std::string n);
    void set_notamate(float nota);
    void set_notaengleza(float nota);
    void set_notaistorie(float nota);
    std::string get_nume();
    float get_notamate();
    float get_notaengleza();
    float get_notaistorie();
    float get_medie();
};
