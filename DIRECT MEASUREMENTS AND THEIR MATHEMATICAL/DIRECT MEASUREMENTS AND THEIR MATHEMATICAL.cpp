#include <iostream>
#include <algorithm>
#include "Header.h"

using std::cout;
using std::cin;
using std::endl;
using std::sort;


void FillArray(double array[], int arraySize)//Вводим числа в массив
{
    cout << "введите ваши данные" << endl;
    for (int i = 0; i < arraySize; i++)
    {
        cout << i << "\t";
        cin >> array[i];
        cout << endl;
    }
    PrintArray(arraySize, array);
    CheckArray(array, arraySize);
    sortingArray(array, arraySize);
    meanArray(array, arraySize);
}
void PrintArray(int count, double array[])//Выводим введенный массив
{
    for (int i = 0; i < count; i++)
    {
        cout << "[" << i << "] = " << array[i] << endl;
    }
    
}
void CheckArray(double array[],int arraySize)//Делаем проверку введенных данных
{
    char Y;
    char exit;
    int number;
    double trueMeaning;
    while (true)
    {
        cout << "Если вы ввели все верно введите Y, если нет то введите N" << endl;
        cin >> Y;
        switch (Y)
        {
        case 'Y':break;
        default:
            while (true)
            {
                cout << "Введите индекс не правильно введенного числа" << endl;
                cin >> number;
                if (number <= arraySize)
                {
                    cout << "Введите правильное значение ";
                    cin >> trueMeaning;
                    array[number] = trueMeaning;
                    break;
                }
                else
                {
                    cout << "Вы ввели число выходящее за предел массива" << endl;
                }
            }

            break;
        }
        cout << "Если все ваши данные были введены верно, то введите Y" << endl;
        cin >> exit;
        if (exit=='Y')
        {
            break;
        }
    }
    cout << "Испрвленный массив " << endl;
    PrintArray(arraySize, array);
    
}
void sortingArray(double array[], int arraySize)//Сортируем массив по возрастанию
{
    sort(array, array + arraySize);
    cout << "Отсортированный по возрастанию массив" << endl;
    for (int i = 0; i < arraySize; i++)
    {
        cout << "[" << i << "] = " << array[i] << endl;
    }
}
void meanArray(double array[], int arraySize)
{
    double sum = 0.0; // сумма элементов массива
    double mean;
    for (int i = 0; i < arraySize; i++)
    {
        sum += array[i];
    }
    mean= sum / arraySize;
    cout << mean;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    
    int count = 0;
    cout << "Введите количество " << endl;
    cin >> count;
    double* array = new double[count];
    FillArray(array, count);
    
    delete[] array;
    return 0;
}

