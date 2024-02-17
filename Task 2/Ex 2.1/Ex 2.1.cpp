#include<iostream>

using namespace std;

int main()
{
    system("chcp 1251");
    int userNumber; // число введенное пользователем
    int m, n; // вспомогательные переменные для нахождения НОД
    int count = 0; //индекс простого числа
    int chislo; // значение простого числа
    bool flag = true; // проверка является ли число простым
    cout << "Введите число = "; cin >> userNumber;
    for (int i = 2; i <= userNumber; i++)
    {
        for (int j = 2; j < i; j++)
        {
            m = i;
            n = j;
            while (n != m)
            {
                if (n > m)
                    n -= m;
                else
                    m -= n;
            }
            if (n != 1)
            {
                flag = false;
                break;
            }
            else
            {
                flag = true;
            }
        }
        if (flag == true)
        {
            count++;
            chislo = i;
        }
    }
    flag = true;
    for (int i = 2; i <= count; i++)
    {
        for (int j = 2; j < i; j++)
        {
            m = i;
            n = j;
            while (n != m)
            {
                if (n > m)
                    n -= m;
                else
                    m -= n;
            }
            if (n != 1)
            {
                flag = false;
                break;
            }
            else
            {
                flag = true;
            }
        }
    }
    if (userNumber == chislo && flag == true)
        cout << "Число " << userNumber << " является суперпростым числом " << endl;
    else
        cout << "Число " << userNumber << " не является суперпростым числом " << endl;
    return 0;
}
