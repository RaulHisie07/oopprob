#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <queue>
struct comparare
{
    bool operator()(const std::pair<std::string,int>&a, const std::pair<std::string,int>&b)
    {
       if(a.second!=b.second)
       {
          return a.second<b.second;
       }
       else return a.first>b.first;
    }
};
int main()
{
    std::ifstream fisier("input.txt");
    if(!fisier.is_open())
    {
        std::cout<<"nu s-a deschis corect fisierul"<<'\n';
        return 1;

    }
    std::string textul; // se creeaza obiectul din clasa string
    std::getline(fisier,textul);// se citeste prima linie din fisier si se pune in textul
    std::vector<std::string> vector_cuvinte;
    size_t start=0;
    size_t sfarsit=0;
    while(start<textul.size())
    {
        sfarsit=textul.find_first_of(" ,.!?",start);
        if(sfarsit==std::string::npos)
           sfarsit=textul.size();
        std::string cuvant=textul.substr(start,sfarsit-start);
        if(!cuvant.empty())
        {   
            for(int i=0;i<cuvant.size();i++)
            {
                if(cuvant[i]>='A' && cuvant[i]<='Z')
                    cuvant[i]+=32;
            }
            vector_cuvinte.push_back(cuvant);
        }
        start=sfarsit+1;
    }
    /**std::cout << "cuvintele din fisier:\n";
    for (const std::string& c : vector_cuvinte) {
        std::cout << c << "\n";
    }
        **/

    std::map<std::string,int> mapa;
    for(const std::string& c :vector_cuvinte)
    {
        mapa.insert(std::pair<std::string,int>(c,0));
    }
    for(const std::string& c:vector_cuvinte)
    {
        mapa[c]=mapa[c]+1;
    }
    std::priority_queue<std::pair<std::string,int>,
                        std::vector<std::pair<std::string,int>>,
                        comparare> coada;
    for(const auto& pereche : mapa)
    {
        coada.push(pereche);
    }
    while(!coada.empty())
    {
        auto pereche=coada.top();
        coada.pop();
        std::cout<<pereche.first<<','<<pereche.second<<'\n';
    }
    fisier.close();
    return 0;
}