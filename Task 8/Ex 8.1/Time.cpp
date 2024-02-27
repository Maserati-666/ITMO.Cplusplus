#include <string>
#include <fstream>
#include "Time.h" 
#include <iostream>

using namespace std;

Time::Time() // Конструктор Time по умолчанию
{
    Time::hours = 0;
    Time::minutes = 0;
    Time::seconds = 0;
}

// Конструктор Time
Time::Time(int hours, int minutes, int seconds)
{
    Time::set_seconds(seconds);
    Time::set_minutes(minutes);
    Time::set_hours(hours);
}


// Установка часов 
void Time::set_hours(int time_hours)
{
    Time::hours += time_hours;
}

// Получение часов 
int Time::get_hours() const
{
    return Time::hours;
}

// Установка минут
void Time::set_minutes(int time_minutes)
{
    Time::hours = 0;
    while (Time::minutes + time_minutes > 59)
    {
        time_minutes -= 60;
        Time::hours++;
    }
    Time::minutes += time_minutes;
}

// Получение минут 
int Time::get_minutes() const
{
    return Time::minutes;
}

// Установка секунд
void Time::set_seconds(int time_seconds)
{
    Time::minutes = 0;
    while (time_seconds > 59)
    {
        time_seconds -= 60;
        Time::minutes++;
    }
    Time::seconds = time_seconds;
}

// Получение секунд
int Time::get_seconds() const
{
    return Time::seconds;
}

// Вывод на экран
void Time::ShowTime() const
{
    string str_h = "";
    string str_m = "";
    string str_s = "";
    if (Time::hours < 10 && Time::hours > -1)
        str_h = "0" + to_string(Time::hours);
    else if (Time::hours < 0 && Time::hours > -10)
        str_h = "-0" + to_string(abs(Time::hours));
    else
        str_h = to_string(Time::hours);
    if (Time::minutes < 10)
        str_m = "0" + to_string(Time::minutes);
    else
        str_m = to_string(Time::minutes);
    if (Time::seconds < 10)
        str_s = "0" + to_string(Time::seconds);
    else
        str_s = to_string(Time::seconds);
    cout << str_h << ":" << str_m  << ":" << str_s << endl;
}

// Метод сложения двух Time
void Time::AddTime(const Time *time1, const Time *time2)
{
    Time::set_seconds(time1->get_seconds() + time2->get_seconds());
    Time::set_minutes(time1->get_minutes() + time2->get_minutes());
    Time::set_hours(time1->get_hours() + time2->get_hours());
}
