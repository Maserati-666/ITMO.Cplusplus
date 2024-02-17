#include <iostream>
using namespace std;

int gcd(int m, int n)
{
    if (n == 0) return m;
    return gcd(n, m % n);
}

int main()
{
    system("chcp 1251");
    int n, m, value;
    cout << "Введите два числа: ";
    cin >> n >> m;
    value = gcd(m, n);
    cout << "НОД: " << value;
}