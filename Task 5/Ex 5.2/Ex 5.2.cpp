#include <iostream>
#include <windows.h>
#include <vector>

using namespace std;

int* max_vect(int, int [], int[]);

int main()
{
    SetConsoleOutputCP(1251);
    int a[] = { 1,2,3,4,5,6,7,2 };
    int b[] = { 7,6,5,4,3,2,1,3 };

    int kc = sizeof(a) / sizeof(a[0]); //Количество элементов массива 
    int* c;                         //Указатель на результирующий массив 
    c = max_vect(kc, a, b); //вызов функции для создания массива 

    for (int i = 0; i < kc; i++) //Вывод результата. 
        cout << c[i] << " ";
    cout << endl;
    delete[]c; //Возврат памяти. 
    return 0;
}

int* max_vect(int kc, int a[], int b[])
{
    int* arrayMax = new int[kc];
    for (int i = 0; i < kc; i++)
    {
        if (a[i] >= b[i])
            arrayMax[i] = a[i];
        else
            arrayMax[i] = b[i];
    }
    return arrayMax;
}

