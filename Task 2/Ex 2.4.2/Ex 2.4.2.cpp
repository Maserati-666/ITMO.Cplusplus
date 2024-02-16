#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    system("chcp 1251");
    double x, y, x0, y0, pomeha;
    string rang;
    unsigned int shot = 0, point = 5, summa = 0;
    cout << "Введите минимальное количество очков: "; cin >> point;
    do
    {
        cout << "Введите координаты выстрела № " << shot + 1 << endl;
        cin >> x >> y;
        x0 = -2 + (double)rand() / RAND_MAX * 4;
        y0 = -2 + (double)rand() / RAND_MAX * 4;
        cout << x0 << " - " << y0 << endl;
        pomeha = -1 + (double)rand() / RAND_MAX * 2;
        cout << pomeha << endl;
        x = x + pomeha;
        y = y + pomeha;
        if ((x - x0) * (x - x0) + (y - y0) * (y - y0) <= 1)
            summa += 10;
        else  if ((x - x0) * (x - x0) + (y - y0) * (y - y0) <= 4)
            summa += 5;
        else  if ((x - x0) * (x - x0) + (y - y0) * (y - y0) <= 9)
            summa += 1;
        shot++;
    } while (summa <= point);
    if (summa / shot > 7)
        rang = " Ваш ранг : Снайпер!";
    else if (summa / shot > 3)
        rang = " Ваш ранг : Стрелок!";
    else
        rang = " Ваш ранг : Новичок!";
    cout << " Количество выстрелов: " << shot << rang << endl;
    return 0;
}