#include <iostream>
#include <windows.h>
#include <math.h>
using namespace std;

double cubeRoot(double a)
{
    double x, oldX = 1.0;
    do
    {
        x = (1.0 / 3.0) * (a / (oldX * oldX) + 2.0 * oldX);
        oldX = x;
    } while (x * x * x != a);
    return x;
}

int main()
{
    SetConsoleOutputCP(1251);
    cout << "Введите число: ";
    double a, result1, result2;
    cin >> a;
    result1 = pow(a, 1.0 / 3);
    result2 = cubeRoot(a);
    cout << "Расчет по формуле: " << result2 << endl;
    cout << "Расчет по станд. функции: " << result1 << endl;
}
