#include <iostream> 
#include <windows.h> 

using namespace std;

struct Distance
{
    int feet;
    double inches;

    void ShowDist()
    {
        cout << feet << "\'-" << inches << "\"\n";
    }
};

Distance AddDist(Distance, Distance);
Distance InputDist();

int main()
{
    SetConsoleOutputCP(1251);
    Distance d1 = InputDist();
    Distance d2 = { 1, 6.25 };
    Distance d3 = AddDist(d1, d2);
    d1.ShowDist();
    d2.ShowDist();
    d3.ShowDist();
    return 0;
}

Distance AddDist(Distance d1, Distance d2)
{
    Distance d;
    d.feet = d1.feet + d2.feet;
    d.inches = d1.inches + d2.inches;
    if (d.inches >= 12.0)
    {
        d.inches -= 12.0;
        d.feet++;
    }
    return d;
}

Distance InputDist()
{
    Distance d;
    cout << "\nВведите число футов: ";
    cin >> d.feet;
    cout << "Введите число дюймов: ";
    cin >> d.inches;
    return d;
}
