#include <iostream>
#include "windows.h"

using namespace std;

template<class T> 
double calc_average(T arr[], int size)
{
    double sum = 0;
    for (int i = 0; i < size; i++) 
    {
        sum += arr[i];
    }
    return sum / size;
}

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    int arr1[] = {1, 2, 3, 4, 5};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    std::cout << calc_average(arr1, size1) << std::endl;
    long arr2[] = {10L, 20L, 30L, 40L, 50L};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    std::cout << calc_average(arr2, size2) << std::endl;
    double arr3[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    int size3 = sizeof(arr3) / sizeof(arr3[0]);
    std::cout << calc_average(arr3, size3) << std::endl;
    char arr4[] = "Hello, word";
    int size4 = sizeof(arr4) / sizeof(arr4[0]);
    std::cout << calc_average(arr4, size4) << std::endl;
}
