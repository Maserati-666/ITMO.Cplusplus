#include <string> 
#include <windows.h> 
#include <iostream>
using namespace std;

class Time
{
public:
    class TimeError
    {
    public:
        TimeError(int minutes, int seconds)
        {
            if (minutes < 0 && seconds < 0)
                message = "Неверно введены минуты и секунды";
            else if (seconds < 0)
                message = "Неверно введены секунды";
            else if (minutes < 0)
                message = "Неверно введены минуты";
        }
        void printMessage() const { cout << message << endl; }
    private:
        string message;
    };
    Time() // Конструктор Time по умолчанию
    {
        hours = 0;
        minutes = 0;
        seconds = 0;
    }

    // Конструктор Time
    Time(int hours, int minutes, int seconds)
    {
        if (minutes < 0 || seconds < 0)
            throw TimeError(minutes, seconds);
        else
        {
            set_seconds(seconds);
            set_minutes(minutes);
            set_hours(hours);
        }
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

    // Метод сложения двух Time
    void AddTime(const Time* time1, const Time* time2)
    {
        set_seconds(time1->get_seconds() + time2->get_seconds());
        set_minutes(time1->get_minutes() + time2->get_minutes());
        set_hours(time1->get_hours() + time2->get_hours());
    }

private:
    // Часы 
    int hours;
    // Минуты 
    int minutes;
    // секунды 
    int seconds;
};

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    try
    {
        const Time* time1 = new Time(2, 2, 40);
        const Time* time2 = new Time(-5, 20, 30);
        time1->ShowTime();
        time2->ShowTime();
        Time time3;
        time3.AddTime(time1, new Time(2, 2, -40));
        delete time1;
        delete time2;
        time3.ShowTime();
    }
    catch (Time::TimeError& error)
    {
        cout << "ОШИБКА: ";
        error.printMessage();
        return 1;
    }
}