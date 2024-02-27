#pragma once /* Защита от двойного подключения заголовочного файла */ 
#include <string> 
using namespace std;

class Time
{
public:
    //// Конструктор класса Time #1
    Time();
    // Конструктор класса Time #2
    Time(int, int, int);
    
    //// Деструктор класса Student 
    //~Student();

    // Установка часов 
    void set_hours(int);
    // Получение часов 
    int get_hours() const;
    // Установка минут 
    void set_minutes(int);
    // Получение минут 
    int get_minutes() const;
    // Установка секунд 
    void set_seconds(int);
    // Получение секунд
    int get_seconds() const;
    // Вывод на экран
    void ShowTime() const;
    // Метод сложения двух Time
    void AddTime(const Time*, const Time*);

private:
    // Часы 
    int mutable hours;
    // Минуты 
    int minutes;
    // секунды 
    int seconds;
};