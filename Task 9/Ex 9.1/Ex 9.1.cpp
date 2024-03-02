#include <iostream> 
#include <string> 
#include <windows.h>
#include <cmath>
using namespace std;

class Triangle
{
public:
    class TriangleError
    {
    public:
        TriangleError() : message("Треугольник с данными сторонами не существует") { }
        void printMessage() const { cout << message << endl; }
    private:
        string message;
    };
    
    // Конструктор Triangle
    Triangle(double sideA, double sideB, double sideC)
    {
        double Maximum = max(sideA, max(sideB, sideC));
        double Minimum = min(sideA, min(sideB, sideC));
        if ((2 * Maximum >= (sideA + sideB + sideC)) || (Minimum < 0))
            throw TriangleError();
        else
        {
            Triangle::set_side_A(sideA);
            Triangle::set_side_B(sideB);
            Triangle::set_side_C(sideC);
        }
    }
    // Установка стороны A
    void set_side_A(double sideA)
    {
        side_A = sideA;
    }

    // Получение стороны A 
    double get_side_A()
    {
        return side_A;
    }

    // Установка стороны B
    void set_side_B(double sideB)
    {
        side_B = sideB;
    }

    // Получение стороны B 
    double get_side_B()
    {
        return side_B;
    }

    // Установка стороны C
    void set_side_C(double sideC)
    {
        side_C = sideC;
    }

    // Получение стороны C 
    double get_side_C()
    {
        return side_C;
    }

    // Расчет площади треугольника
    double calc_square(Triangle* triangle1)
    {
        double square, pp;
        pp = (triangle1->get_side_A() + triangle1->get_side_B() + triangle1->get_side_C()) / 2;
        square = sqrt(pp * (pp - triangle1->get_side_A()) * (pp - triangle1->get_side_B()) * (pp - triangle1->get_side_C()));
        return square;
    }

private:
    double side_A;
    double side_B;
    double side_C;
    double square;        // Площадь 
};

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    try
    {
        Triangle* triangle1 = new Triangle(3, 4, 7);
        double sq = triangle1->calc_square(triangle1);
        delete triangle1;
        cout << "Площадь треугольника равна " << sq << endl;
    }
    catch (Triangle::TriangleError& error)
    {
        cout << "ОШИБКА: ";
        error.printMessage();
        return 1;
    }
    return 0;
}