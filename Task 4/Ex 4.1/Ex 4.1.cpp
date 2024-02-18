
#include <iostream>
#include <windows.h>
using namespace std;

int Myroot(double, double, double, double&, double&);

int main()
{
    SetConsoleOutputCP(1251);
    double a, b, c, x1, x2;
    int d;
    cout << "Введите коэффициенты квадратного уравнения (через пробел): ";
    cin >> a >> b >> c;
    d = Myroot(a, b, c, x1, x2);
    switch (d)
    {
    case 1:
        cout << "Корни уравнения x1 = " << x1 << ", x2 = " << x2;
        break;
    case 0:
        cout << "Корень уравнения один x1 = x2 =" << x1;
        break;
    case -1:
        cout << "Корней уравнения нет";
        break;
    }

}

int Myroot(double a, double b, double c, double &x1, double &x2)
{
    double d;
    short flag;
    d = b * b - 4 * a * c;
    if (d > 0)
    {
        x1 = (-b - sqrt(d)) / (2 * a);
        x2 = (-b + sqrt(d)) / (2 * a);
        return flag = 1;
    }
    else if (d == 0)
    {
        x1 = -b / (2 * a);
        return flag = 0;
    }
    else
        return flag = -1;
}