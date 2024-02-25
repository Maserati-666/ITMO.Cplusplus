#include <iostream>
#include <windows.h>
#include <array>
using namespace std;

void searhTrans(int[], int, int);

int main()
{
    SetConsoleOutputCP(1251);
    int mas[] = { 1, 2, 3, 4, 7, 5, 9, 5, 6, 7, 8 };
    int c, value = 4;
    int n = sizeof(mas) / sizeof(mas[0]);
    cout << "Изначальный массив" << endl;
    for (int i : mas)
        cout << i << '\t';
    for (int i = 0; i < 5; i++) // проверка работы алгоритма
    {
        searhTrans(mas, value, n);
        cout << "\nКонечный массив" << endl;
        for (int i : mas)
            cout << i << '\t';
    }
}

void searhTrans(int mas[], int value, int n) 
{
    int index;
    for (int i = 0; i < n; i++)
    {
        if (mas[i] == value)
        {
            index = i;
            if (index == 0)
                break;
            else
                swap(mas[i], mas[i - 1]);
        }
    }
}