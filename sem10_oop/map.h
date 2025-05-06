#include <iostream>
#include <cstring>
template<typename K,typename V>
struct triplet
{
    K key;
    V value;
    int index;
};
template <typename K,typename V>
struct pereche
{
   K key;
   V value;
   
};
template <typename K, typename V>
class map
{
private:
  
  int contor;
  pereche<K,V> vector_map[100];
  int index_repetare;
public:
  map<K,V>()
  {
    contor=0;
    index_repetare=0;
  }
 map& operator[](K cheie)
 {  
    bool found=0;
    for(int i=0;i<contor;i++)
    {
        if(vector_map[i].key==cheie)
           { 
            found=1;
            index_repetare=i;
           }
          
    } 
    if(found==0)
       vector_map[contor].key=cheie;
     return *this;

 }
 void operator=(V valoare)
 {  
    if(index_repetare!=0)
     {
        vector_map[index_repetare].value=valoare;
     }
    else{
        vector_map[contor].value=valoare;
        contor++;
    }
    index_repetare=0;
        
 }
 void print()
 {
    for(int i=0;i<contor;i++)
    {
        std::cout<<vector_map[i].key<<' '<<vector_map[i].value<<'\n';
    }
 }
 struct iterator
 {
    pereche<K,V> * ptr;
    int index;
    iterator(pereche<K,V>* p ,int i): ptr(p),index(i){}
    bool operator!=(const iterator& i1) const
    {
        return ptr!=i1.ptr;
    }
    iterator& operator++()
    {
       ++ptr;
       ++index;
       return *this;
    }
    triplet<K,V> operator*() const
    {
        triplet<K,V> t;
        t.key=ptr->key;
        t.value=ptr->value;
        t.index=index;
        return t;
    }
 };
 iterator begin()
 {
    return iterator(vector_map,0);
 }
 iterator end()
 {
    return iterator(vector_map+contor,contor);
 }
 void Set(K cheie,V valoare)
 {
    for(int i=0;i<contor;i++)
    {
        if(vector_map[i].key==cheie)
        {
           vector_map[i].value=valoare;
           break;
        }
    }
 }
 bool Get(const K& key,const V& value)
 {
    bool found = 0;
    for(int i=0;i<contor;i++)
    {
        if(vector_map[i].key==key)
        {
            found=1;
            vector_map[i].value=key;
            break;
        }
    }
    return found;
 }
 int Count()
 {
    return contor;
 }
 bool Delete(const K& key)
 {
    bool found =0;
    for(int i=0;i<contor;i++)
    {
        if(vector_map[i].key==key)
        {
            found=1;
            for(int j=i+1;j<contor;j++)
            {
                vector_map[j-1]=vector_map[j];

            }
            contor--;
            break;
        }
    }
    return found;
 }
 void Clear()
 {
    contor=0;
 }
 bool Includes(const map<K,V>& map)
 {
    int egalitati=0;
    if(map.contor<contor)
    {
        for(int i=0;i<map.contor;i++)
        {
            for(int j=0;j<contor;j++)
            {
                if(map.vector_map[i].key==vector_map[j].key)
                  egalitati++;
            }
        }
        if(egalitati==map.contor )
           return true;
        else return false;
    }
    else
    {
        for(int i=0;i<contor;i++)
        {
            for(int j=0;j<map.contor;j++)
            {
                if(vector_map[i].key==map.vector_map[j].key)
                  egalitati++;
            }
        }
        if(egalitati==contor )
           return true;
        else return false;
    }
 }
};
