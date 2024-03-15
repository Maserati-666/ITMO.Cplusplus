
#include <iostream>

class Point 
{
public:
    // конструктор по умолчанию
    Point()
    {
        this->x = 0;
        this->y = 0;
    }

    // конструктор
    Point(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
    // Перегрузка оператора = для сложения двух классов
    Point operator+ (const Point& point) 
    {
        Point newPnt(this->x + point.x, this->y + point.y);
        return newPnt;
    }
    // Перегрузка оператора = для сложения класса и числа
    Point operator+ (const int value)
    {
        Point newPnt(this->x + value, this->y);
        return newPnt;
    }
    // Перегрузка оператора += для сложения двух классов
    void operator+= (Point& point) 
    {
        *this = *this + point;
    }
    void print()
    {
        std::cout << "x = " << this->x << " ** y = " << this->y << std::endl;
    }

private:
    int x, y;
};

int main()
{
    Point pt1(1, 1), pt2(2, 2), pt3;
    pt3 = pt1 + pt2;
    pt2 += pt1;
    pt3 = pt1 + 5;
}
