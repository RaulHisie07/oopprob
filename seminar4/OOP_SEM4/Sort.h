#include <iostream>
#include <initializer_list>
#include <vector>
class Sort
{
    
private:
    int count , arr[100];
public:
    Sort(int count, int min, int max);
    Sort(std::initializer_list <int> val);
    Sort(int v[],int nr_elem);
    Sort(int count, ...);
    Sort(const char s[100]);
    void InsertSort(bool ascendent=false);
    void QuickSort(bool ascendent=false);
    void BubbleSort(bool ascendent=false);
    void Print();
    int  GetElementsCount();
    int  GetElementFromIndex(int index);
};
