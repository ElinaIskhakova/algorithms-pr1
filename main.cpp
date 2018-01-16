#include <QtCore/QCoreApplication>
#include <iostream>
#include <ctime>
#include <iomanip>
#include<stdlib.h>
#include<time.h>
#include<stdio.h>
using namespace std;
void Selection(int*, int);
void radix(int *,int*,int*,int,int);
int main()
{
    srand(time(NULL));
    setlocale(LC_ALL, "rus");
    cout << "Length of array: ";
    int size_array;
    int*c= new int [size_array];
    int*br= new int [size_array];
    cin >> size_array;
    int *sorted_array = new int [size_array];
    int *sorted_array1 = new int [size_array];
    for (int counter = 0; counter < size_array; counter++)
    {
        sorted_array[counter] = rand() % 100;
        cout << setw(2) << sorted_array[counter] << "  ";
    }
    for (int counter = 0; counter < size_array; counter++)
    {
        sorted_array1[counter] = rand() % 100;
        cout << setw(2) << sorted_array1[counter] << "  ";
    }
    cout << "\n\n";
    clock_t start=clock();
    radix(sorted_array,br,c,size_array, size_array);
    clock_t end=clock();
double seconds=(double)(end-start)/CLOCKS_PER_SEC;
clock_t start1=clock();
Selection(sorted_array1, size_array);
clock_t end1=clock();
double seconds1=(double)(end1-start1)/CLOCKS_PER_SEC;
cout<<"Array of radix:\n";
    for (int counter = 0; counter < size_array; counter++)
    {
        cout << setw(2) << br[counter] << "  ";
    }
    cout << "\n";
    cout<<"Array of selection\n";
    for (int counter = 0; counter < size_array; counter++)
    {
        cout << setw(2) << sorted_array1[counter] << "  ";
    }
    printf("The time: %f seconds of Radix\n", seconds);
    printf("The time: %f seconds of Selection\n", seconds1);
    delete [] sorted_array;
    delete [] sorted_array1;
    system("pause");
    return 0;
}
void radix(int *ar, int *br, int *cr, int sizeC, int sizeAB)
{
    int i,k,n;
    k = sizeC;
    n = sizeAB;
    for (i = 0; i <= k; i++)
        cr[i]=0;
    for (i = 0; i < n; i++)
        cr[ar[i]]+=1;
    for (i = 1; i < k+1; i++)
        cr[i]+=cr[i-1];
    for (i = n-1; i >= 0; i--)
      {
         br[cr[ar[i]]-1]=ar[i];
         cr[ar[i]]-=1;
      }
  }
void Selection(int* arrayPtr, int length_array) // selection
{
    for (int repeat_counter = 0; repeat_counter < length_array; repeat_counter++)
    {
        int temp = arrayPtr[0];
        for (int element_counter = repeat_counter + 1; element_counter < length_array; element_counter++)
        {
            if (arrayPtr[repeat_counter] > arrayPtr[element_counter])
            {
                temp = arrayPtr[repeat_counter];
                arrayPtr[repeat_counter] = arrayPtr[element_counter];
                arrayPtr[element_counter] = temp;
            }
        }
    }
}
