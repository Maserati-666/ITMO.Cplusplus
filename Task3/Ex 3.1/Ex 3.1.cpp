#include <iostream>
#include <string>
using namespace std;

long long checkInn(string str)
{
    string result;
    result = str;
    int cnt = 0;
    bool flag = true;
    unsigned long long stroka; // Ввод пользователя
    int snils; // номер СНИЛС
    int controlChislo; // Контрольное число
    for (int i = 0; i < str.length(); i++) 
    {
        if (!isdigit(str[i]))
            if (str[i] == ' ' || str[i] == '-')
            {
                result.erase(i - cnt, 1);
                cnt++;
            }
            else
            {
                flag = false;
                break;
            }
    }
    if (flag == true && result.length() == 11)
    {
        stroka = atoll(result.c_str());
        short num, oldNum = 10, summa = 0, count = 0;
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
        return flag;
    }
    else
        return false;
}

int main()
{
    system("chcp 1251");
    bool value;
    string str;
    cout << "Введите СНИЛС: ";
    getline(cin, str);
    value = checkInn(str);
    cout << boolalpha << value << endl;
}

