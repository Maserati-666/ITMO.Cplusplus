#include "windows.h"
#include <iostream>
#include <vector>

using namespace std;

template<class T> void Print(T, string);

int main() 
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	vector<int> data = { 1, 2, 3 };
	Print(data, ", "); // на экране: 1, 2, 3 
}

template<class T> void Print(T str, string razd)
{
	for (auto item : str) 
	{
		if (item == *(str.end() - 1))
			cout << item << "\n";
		else
			cout << item << razd;
	}
}