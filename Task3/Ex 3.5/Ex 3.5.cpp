#include <iostream>
#include <windows.h>
using namespace std;

int recursion(int n)
{
    if (n == 0) return 0;
    else return  n % 2 + 10 * (recursion(n / 2));
}

int main()
{
    SetConsoleOutputCP(1251);
    int n, value;
    string str = "";
    cout << "Введите число n: ";
    cin >> n;
    value = recursion(n);
    cout << "Результат: " << value;
}