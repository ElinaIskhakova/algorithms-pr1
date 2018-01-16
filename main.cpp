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
    cout << "Введите размер массива: ";
    int size_array; // длина массива
    cin >> size_array;

    int *sorted_array = new int [size_array]; // одномерный динамический массив
    for (int counter = 0; counter < size_array; counter++)
    {
        sorted_array[counter] = rand() % 100; // заполняем массив случайными числами
        cout << setw(2) << sorted_array[counter] << "  "; // вывод массива на экран
    }
    cout << "\n\n";
    clock_t start=clock();
    Selection(sorted_array, size_array);
    clock_t end=clock();
double seconds=(double)(end-start)/CLOCKS_PER_SEC;
    for (int counter = 0; counter < size_array; counter++)
    {
        cout << setw(2) << sorted_array[counter] << "  ";
    }
    cout << "\n";
    printf("The time: %f seconds\n", seconds);
    delete [] sorted_array; // высвобождаем память
    system("pause");
    return 0;
}
void Selection(int* arrayPtr, int length_array) // сортировка выбором
{
    for (int repeat_counter = 0; repeat_counter < length_array; repeat_counter++)
    {
        int temp = arrayPtr[0]; // временная переменная для хранения значения перестановки
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
