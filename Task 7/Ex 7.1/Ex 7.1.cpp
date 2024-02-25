#include <iostream> 
#include <windows.h> 
#include <string>

using namespace std;

struct Time
{
    int hours;
    int minutes;
    int seconds;

    int ShowTime()
    {
        return hours * 3600 + minutes * 60 + seconds;
    }

    Time AddTime(Time t1)
    {
        Time t;
        t.hours = 0;
        t.minutes = 0;
        t.seconds = 0;
        if (seconds + t1.seconds > 59)
        {
            t.seconds = seconds + t1.seconds - 60;
            t.minutes++;
        }
        else
            t.seconds = seconds + t1.seconds;
        if (t.minutes + minutes + t1.minutes > 59)
        {
            t.minutes = t.minutes + minutes + t1.minutes - 60;
            t.hours++;
        }
        else
            t.minutes += minutes + t1.minutes;
        t.hours += hours + t1.hours;
        return t;
    }

    Time SubTime(Time t1)
    {
        Time t;
        t.hours = 0;
        t.minutes = 0;
        t.seconds = 0;
        if (seconds - t1.seconds < 0)
        {
            t.seconds = 60 + seconds - t1.seconds;
            t.minutes--;
        }
        else
            t.seconds = seconds - t1.seconds;
        if (t.minutes + minutes - t1.minutes < 0)
        {
            t.minutes = 60 + t.minutes + minutes - t1.minutes;
            t.hours--;
        }
        else
            t.minutes += minutes - t1.minutes;
        t.hours += hours - t1.hours;
        return t;
    }
};

Time InputTime(bool&);

int main()
{
    SetConsoleOutputCP(1251);
    bool flag = true;
    Time t1 = InputTime(flag);
    Time t2 = InputTime(flag);
    if (flag != true)
    {
        cout << "ERROR!";
        return -1;
    }
    else
    {
        int output = t1.ShowTime();
        cout << "Время в секундах: " << output << endl;
        output = t2.ShowTime();
        cout << "Время в секундах: " << output << endl;
        Time t3 = t1.AddTime(t2);
        output = t3.ShowTime();
        cout << "Время в секундах: " << output << endl;
        Time t4 = t1.SubTime(t2);
        output = t4.ShowTime();
        cout << "Время в секундах: " << output << endl;
        return 0;
    }
}

Time InputTime(bool &flag) 
{
    Time t;
    cout << "Введите время: ";
    cin >> t.hours;
    cin >> t.minutes;
    cin >> t.seconds;
    if (t.hours < 0)
        flag = false;
    else if (t.minutes > 59 || t.minutes < 0 || t.seconds > 59 || t.seconds < 0)
        flag = false;
    return t;
}
