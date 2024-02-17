#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    system("chcp 1251");
    double p, pp, square, a; // периметр, полупериметр, площадь соответственно
    cout << "Введите периметр равностороннего треугольника: ";
    cin >> p;
    pp = p / 2; //вычисление полупериметра
    a = p / 3; //вычисление стороны
    square = sqrt(pp * (pp - a) * (pp - a) * (pp - a));
    cout.precision(3);
    cout.setf(std::ios::fixed);
    cout << "\nПлощадь треугольника равна: " << square << endl;
    return 0;
}

