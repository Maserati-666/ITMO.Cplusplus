#include <iostream>
#include <string>
#include <map>
#include "windows.h"

using namespace std;

struct StudentGrade 
{
	string name;
	char grade;
	StudentGrade(string name, char grade)
	{
		this->name = name;
		this->grade = grade;
	}
};

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	StudentGrade student1 = StudentGrade("Петр", '3');
	StudentGrade student2 = StudentGrade("Семен", '4');
	StudentGrade student3 = StudentGrade("Анна", '5');
	StudentGrade student4 = StudentGrade("Дмитрий", '4');
	StudentGrade student5 = StudentGrade("Андрей", '3');
	map<string, char> map_student;
	map_student[student1.name] = student1.grade;
	map_student[student2.name] = student2.grade;
	map_student[student3.name] = student3.grade;
	map_student[student4.name] = student4.grade;
	map_student[student5.name] = student5.grade;
	for (const auto& element : map_student)
		cout << element.first << " - " << element.second << std::endl;
	return 0;
}
