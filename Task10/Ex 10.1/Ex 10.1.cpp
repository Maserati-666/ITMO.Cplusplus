#include <iostream>
#include <windows.h> 
#include "Dot.h" 
using namespace std;

class Triangle
{
public:
    // Конструктор Triangle
    Triangle(Dot *dot_one, Dot *dot_two, Dot *dot_three)
    {   
            Triangle::set_dot_one(dot_one);
            Triangle::set_dot_two(dot_two);
            Triangle::set_dot_three(dot_three);
            side_A = dot_one->distanceTo(*dot_two);
            side_B = dot_two->distanceTo(*dot_three);
            side_C = dot_three->distanceTo(*dot_one);
    }
    // Установка вершины 1
    void set_dot_one(Dot* dotOne)
    {
        dot_one = dotOne;
    }

    // Получение вершины 1
    Dot get_dot_one()
    {
        return *dot_one;
    }

    // Установка вершины 2
    void set_dot_two(Dot* dotTwo)
    {
        dot_two = dotTwo;
    }

    // Получение вершины 2
    Dot get_dot_two()
    {
        return *dot_two;
    }

    // Установка вершины 3
    void set_dot_three(Dot* dotThree)
    {
        dot_three = dotThree;
    }

    // Получение вершины 3
    Dot get_dot_three()
    {
        return *dot_three;
    }

    // Вывод длин сторон треугольника
    void output_len_side()
    {
        cout << "Длина стороны A: " << side_A << endl;
        cout << "Длина стороны B: " << side_B << endl;
        cout << "Длина стороны C: " << side_C << endl;
    }

    // Расчет периметра треугольника
     double calc_perimetr()
    {
        return side_A + side_B + side_C;
    }

    // Расчет площади треугольника
    double calc_square()
    {
        double square, pp;
        pp = this->calc_perimetr()/ 2;
        square = sqrt(pp * (pp - side_A) * (pp - side_B) * (pp - side_C));
        return square;
    }

private:
    Dot* dot_one;
    Dot* dot_two;
    Dot* dot_three;
    double side_A;
    double side_B;
    double side_C;
};

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    Dot *dot1 = new Dot();
    Dot *dot2 = new Dot(0, 3);
    Dot *dot3 = new Dot(4, 3);
    Triangle* triangle = new Triangle(dot1, dot2, dot3);
    triangle->output_len_side();
    cout << "Периметр треугольника равен: " << triangle->calc_perimetr() << endl;
    cout << "Площадь треугольника равна: " << triangle->calc_square() << endl;
}
