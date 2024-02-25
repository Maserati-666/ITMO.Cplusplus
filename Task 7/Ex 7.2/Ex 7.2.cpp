#include <iostream> 
#include <windows.h> 

using namespace std;

struct QuadEquation
{
    double root1;
    double root2;
};

QuadEquation SolvEquation(bool&);

int main()
{
    SetConsoleOutputCP(1251);
    bool flag = true;
    QuadEquation equat = SolvEquation(flag);
    if (flag != true)
    {
        cout << "Корней нет!";
        return -1;
    }
    else
    {
        cout << "Корень №1 уравнения :" << equat.root1 << endl;
        cout << "Корень №2 уравнения :" << equat.root2 << endl;
        return 0;
    }
    return 0;
}

QuadEquation SolvEquation(bool& flag)
{
    QuadEquation equat;
    double a, b, c;
    double d;
    cout << "Введите коэффициенты квадратного уравнения (через пробел): ";
    cin >> a >> b >> c;
    d = b * b - 4 * a * c;
    if (d > 0)
    {
        equat.root1 = (-b - sqrt(d)) / (2 * a);
        equat.root2 = (-b + sqrt(d)) / (2 * a);
    }
    else if (d == 0)
    {
        equat.root1 = -b / (2 * a);
        equat.root2 = equat.root1;
    }
    else
        flag = false;
    return equat;
}