#include <iostream>
#include <windows.h>
using namespace std;

int recursion(int n)
{
    if (n == 1) return 5; // выход из рекурсии 
    else return (5 * n + recursion(n - 1));
}

int main()
{
    SetConsoleOutputCP(1251);
    int n, value;
    cout << "Введите число n: ";
    cin >> n;
    value = recursion(n);
    cout << "Результат: " << value;
}
