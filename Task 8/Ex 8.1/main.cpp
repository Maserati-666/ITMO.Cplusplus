#include <iostream> 
#include <windows.h> 
#include "Time.h" 
using namespace std;

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    const Time* time1 = new Time(2, 70, 40);
    const Time* time2 = new Time(-5, 20, 30);
    time1->ShowTime();
    time2->ShowTime();
    Time time3;
    time3.AddTime(time1, time2);
    delete time1;
    delete time2;
    time3.ShowTime();


}