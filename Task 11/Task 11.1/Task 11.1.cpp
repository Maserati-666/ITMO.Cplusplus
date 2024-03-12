#include <iostream>
#include <Windows.h>

using namespace std;

class Distance
{
	friend Distance operator-(const Distance&, const Distance&);
	friend std::ostream& operator<< (std::ostream& out, const Distance
		& dist);
private:
	int feet;
	float inches;
public:
	// конструктор по умолчанию 
	Distance() : feet(0), inches(0.0) { }
	// конструктор с двумя параметрами 
	Distance(int ft, float in) : feet(ft), inches(in) { }
	void getdist()
	{
		cout << "\nВведите число футов : ";
		cin >> feet;
		cout << "\nВведите число дюймов : ";
		cin >> inches;
	}
	void showdist()
	{
		cout << feet << "\" - " << inches << "\"\n";
	}
	Distance operator+ (const Distance& d2) const
	{
		int f = feet + d2.feet;
		float i = inches + d2.inches;
		if (i >= 12.0)
		{
			i -= 12.0;
			f++;
		}
		return Distance(f, i);
	}
};

Distance operator- (const Distance& d1, const Distance& d2)
{
	int f = 0; float i = 0;
	if (d1.inches < d2.inches)
	{
		i = d1.inches + 12 - d2.inches;
		f = d1.feet - 1 - d2.feet;
	}
	else
	{
		i = d1.inches - d2.inches;
		f = d1.feet - d2.feet;
	}
	return Distance(f, i);
}

std::ostream& operator<< (std::ostream& out, const Distance& dist)
{
	out << dist.feet << "\" - " << dist.inches << "\"\n";
	return out;
}

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	Distance dist1, dist2, dist3, dist4;
	dist1.getdist();
	dist2.getdist();
	dist3 = dist1 - dist2;
	dist4 = dist1 + dist2 + dist3;
	cout << "\ndist1 = " << dist1;
	cout << "\ndist2 = " << dist2;
	cout << "\ndist3 = " << dist3;
	cout << "\ndist4 = " << dist4;

}