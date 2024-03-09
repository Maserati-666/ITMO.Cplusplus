#include <string> 
#include <windows.h> 
#include <iostream>
using namespace std;

class Time
{
    friend Time operator+ (double hours, Time t2);
public:
    Time() // Конструктор Time по умолчанию
    {
        hours = 0;
        minutes = 0;
        seconds = 0;
    }

    // Конструктор Time
    Time(int hours, int minutes, int seconds)
    {
            set_seconds(seconds);
            set_minutes(minutes);
            set_hours(hours);
    }
    // Конструктор Time
    Time (double hrs)
    {
        set_seconds(int(hrs * 3600));
        set_minutes(0);
        set_hours(0);
    }

    // Установка часов 
    void set_hours(int time_hours)
    {
        hours += time_hours;
    }

    // Получение часов 
    int get_hours() const
    {
        return hours;
    }

    // Установка минут
    void set_minutes(int time_minutes)
    {
        hours = 0;
        while (minutes + time_minutes > 59)
        {
            time_minutes -= 60;
            hours++;
        }
        minutes += time_minutes;
    }

    // Получение минут 
    int get_minutes() const
    {
        return minutes;
    }

    // Установка секунд
    void set_seconds(int time_seconds)
    {
        minutes = 0;
        while (time_seconds > 59)
        {
            time_seconds -= 60;
            minutes++;
        }
        seconds = time_seconds;
    }

    // Получение секунд
    int get_seconds() const
    {
        return seconds;
    }

    // Вывод на экран
    void ShowTime() const
    {
        string str_h = "";
        string str_m = "";
        string str_s = "";
        if (hours < 10 && hours > -1)
            str_h = "0" + to_string(hours);
        else if (hours < 0 && hours > -10)
            str_h = "-0" + to_string(abs(hours));
        else
            str_h = to_string(hours);
        if (minutes < 10)
            str_m = "0" + to_string(minutes);
        else
            str_m = to_string(minutes);
        if (seconds < 10)
            str_s = "0" + to_string(seconds);
        else
            str_s = to_string(seconds);
        cout << str_h << ":" << str_m << ":" << str_s << endl;
    }

    // Пересчет в  секунды
    int calc_seconds() const
    {
        return this->hours * 3600 + this->minutes * 60 + this->seconds;
    }

    // Переопределение оператора +
    Time operator+ (const Time& t2) const
    {
        int s = seconds + t2.seconds;
        int m = minutes + t2.minutes;
        int h = hours + t2.hours;
        return Time(h, m, s);
    }

    // Переопределение оператора +
    Time operator+ (double hrs)
    {
        Time time2(hrs);
        Time newTime = *this + time2;
        /*Time newTime(hours + time2.get_hours(), minutes + time2.get_minutes(), seconds + time2.get_seconds());*/
        return newTime;
    }

    // Переопределение оператора -
    Time operator- (const Time& t2) const
    {
        int s = 0;  int m = 0; int h = 0;
        bool flag = true;
        int sec1 = 0; int sec2 = 0; int min1 = 0; int min2 = 0;
        int hours1 = 0; int hours2 = 0;
        if (hours - t2.hours < 0 || (hours - t2.hours == 0 && minutes - t2.minutes < 0) ||
           (hours - t2.hours == 0 && minutes - t2.minutes == 0 && seconds - t2.seconds < 0))
        {
            hours1 = t2.hours;
            hours2 = hours;
            min1 = t2.minutes;
            min2 = minutes;
            sec1 = t2.seconds;
            sec2 = seconds;
            flag = false;
        }
        else
        {
            hours1 = hours;
            hours2 = t2.hours;
            min1 = minutes;
            min2 = t2.minutes;
            sec1 = seconds;
            sec2 = t2.seconds;
        }
        s = sec1 - sec2;
        m = min1 - min2;
        if (flag == false)
            h = -(hours1 - hours2);
        else
            h = hours1 - hours2;
        return Time(h, m, s);
    }

    // Переопределение оператора <
    bool operator < (const Time& t2)
    {
        return this->calc_seconds() < t2.calc_seconds();
    }

    // Переопределение оператора >
    bool operator > (const Time& t2)
    {
        return this->calc_seconds() > t2.calc_seconds();
    }

private:
    // Часы 
    int hours;
    // Минуты 
    int minutes;
    // секунды 
    int seconds;
};

// Дружественная функция переопределения оператора + 
Time operator+ (double hrs, Time time2)
{
    Time time3;
    Time time1(hrs);
    return time3 = time1 + time2;
}

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    Time time1(2, 45, 50);
    Time time2(2, 46, 51);
    time1.ShowTime();
    time2.ShowTime();
    Time time3, time4, time5, time6;
    time3 = time1 + time2;
    time3.ShowTime();
    time4 = time1 - time2;
    time4.ShowTime();
    time5 = Time (2, 45, 50) + 2.5;
    time5.ShowTime();
    time5 = 2.0 + Time(2, 45, 50);
    time5.ShowTime();
    if (time5 > time1)
        time5.ShowTime();
}
