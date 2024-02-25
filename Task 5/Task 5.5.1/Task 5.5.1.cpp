#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
    SetConsoleOutputCP(1251);
    srand(time(NULL));
    int a, b, c;
    int k = 0;

    const int n = 10;
    int mas[n];
    for (int i = 0; i < n; i++)
    {
        cin >> c;
        mas[i] = c;
    }
    cout << "\nAll: ";
    for (int i = 0; i < n; i++)
    {
        cout << mas[i] << ends;
    }
}