#include <iostream>
#include <windows.h>
using namespace std;

void arrayOperations(const int, int[]);
void arrayReplace(const int, int[]);

int main()
{
    SetConsoleOutputCP(1251);
    const int n = 10;
    int mas[n];
    for (int i = 0; i < n; i++)
    {
        cout << "mas[" << i << "]=";
        cin >> mas[i];
    }
    const int size = 10;
    int a[size] = { 1, 25, 6, 32, 43, 5, 96, 23, 4, 55 };
    arrayOperations(n, mas);
    arrayReplace(size, a);
    return 0;
}

void arrayOperations(const int n, int mas[])
{
    int s = 0;
    bool flagNeg = false, flagPos = false;
    int sumNeg = 0, sumPos = 0;
    int sumEven = 0, sumOdd = 0;
    int maxVal, maxIndex, minVal, minIndex;
    for (int i = 0; i < n; i++)
    {
        s += mas[i];
        if (mas[i] < 0)
        {
            sumNeg += mas[i];
            flagNeg = true;
        }
        else
        {
            sumPos += mas[i];
            flagPos = true;
        }
        if (i % 2 == 0)
            sumEven += mas[i];
        else
            sumOdd += mas[i];
        if (i == 0)
        {
            maxVal = mas[i];
            maxIndex = i;
            minVal = mas[i];
            minIndex = i;
        }
        else
        {
            if (mas[i] > maxVal)
            {
                maxVal = mas[i];
                maxIndex = i;
            }
            if (mas[i] < minVal)
            {
                minVal = mas[i];
                minIndex = i;
            }
        }
    }
    cout << "Сумма значений элементов массива: " << s << endl;
    double mid; // среднее значение элементов
    mid = double(s) / n;
    cout << "Среднее значение элементов массива: " << mid << endl;
    if (flagNeg == true)
        cout << "Сумма отрицательных элементов массива: " << sumNeg << endl;
    else
        cout << "В массиве нет отрицательных элементов!" << endl;
    if (flagPos == true)
        cout << "Сумма положительных элементов массива: " << sumPos << endl;
    else
        cout << "В массиве нет положительных элементов!" << endl;
    cout << "Сумма четных элементов массива: " << sumEven << endl;
    cout << "Сумма нечетных элементов массива: " << sumEven << endl;
    cout << "Максимальное значение элемента массива: " << maxVal << " , его индекс: " << maxIndex << endl;
    cout << "Минимальное значение элемента массива: " << minVal << " , его индекс: " << minIndex << endl;
    int sumEntMinMax = 1; // произведение элементов между мин и макс
    for (int i = min(maxIndex, minIndex); i < max(maxIndex, minIndex) - 1; i++)
    {
        if (max(maxIndex, minIndex) - min(maxIndex, minIndex) > 1)
        {
            sumEntMinMax *= mas[i + 1];
        }
        else
            sumEntMinMax = 1;
    }
    if (sumEntMinMax == 1)
        cout << "Между минимальным и максимальным значением нет элементов" << endl;
    else
        cout << "Произведение элементов между минимальным и максимальным значением = " << sumEntMinMax << endl;
}

void arrayReplace(const int N, int a[])
{
    int min = 0; // для записи минимального значения
    int buf = 0; // для обмена значениями
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
    for (int i = 0; i < N; i++)
        cout << a[i] << '\t';
}