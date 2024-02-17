#include <iostream>
using namespace std;

long double firBinSearch(double a, int n)
{
    double L = 0;
    double R = a;
    while (R - L > 1e-10)
    {
        double M = (L + R) / 2;
        if (pow(M, n) < a)
        {
            L = M;
        }
        else
        {
            R = M;
        }
    }
    return R;
}

int main()
{
    system("chcp 1251");
    double a;
    int n;
    long double value;
    cout << "Введите число и степень его корня: ";
    cin >> a >> n;
    value = firBinSearch(a, n);
    cout.setf(std::ios::fixed);
    cout.precision(6);
    cout << value << endl;
}

