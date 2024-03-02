#include <iostream>
#include <windows.h>
#include "Dot.h"

using namespace std;

class Triangle
{
private:
    Dot* dot_one;
    Dot* dot_two;
    Dot* dot_three;
    double side_A;
    double side_B;
    double side_C;
public:
    // Конструктор Triangle
    Triangle()
    {
        dot_one = new Dot();
        dot_two = new Dot(0, 3);
        dot_three = new Dot(4, 3);
        side_A = dot_one->distanceTo(*dot_two);
        side_B = dot_two->distanceTo(*dot_three);
        side_C = dot_three->distanceTo(*dot_one);
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
        pp = this->calc_perimetr() / 2;
        square = sqrt(pp * (pp - side_A) * (pp - side_B) * (pp - side_C));
        return square;
    }
};

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    Triangle* triangle = new Triangle();
    triangle->output_len_side();
    cout << "Периметр треугольника равен: " << triangle->calc_perimetr() << endl;
    cout << "Площадь треугольника равна: " << triangle->calc_square() << endl;
}