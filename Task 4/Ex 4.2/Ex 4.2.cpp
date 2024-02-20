#include <iostream>
#include <windows.h>
using namespace std;

bool Input(int&, int&);

int main()
{
    SetConsoleOutputCP(1251);
    int a, b;
    if (Input(a, b) == false) // if(!Input(a,b)) 
    {
        cerr << "error";
        return 1;
    }
    int s = a + b;
    cout << s;
    return 0;
}

bool Input(int &a, int &b)
{
    string strA, strB;
    bool flag = true;
    cout << "Введите число a = " << endl;
    cin >> strA;
    cout << "Введите число b = " << endl;
    cin >> strB;
    for (int i = 0; i < strA.length(); i++)
    {
        if (!isdigit(strA[i]))
            if (strA[i] == '-' && i == 0)
                continue;
            else
            {
                flag = false;
                break;
            }
    }
    for (int i = 0; i < strB.length(); i++)
    {
        if (!isdigit(strB[i]))
            if (strA[i] == '-' && i == 0)
                continue;
            else
            {
                flag = false;
                break;
            }
    }
    if (flag == true)
    {
        a = atoi(strA.c_str());
        b = atoi(strB.c_str());
    }
    return flag;
}
