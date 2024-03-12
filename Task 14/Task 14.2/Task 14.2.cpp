#include "windows.h"
#include <iostream>
#include <tuple> 
#include <string> 
#include <vector> 

using namespace std;

template<class Tuple>
void printTupleOfThree(Tuple t)
{
    cout << "("
        << std::get<0>(t) << ", "
        << std::get<1>(t) << ", "
        << std::get<2>(t) << ")" << endl;
}
int main()
{
        SetConsoleOutputCP(1251);
        SetConsoleCP(1251);
        vector<string> v1{ "one", "two", "three", "four", "five", "six" };
        vector<int> v2 = { 1, 2, 3, 4, 5, 6 };
        vector<double> v3 = { 1.1, 2.2, 3.3, 4.4, 5.5, 6.6 };
        auto t3 = std::make_tuple(v1[0], v1[1], v2[2]);
        printTupleOfThree(t3);
        return 0;
}
