#include <iostream>
using namespace std;

int main()
{
    system("chcp 1251");
    double x, y;
    cout << "Введите координаты точки: ";
    cin >> x >> y;
    if (x * x + y * y < 9 && y > 0)
        cout << "внутри";
    else if (x * x + y * y > 9 || y < 0)
        cout << "снаружи";
    else 
        cout << "на границе";
    return 0;
}

