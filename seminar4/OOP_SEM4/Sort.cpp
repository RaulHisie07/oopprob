#include "Sort.h"
#include <cstring>
#include <iostream>
#include <cstdlib>
#include <initializer_list>
#include <ctime>
#include <cstdarg> //parametrii variadici
using namespace std;


// pentru insertsort
void Sort::InsertSort(bool ascendent)
{
    for(int i=1;i<count;i++)
    {
        int val=arr[i],j=i-1;
        if(ascendent)
        {
          while(j>0 && arr[j]>val)
          {
            arr[j+1]=arr[j];
            j--;
          }
        }
        else
        {
            while(j>0 && arr[j]<val)
          {
            arr[j+1]=arr[j];
            j--;
          }
        }
        arr[j+1]=val;
    }
    
}
//pentru quicksort
int pivotdescr(int arr[],int n,int m)
{
    int x = arr[n];  
    int i = n + 1;   
    int j = m;       

    while (i <= j) {
        
        while (arr[i] > x && i <= m) i++;  

       
        while (arr[j] < x && j >= n) j--;  
        if (i < j) {
            swap(arr[i], arr[j]);
        }
    }

    
    swap(arr[n], arr[j]);  
    return j;  
}
int pivotcresc(int arr[],int n,int m)
{
    int x=arr[n],i=n+1,j=1;
    while(i<=j)
    {
        if(arr[i]<=x)
          i++;
        else if(arr[j]>=x)
          j--;
        else if(i<j && arr[i]>x && arr[j]<x)
             swap(arr[i],arr[j]);
    }
    arr[n]=arr[i-1];
    arr[i-1]=x;
    return i-1;
}
void QuickSortcresc(int arr[],int n,int m)
{
    if(n<m)
    {
        int mij=pivotcresc(arr,n,m);
        QuickSortcresc(arr,n,mij-1);
        QuickSortcresc(arr,m+1,m);
    }
}
void QuickSortdescr(int arr[],int n,int m)
{
    if(n<m)
    {
        int mij=pivotdescr(arr,n,m);
        QuickSortdescr(arr,n,mij-1);
        QuickSortdescr(arr,m+1,m);
    }
}
void Sort::QuickSort(bool ascendent)
{  
    if(ascendent==false)
      QuickSortdescr(arr,0,count-1);
    else QuickSortcresc(arr,0,count-1);
    
}

//bubblesort
void Sort::BubbleSort(bool ascendent)
{
    for(int i = 0; i < count - 1; i++) {
        for(int j = 0; j < count - 1 - i; j++) 
        {
            if (ascendent && arr[j]>arr[j+1]) 
            {
                swap(arr[j],arr[j+1]);
            }
            else if (!ascendent && arr[j]<arr[j+1]) 
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void Sort::Print()
{
    for(int i=0;i<count;i++)
       cout<<arr[i]<<' ';
    
}
int Sort::GetElementsCount()
{
    return count;
}
int Sort::GetElementFromIndex(int index)
{
    return arr[index];
}
Sort::Sort(int count, int min, int max) // generarea de nr intre min si max
{
    srand(time(nullptr)); // se initializeaza
    for(int i=0;i<count;i++)
    {
        arr[i]=min+rand()%(max-min+1);
    }
}
Sort::Sort(initializer_list <int> val)
{
    int i=0;
    for(int j:val)
      arr[i++]=j;
    count=i;
}
Sort::Sort(int v[],int nr_elem)
{
    count = nr_elem;
    for(int i=0;i<nr_elem;i++)
       arr[i]=v[i];
}
Sort::Sort(int count, ...)
{
    va_list arg;
    va_start(arg,count);
    for(int i=0;i<count;i++)
    {
        arr[i]=va_arg(arg,int);
    }
    va_end(arg);
}
Sort::Sort(const char s[100])
{
    int nr_elem=0;
    int numar=0;
    for(int i=0;i<strlen(s);i++)
    {
        if(s[i]!=',')
          numar=numar*10+(s[i]-'0');
        else
        {
            arr[nr_elem++]=numar;
            numar=0;
        }
    }
    arr[nr_elem]=numar;
    nr_elem++;
}
