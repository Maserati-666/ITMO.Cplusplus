#pragma once /* ������ �� �������� ����������� ������������� ����� */ 
#include <string> 
using namespace std;

class Time
{
public:
    //// ����������� ������ Time #1
    Time();
    // ����������� ������ Time #2
    Time(int, int, int);
    
    //// ���������� ������ Student 
    //~Student();

    // ��������� ����� 
    void set_hours(int);
    // ��������� ����� 
    int get_hours() const;
    // ��������� ����� 
    void set_minutes(int);
    // ��������� ����� 
    int get_minutes() const;
    // ��������� ������ 
    void set_seconds(int);
    // ��������� ������
    int get_seconds() const;
    // ����� �� �����
    void ShowTime() const;
    // ����� �������� ���� Time
    void AddTime(const Time*, const Time*);

private:
    // ���� 
    int mutable hours;
    // ������ 
    int minutes;
    // ������� 
    int seconds;
};