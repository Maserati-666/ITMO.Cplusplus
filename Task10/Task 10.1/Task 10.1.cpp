#include <iostream> 
#include <string> 
#include <windows.h> 
#include "student.h" 
using namespace std;

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    IdCard *idc = new IdCard(123, "Базовый");
    string name = "Ivan";
    string last_name = "Ivanov";
    Student* student02 = new Student(name, last_name, idc);
    cout << "IdCard: " << student02->getIdCard().getNumber() << endl;
    cout << "Category: " << student02->getIdCard().getCategory() << endl;
    int num; string cat;
    cout << "IdCard: " << endl;
    cin >> num;
    cout << "Category: " << endl;
    cin >> cat;
    idc->setNumber(num);
    idc->setCategory(cat);
    student02->setIdCard(idc);
    //student02->setIdCard(new IdCard(num, cat));
    cout << "IdCard: " << student02->getIdCard().getNumber() << endl;
    cout << "Category: " << student02->getIdCard().getCategory() << endl;
    return 0;
}