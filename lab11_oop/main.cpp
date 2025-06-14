#include <iostream>
#include "lab11.h"

int main() {
    
    catalog_ro catalog_romana;
    catalog_en catalog_engleza;
    
    
    romana* rom = new romana();
    informatica* info = new informatica();
    mate* matematica = new mate();
    engleza* eng = new engleza();
    fizica* fiz = new fizica();
    sport* sp = new sport();
    
    
    student stud1("Popescu Ion", "2023001", "romana", 4);
    stud1.adaugare_materie_nota(rom, 8.5);
    stud1.adaugare_materie_nota(info, 9.0);
    stud1.adaugare_materie_nota(matematica, 7.5);
    stud1.adaugare_materie_nota(fiz, 8.0);
    
    student stud2("Ionescu Maria", "2023002", "romana", 3);
    stud2.adaugare_materie_nota(rom, 9.5);
    stud2.adaugare_materie_nota(info, 8.5);
    stud2.adaugare_materie_nota(matematica, 9.0);
    
    
    student stud3("Mihnea Ion", "2023003", "engleza", 4);
    stud3.adaugare_materie_nota(eng, 9.0);
    stud3.adaugare_materie_nota(info, 8.0);
    stud3.adaugare_materie_nota(matematica, 8.5);
    stud3.adaugare_materie_nota(sp, 7.0);
    
    student stud4("Pavel Drexler", "2023004", "engleza", 3);
    stud4.adaugare_materie_nota(eng, 8.5);
    stud4.adaugare_materie_nota(info, 9.5);
    stud4.adaugare_materie_nota(fiz, 8.0);
    
    
    std::cout << "Adaugare studenti :" << std::endl;
    catalog_romana.adauga_student(stud1);
    catalog_romana.adauga_student(stud2);
    catalog_engleza.adauga_student(stud3);
    catalog_engleza.adauga_student(stud4);
    
    catalog_romana.afiseaza_studenti_ro();
    std::cout << std::endl;
    catalog_engleza.display_students_en();
    
    std::cout << "\n Testare functionalitati" << std::endl;
    
    
    double media = catalog_romana.get_medie_student("2023001");
    std::cout << "Media studentului 2023001: " << media << std::endl;
    
    auto note = catalog_romana.get_note_student("2023002");
    std::cout << "Notele studentului 2023002:" << std::endl;
    for(const auto& nota : note) {
        std::cout << "  " << nota.first->get_nume_materie() 
                  << ": " << nota.second << std::endl;
    }
    
    
    std::cout << "\n Ranking studenti catalog RO:" << std::endl;
    auto ranking_ro = catalog_romana.ranking_studenti();
    int pozitie = 1;
    std::for_each(ranking_ro.begin(), ranking_ro.end(),
        [&pozitie](const std::pair<std::string, double>& student_ranking) {
            std::cout << pozitie << ". " << student_ranking.first 
                      << " - Media: " << student_ranking.second << std::endl;
            pozitie++;
        });
    
    
    std::cout << "\n Ranking studenti catalog EN " << std::endl;
    auto ranking_en = catalog_engleza.ranking_studenti();
    pozitie = 1;
    std::for_each(ranking_en.begin(), ranking_en.end(),
        [&pozitie](const std::pair<std::string, double>& student_ranking) {
            std::cout << pozitie << ". " << student_ranking.first 
                      << " - Average: " << student_ranking.second << std::endl;
            pozitie++;
        });
    
    
    delete rom;
    delete info;
    delete matematica;
    delete eng;
    delete fiz;
    delete sp;
    
    return 0;
}