#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void writeFile(string);

int main()
{
    string text;
    const int N = 10;
    int a[N] = { 1, 25, 6, 32, 43, 5, 96, 23, 4, 55 };
    int min = 0; // для записи минимального значения
    int buf = 0; // для обмена значениями
    for (int i = 0; i < N; i++)
    {
        text.append(to_string(a[i]));
        text.append(" ");
    }
    writeFile("Исходный массив: " + text);
    for (int i = 0; i < N; i++)
    {
        min = i; // номер текущей ячейки, как ячейки с минимальным значением
        // в цикле найдем реальный номер ячейки с минимальным значением
        for (int j = i + 1; j < N; j++)
            min = (a[j] < a[min]) ? j : min;
        // перестановка этого элемента, поменяв его местами с текущим
        if (i != min)
        {
            buf = a[i];
            a[i] = a[min];
            a[min] = buf;
        }
    }
    text = "";
    for (int i : a)
    {
        text.append(to_string(i));
        text.append(" ");
    }
    writeFile("Отсортированный массив: " + text);
    return 0;
}

void writeFile(string text)
{
    ofstream f("Text.txt", ios::app);
    f << text << '\n';
    f.close();
}
