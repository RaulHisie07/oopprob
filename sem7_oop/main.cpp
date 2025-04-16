#include <iostream>
#include "Arbore.h"

template <typename TipValoare>
void afiseazaCopii(typename Arbore<TipValoare>::NodArbore* nod) {
    if (nod == nullptr) return;
    std::cout << "Copiii nodului cu valoarea " << nod->valoare << ": ";
    typename Arbore<TipValoare>::NodArbore* copil = nod->primCopil;
    while (copil != nullptr) {
        std::cout << copil->valoare << " ";
        copil = copil->urmatorFrate;
    }
    std::cout << "\n";
}

int main() {
    Arbore<int> arbore;

    arbore.adaugaNod(1);
    Arbore<int>::NodArbore* radacina = arbore.obtineNod();
    arbore.adaugaNod(2, radacina);
    arbore.adaugaNod(3, radacina);
    arbore.adaugaNod(4, radacina);

    arbore.insereaza(5, radacina, 1);
    arbore.sorteaza(radacina);

    std::cout << "Numar total noduri: " << arbore.numara() << "\n";

    auto comparaCautare = [](const int& a, const int& b) { return a == 3; };
    Arbore<int>::NodArbore* gasit = arbore.cauta(comparaCautare);
    if (gasit) {
        std::cout << "Nod gasit cu valoarea: " << gasit->valoare << "\n";
    }

    arbore.stergeNod(gasit);
    std::cout << "Numar total noduri dupa stergere: " << arbore.numara() << "\n";

    std::cout << "\n--- Exemplu cu sortare personalizata ---\n\n";

    Arbore<int> arbore2;

    arbore2.adaugaNod(10);
    Arbore<int>::NodArbore* radacina2 = arbore2.obtineNod();
    arbore2.adaugaNod(30, radacina2);
    arbore2.adaugaNod(20, radacina2);
    arbore2.adaugaNod(40, radacina2);
    arbore2.adaugaNod(15, radacina2);

    std::cout << "Inainte de sortare:\n";
    afiseazaCopii<int>(radacina2);

    auto comparaDescrescator = [](const int& a, const int& b) { return a > b; };
    arbore2.sorteaza(radacina2, comparaDescrescator);

    std::cout << "Dupa sortare descrescatoare:\n";
    afiseazaCopii<int>(radacina2);

    return 0;
}