#include <iostream>
using namespace std;

int addNumders(int n)
{
    if (n == 1) return 1; // выход из рекурсии 
    else return (n + addNumders(n - 1));
}

int addNumders(int n, int m)
{
    if (m == n) return n; // выход из рекурсии 
    else return (m + addNumders(n, m - 1));
}

int main()
{
    system("chcp 1251");
    int n, m, value;
    cout << "Введите число: ";
    cin >> n >> m;
    value = addNumders(n, m);
    cout << "Результат: " << value;
}
