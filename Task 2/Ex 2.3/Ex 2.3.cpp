#include <iostream>
using namespace std;

int main()
{
    system("chcp 1251");
    double razmen;
    string str;
    int rub; short kop;
    short countRub10 = 0, countRub5 = 0, countRub2 = 0, countRub1 = 0, n;
    short countKop50 = 0, countKop10 = 0, countKop5 = 0, countKop1 = 0;
    cout << "Введите сумму для размена (12 руб 25 коп): ";
    cin >> rub;
    cin >> str;
    cin >> kop;
    cout << rub << " руб. "<< kop << " коп. " << endl;
    while (rub > 0)
    {
        if (rub >= 10)
        {
            n = 10;
            countRub10++;
        }
        else if (rub >= 5)
        {
            n = 5;
            countRub5++;
        }
        else if (rub >= 2)
        {
            n = 2;
            countRub2++;
        }
        else 
        {
            n = 1;
            countRub1++;
        }
        rub -= n;
    }
    while (kop > 0)
    {
        if (kop >= 50)
        {
            n = 50;
            countKop50++;
        }
        else if (kop >= 10)
        {
            n = 10;
            countKop10++;
        }
        else if (kop >= 5)
        {
            n = 5;
            countKop5++;
        }
        else
        {
            n = 1;
            countKop1++;
        }
        kop -= n;
    }
    if (countRub10 > 0)
        cout << " 10 руб - " << countRub10 << " шт." << endl;
    if (countRub5 > 0)
        cout << " 5 руб - " << countRub5 << " шт." << endl;
    if (countRub2 > 0)
        cout << " 2 руб - " << countRub2 << " шт." << endl;
    if (countRub1 > 0)
        cout << " 1 руб - " << countRub1 << " шт." << endl;
    if (countKop50 > 0)
        cout << " 50 коп - " << countKop50 << " шт." << endl;
    if (countKop10 > 0)
        cout << " 10 коп - " << countKop10 << " шт." << endl;
    if (countKop5 > 0)
        cout << " 5 коп - " << countKop5 << " шт." << endl;
    if (countKop1 > 0)
        cout << " 1 коп - " << countKop1 << " шт." << endl;
    return 0;
}