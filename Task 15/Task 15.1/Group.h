#pragma once /* «ащита от двойного подключени€ заголовочного файла */
#include <string>
#include <list>
#include <algorithm>
#include "Student.h"

using namespace std;


class Group
{
private:
	string name;
	list<Student*> masSt;			// список студентов
	list<Student*>::iterator iter; // итератор дл€ списка
	

public:
	Group(string name);
	Group();

	void setName(string newName);
	string getName();
	int  getSize();
	void addStudent(Student* newStudent);
	//string GroupOut(int);	// было дл€ вектора
	void GroupOut(); 
	Student* delStudent(Student* oldStudent);

	friend bool operator< (Student&,  Student&);
	friend bool operator> (Student&,  Student&);
	friend bool operator== (Student&,  Student&);
	friend bool operator!= (Student&,  Student&);
	
};