#include <iostream> 
#include <windows.h> 

using namespace std;

struct Distance
{
    int feet;
    double inches;
};

Distance InputDist();
void ShowDist(Distance);
Distance SummaMasDist(Distance[], int);

int main()
{
    SetConsoleOutputCP(1251);
    int n;
    Distance d;
    cout << "¬ведите размер массива рассто€ний ";
    cin >> n;
    Distance* masDist = new Distance[n];
    for (int i = 0; i < n; i++)
    {
        masDist[i] = InputDist();
    }
    for (int i = 0; i < n; i++)
    {
        ShowDist(masDist[i]);
    }
    d = SummaMasDist(masDist, n);
    delete[] masDist;
    ShowDist(d);
    return 0;
}

//Distance AddDist(const Distance& d1, const Distance& d2)
//{
//    Distance d;
//    d.feet = d1.feet + d2.feet;
//    d.inches = d1.inches + d2.inches;
//    if (d.inches >= 12.0)
//    {
//        d.inches -= 12.0;
//        d.feet++;
//    }
//    return d;
//}

Distance InputDist()
{
    Distance d;
    cout << "\n¬ведите число футов: ";
    cin >> d.feet;
    cout << "¬ведите число дюймов: ";
    cin >> d.inches;
    return d;
}

void ShowDist(Distance d)
{
    cout << d.feet << "\'-" << d.inches << "\"\n";
}

Distance SummaMasDist(Distance masDist[], int n)
{
    Distance d;
    d.feet = 0;
    d.inches = 0;
    for (int i = 0; i < n; i++)
    {
        d.feet += masDist[i].feet;
        d.inches += masDist[i].inches;
        while (d.inches >= 12.0)
        {
            d.inches -= 12.0;
            d.feet++;
        }
    }
    return d;
}
