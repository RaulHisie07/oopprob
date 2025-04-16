
#include "Arbore.h"

template <typename TipValoare>
Arbore<TipValoare>::Arbore() : radacina(nullptr) {}

template <typename TipValoare>
Arbore<TipValoare>::~Arbore() {
    stergeSubarbore(radacina);
}

template <typename TipValoare>
void Arbore<TipValoare>::stergeSubarbore(Nod* nod) {
    if (nod == nullptr) return;
    Nod* copil = nod->primCopil;
    while (copil != nullptr) {
        Nod* urmator = copil->urmatorFrate;
        stergeSubarbore(copil);
        copil = urmator;
    }
    delete nod;
}

template <typename TipValoare>
void Arbore<TipValoare>::adaugaNod(TipValoare valoare, Nod* parinte) {
    Nod* nodNou = new Nod(valoare, parinte);
    if (parinte == nullptr) {
        radacina = nodNou;
        return;
    }
    nodNou->urmatorFrate = parinte->primCopil;
    parinte->primCopil = nodNou;
}

template <typename TipValoare>
typename Arbore<TipValoare>::Nod* Arbore<TipValoare>::obtineNod(Nod* parinte) {
    return (parinte == nullptr) ? radacina : parinte;
}

template <typename TipValoare>
void Arbore<TipValoare>::stergeNod(Nod* nod) {
    if (nod == nullptr) return;
    if (nod == radacina) {
        radacina = nullptr;
        stergeSubarbore(nod);
        return;
    }

    
    Nod* parinte = nod->parinte;
    Nod* copil = parinte->primCopil;
    Nod* precedent = nullptr;
    
    while (copil != nullptr && copil != nod) { 
        precedent = copil;
        copil = copil->urmatorFrate;
    }

   
    if (copil == nullptr) return; 

    if (precedent == nullptr) {
        parinte->primCopil = nod->urmatorFrate;
    } else {
        precedent->urmatorFrate = nod->urmatorFrate;
    }

    nod->urmatorFrate = nullptr;
    stergeSubarbore(nod);
}

template <typename TipValoare>
typename Arbore<TipValoare>::Nod* Arbore<TipValoare>::cautaRecursiv(Nod* nod, bool (*compara)(const TipValoare&, const TipValoare&)) {
    if (nod == nullptr) return nullptr;
    if (compara(nod->valoare, nod->valoare)) return nod;

    Nod* copil = nod->primCopil;
    while (copil != nullptr) {
        Nod* rezultat = cautaRecursiv(copil, compara);
        if (rezultat != nullptr) return rezultat;
        copil = copil->urmatorFrate;
    }
    return nullptr;
}

template <typename TipValoare>
typename Arbore<TipValoare>::Nod* Arbore<TipValoare>::cauta(bool (*compara)(const TipValoare&, const TipValoare&)) {
    return cautaRecursiv(radacina, compara);
}

template <typename TipValoare>
void Arbore<TipValoare>::insereaza(TipValoare valoare, Nod* parinte, int pozitie) {
    if (parinte == nullptr || pozitie < 0) return;

    Nod* nodNou = new Nod(valoare, parinte);
    if (pozitie == 0) {
        nodNou->urmatorFrate = parinte->primCopil;
        parinte->primCopil = nodNou;
        return;
    }

    Nod* copil = parinte->primCopil;
    int index = 0;
    while (copil != nullptr && index < pozitie - 1) {
        copil = copil->urmatorFrate;
        index++;
    }

    if (copil == nullptr) {
        delete nodNou;
        return;
    }

    nodNou->urmatorFrate = copil->urmatorFrate;
    copil->urmatorFrate = nodNou;
}

template <typename TipValoare>
void Arbore<TipValoare>::sorteaza(Nod* nod, bool (*compara)(const TipValoare&, const TipValoare&)) {
    if (nod == nullptr || nod->primCopil == nullptr) return;

    
    if (!compara) { 
        compara = [](const TipValoare& a, const TipValoare& b) { return a < b; };
    }

    bool sortat;
    do {
        sortat = true;
        Nod* copil = nod->primCopil;
        Nod* precedent = nullptr;
        while (copil != nullptr && copil->urmatorFrate != nullptr) {
            if (compara(copil->urmatorFrate->valoare, copil->valoare)) {
                sortat = false;
                Nod* urmator = copil->urmatorFrate;
                copil->urmatorFrate = urmator->urmatorFrate;
                urmator->urmatorFrate = copil;

                if (precedent == nullptr) {
                    nod->primCopil = urmator;
                } else {
                    precedent->urmatorFrate = urmator;
                }

                Nod* temp = copil;
                copil = urmator;
                precedent = copil;
            } else {
                precedent = copil;
                copil = copil->urmatorFrate;
            }
        }
    } while (!sortat);
}
template <typename TipValoare>
int Arbore<TipValoare>::numaraCopiiRecursiv(Nod* nod) const {
    if (nod == nullptr) return 0;
    int total = 1; // Numărăm nodul curent
    Nod* copil = nod->primCopil;
    while (copil != nullptr) {
        total += numaraCopiiRecursiv(copil); // Adăugăm copiii
        copil = copil->urmatorFrate;
    }
    return total;
}

template <typename TipValoare>
int Arbore<TipValoare>::numara(Nod* nod) const {
    return (nod == nullptr) ? numaraCopiiRecursiv(radacina) : numaraCopiiRecursiv(nod);
}

template class Arbore<int>;