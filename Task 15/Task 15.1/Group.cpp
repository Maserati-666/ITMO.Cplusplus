#include <iostream>
#include <string>
#include <Windows.h>
#include "Group.h"
#include "Student.h"
#include <list> 
#include <algorithm> 


using namespace std;

	void Group::addStudent(Student* newStudent)
	{
		masSt.push_back(newStudent);
	}

	//Student* Group::delStudent(Student* oldStudent)
	//{
	//	
	//}



	Group::Group(string name)
	{
		this->name = name;
	}
		Group::Group()
	{
		name = "Не определена";
	}
	void Group::setName(string newName)
	{
        name = newName;
    }

	string Group::getName()
	{
        return name;
	}

	int  Group::getSize()
	{
		return masSt.size();
	}

	//string Group::GroupOut(int n)
	//{
	//return	masSt[n]->get_last_name(); // было для вектора
	//}

	void Group::GroupOut()
	{
		iter = masSt.begin();            // вывод содержимого списка 
		while( iter != masSt.end() )
			(*iter++)->display();
	}


	// перегруженный == для класса Student 
	bool operator== (Student& p1,  Student& p2) 
	{
		return (p1.get_name() == p2.get_name() && p1.get_last_name() == p2.get_last_name() ) ? true : false;
	}

// перегруженный < для класса Student 
	bool operator< (Student& p1,  Student& p2)
	{
		if(p1.get_last_name() == p2.get_last_name())
			return (p1.get_name() < p2.get_name()) ? true : false; 
		return (p1.get_last_name() < p2.get_last_name() ) ? true : false;
	}

// перегруженный != для класса Student
	bool operator!= (Student& p1,  Student& p2)
	{ return !(p1 == p2); }

// перегруженный > для класса Student 
	bool operator> (Student& p1,  Student& p2)
	{ return !(p1 < p2) && !(p2 == p2); }





