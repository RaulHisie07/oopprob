#ifndef ARBORE_H
#define ARBORE_H

template <typename TipValoare>
class Arbore{
private:
   struct Nod{
    TipValoare valoare;
    Nod* parinte;
    Nod* primCopil;
    Nod* urmatorFrate;
    Nod(TipValoare val,Nod* p=nullptr)
        : valoare(val),parinte(p),primCopil(nullptr),urmatorFrate(nullptr){}
   };
   Nod* radacina;

   void stergeSubarbore(Nod* nod);
   Nod* cautaRecursiv(Nod* nod, bool (*compara)(const TipValoare&,const TipValoare&));
   int numaraCopiiRecursiv(Nod* nod) const;
public:
   using NodArbore=Nod;

   Arbore();
   ~Arbore();

   void adaugaNod(TipValoare valoare, Nod* parinte=nullptr);
   Nod* obtineNod(Nod* parinte=nullptr);
   void stergeNod(Nod* nod);
   Nod* cauta(bool (*compara)(const TipValoare&, const TipValoare&));
   void insereaza(TipValoare valoare, Nod* parinte, int pozitie);
   void sorteaza(Nod *nod, bool (*compara)(const TipValoare&, const TipValoare&)=nullptr);
   int numara(Nod* nod=nullptr) const;
};
#endif