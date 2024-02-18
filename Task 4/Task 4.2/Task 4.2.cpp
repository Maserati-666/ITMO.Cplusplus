#include <iostream>
#include <windows.h>
using namespace std;

void swap(int*, int*);
void swap(int&, int&);

int main()
{
    SetConsoleOutputCP(1251);
    int x = 5, y = 10;
    cout << " x = " << x << " y = " << y << endl;
    swap(&x, &y);
    cout << " x = " << x << " y = " << y << endl;
    swap(x, y);
    cout << " x = " << x << " y = " << y << endl;
}

void swap(int* x, int* y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
void swap(int& x, int& y)
{
    int temp;
    temp = x;
    x = y;
    y = temp;
}