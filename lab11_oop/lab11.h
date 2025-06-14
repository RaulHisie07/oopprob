#include <iostream>
#include <string>
#include <vector>
#include <tuple>
class catalog
{
protected:
   std::vector<student> studenti;
public:
   virtual void adauga_student(const student& stud) = 0;

   
   virtual std::vector<std::pair<materie*,double>> get_note_student(const char * nr_matricol)
   {
      auto it = std::find_if(studenti.begin(), studenti.end(),
            [&nr_matricol](const student& s) {
                return s.get_nr_matricol() == nr_matricol;
            });
        
        if (it != studenti.end()) {
            return it->get_note();
        }
        
        return std::vector<std::pair<materie*, double>>();
   }
   virtual double get_medie_student(const char* nr_matricol)
   {
      auto it = std::find_if(studenti.begin(), studenti.end(),
            [&nr_matricol](const student& s) {
                return s.get_nr_matricol() == nr_matricol;
            });
        
        if (it != studenti.end()) {
            return it->calculare_medie();
        }
        
        return 0.0;
   }
   virtual std::vector<std::pair<std::string, double>> ranking_studenti() {
        std::vector<std::pair<std::string, double>> ranking;
        
        
        std::for_each(studenti.begin(), studenti.end(),
            [&ranking](const student& s) {
                ranking.push_back({s.get_nume(), s.calculare_medie()});
            });
        
        
        std::sort(ranking.begin(), ranking.end(),
            [](const std::pair<std::string, double>& a, 
               const std::pair<std::string, double>& b) {
                return a.second > b.second;
            });
        
        return ranking;
    }

}; 




class materie{
private:
  const char * nume_materie;
  const char * tip_materie;
  int numar_credite;
public:
   materie(const char * nume, const char * tip , int credite)
   {
    nume_materie=nume;
    tip_materie=tip;
    numar_credite=credite;
   }
   ~materie()
   {
    delete [] nume_materie;
    delete [] tip_materie;
   }
   const char * get_nume_materie()
   {
    return nume_materie;
   }
   const char * get_tip_materie()
   {
    return tip_materie;
   }
   int get_numar_credite()
   {
    return numar_credite;
   }
};

class romana: public materie
{
   public: 
   romana():materie("romana","obligatorie",5){}
};
class informatica: public materie
{
  informatica():materie("informatica","obligatorie",6){}

};
class mate:public materie
{
  mate():materie("mate","obligatorie",6){}
};
class engleza:public materie
{
 engleza():materie("engleza","optional",2){}
};
class fizica:public materie
{
 fizica():materie("fizica","obligatorie",4){}
};
class sport:public materie
{
 sport():materie("sport","optional",2){}
};
class student
{
private:
   int numar_materii;
   const char * nume_student;
   const char * numar_matricol;
   const char * program_invatare;
   std::vector<std::pair<materie*,double>> note;
public:
   student(const char * nume ,const char * nr_matricol ,const char * progr_invatare,int nr_materii)
   {
    nume_student=nume;
    numar_matricol=nr_matricol;
    program_invatare=progr_invatare;
    numar_materii=nr_materii;
   }
   ~student()
   {
    delete [] nume_student;
    delete [] numar_matricol;
    delete [] program_invatare;
    for(auto& pair:note)
    {
        delete pair.first;
    }
   
   }
   void adaugare_materie_nota(materie* m, double nota)
   {
      note.push_back({m,nota});
   }
   double calculare_medie() const
   {
      double suma=0;
      for(const auto& pair : note)
      {
        suma=suma+pair.second;
      }
      return suma/numar_materii;
   }
   const char * get_nume() const
   {
    return nume_student;
   }
   const char * get_nr_matricol () const
   {
    return numar_matricol;
   } 
   const char * get_program_invatare() const
   {
    return program_invatare;
   }
   std::vector<std::pair<materie*,double>> get_note()
   {
    return note;
   }
   
};

class catalog_ro : public catalog {
public:
    void adauga_student(const student& stud) override {
        if(stud.get_program_invatare() == "romana") {
            studenti.push_back(stud);
        } else {
            std::cout << "Studentul nu poate fi adaugat la catalogul RO\n";
        }
    }
    
    
    void afiseaza_studenti_ro() {
        std::cout << " Catalog Romana:\n";
        std::for_each(studenti.begin(), studenti.end(),
            [](const student& s) {
                std::cout << "Student: " << s.get_nume() 
                         << " (Nr. matricol: " << s.get_nr_matricol() 
                         << ") - Media: " << s.calculare_medie() << "\n";
            });
    }
};


class catalog_en : public catalog {
public:
    void adauga_student(const student& stud) override {
        if(stud.get_program_invatare() == "engleza") {
            studenti.push_back(stud);
        } else {
            std::cout << "Studentul nu poate fi adaugat la catalogul EN \n";
        }
    }
    
   
    void display_students_en() {
        std::cout << "English Catalog:\n";
        std::for_each(studenti.begin(), studenti.end(),
            [](const student& s) {
                std::cout << "Student: " << s.get_nume() 
                         << " (Student ID: " << s.get_nr_matricol() 
                         << ") - Average: " << s.calculare_medie() << "\n";
            });
    }
};
