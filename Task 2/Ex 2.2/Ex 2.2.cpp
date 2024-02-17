#include <iostream>
using namespace std;

int main()
{
    system("chcp 1251");
    short num, oldNum = 10, summa = 0, count = 0;
    unsigned long long stroka; // Ввод пользователя
    int snils; // номер СНИЛС
    int controlChislo; // Контрольное число
    bool flag = true; 
    cout << "Введите СНИЛС: ";
    cin >> stroka;
    snils = stroka / 100;
    controlChislo = stroka % 100;
    for (int i = 1; i < 10; i++)
    {
        num = snils % 10;
        if (oldNum == num)
        {
            count += 1;
            if (count == 2)
            {
                flag = false;
                break;
            }
        }
        else
            count = 0;
        snils = snils / 10;
        summa += num * i;
        oldNum = num;
    }
    summa = summa % 101;
    if (summa == 100 || summa == 101)
        summa = 0;
    if (summa == controlChislo)
        flag *= true;
    else
        flag *= false;
    cout << boolalpha << flag << endl;
}