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

    // Создание массива длин сторон треугольника
    double* create_masSide()
    {
        double mas[3];
        mas[0] = dot_one->distanceTo(*dot_two);
        mas[1] = dot_two->distanceTo(*dot_three);
        mas[2] = dot_three->distanceTo(*dot_one);
        return mas;
    }


    // Вывод длин сторон треугольника
    void output_len_side()
    {
        double *mas;
        mas = create_masSide();
        double side_A = mas[0];
        double side_B = mas[1];
        double side_C = mas[2];
        cout << "Длина стороны A: " << side_A << endl;
        cout << "Длина стороны B: " << side_B << endl;
        cout << "Длина стороны C: " << side_C << endl;
    }

    // Расчет периметра треугольника
     double calc_perimetr()
    {
        double* mas;
        mas = create_masSide();
        return mas[0] + mas[1] + mas[2];
    }

    // Расчет площади треугольника
    double calc_square()
    {
        double* mas;
        mas = create_masSide();
        double square, pp;
        pp = this->calc_perimetr()/ 2;
        square = sqrt(pp * (pp - mas[0]) * (pp - mas[1]) * (pp - mas[2]));
        return square;
    }

private:
    Dot* dot_one;
    Dot* dot_two;
    Dot* dot_three;
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
