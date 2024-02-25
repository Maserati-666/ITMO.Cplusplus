#include <iostream> 
#include <windows.h> 
#include <string> 
#include <tuple> 
#include <vector> 

using namespace std;
using Tuple = tuple<double, double, short>;

Tuple SolvEquation();
void printTupleOfThree(Tuple);

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    Tuple quadEqua;
    quadEqua = SolvEquation();
    printTupleOfThree(quadEqua);
    return 0;
}

void printTupleOfThree(Tuple t)
{
    cout << "("
        << std::get<0>(t) << ", "
        << std::get<1>(t) << ", "
        << std::get<2>(t) << ")" << endl;
}

Tuple SolvEquation()
{
    Tuple quadEqua;
    double a, b, c;
    double d;
    cout << "Введите коэффициенты квадратного уравнения (через пробел): ";
    cin >> a >> b >> c;
    d = b * b - 4 * a * c;
    if (d > 0)
    {
        return make_tuple((-b - sqrt(d)) / (2 * a), (-b + sqrt(d)) / (2 * a), 1);
    }
    else if (d == 0)
    {
        return make_tuple(-b / (2 * a), 0, 0);
    }
    else
        return make_tuple(0, 0, -1);
}