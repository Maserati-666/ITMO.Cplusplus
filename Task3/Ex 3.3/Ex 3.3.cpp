#include <iostream>
#include <windows.h>
using namespace std;

double squareTriangle(double a)
{
    double pp, square; // полупериметр, площадь соответственно
    pp = 3 * a / 2; //вычисление полупериметра
    square = sqrt(pp * (pp - a) * (pp - a) * (pp - a));
    return square;
}

double squareTriangle(double a, double b, double c)
{
    double pp, square; // полупериметр, площадь соответственно
    pp = (a + b + c) / 2; //вычисление полупериметра
    square = sqrt(pp * (pp - a) * (pp - b) * (pp - c));
    return square;
}


int main()
{
    SetConsoleOutputCP(1251);
    bool vid;
    short cnt = 1;
    double a, b, c, square;
    cout << "Является ли треугольник равносторонним? (1 - да, 0 - нет): ";
    cin >> vid;
    if (vid == true)
    {
        cout << "Введите длину стороны треугольника: ";
        cin >> a;
        square = squareTriangle(a);
        cout << "Площадь треугольника: " << square;
    }
    else
    {
        cout << "Введите длину стороны № 1:" << endl;
        cin >> a;
        cout << "Введите длину стороны № 2:" << endl;
        cin >> b;
        cout << "Введите длину стороны № 3:" << endl;
        cin >> c;
        square = squareTriangle(a, b, c);
        cout << "Площадь треугольника: " << square;
    }
    return 0;
}
