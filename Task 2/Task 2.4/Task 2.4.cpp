
#include <iostream>
using namespace std;

int main()
{
    system("chcp 1251");
    int k, m, s = 0;
    cout << "Введите диапазон чисел (через пробел) :";
    cin >> k >> m;
    for (int i = 1; i <= 100; i++)
    {
        if ((i > k) && (i < m))
            continue;
        s += i;
    }
    cout << "Сумма чисел в диапазоне от 0 до "<< k << " и от " << m << " до 100 равна " << s;
}
