#include <iostream>
#include <Windows.h>

using namespace std;

class Distance
{
	friend std::ostream& operator<< (std::ostream& out, const Distance
		& dist);
private:
	int feet;
	float inches;
	const float MTF;
public:
	// конструктор по умолчанию 
	Distance() : feet(0), inches(0.0), MTF(3.280833F) { }
	// конструктор с двумя параметрами 
	Distance(int ft, float in) : feet(ft), inches(in), MTF(3.280833F) { }

	Distance(float meters) : MTF(3.280833F)
	{
		float fltfeet = MTF * meters;      // перевод в футы 
		feet = int(fltfeet); // число полных футов 
		inches = 12 * (fltfeet - feet); // остаток - это дюймы 
	}

	void getdist()
	{
		cout << "\nВведите число футов : ";
		cin >> feet;
		cout << "\nВведите число дюймов : ";
		cin >> inches;
	}
	void showdist()
	{
		cout << feet << "\' - " << inches << "\"\n";
	}

	/*Distance operator+ (float value) const
	{
		Distance d = value;
		return *this + d;
	}*/

	/*Distance operator+ (const Distance& d)
	{
		float value = d;
		return *this + value;
	}*/
	operator float() const
	{
		float fracfeet = inches / 12;
		fracfeet += static_cast<float>(feet);
		return fracfeet / MTF;
	}
};

std::ostream& operator<< (std::ostream& out, const Distance& dist)
{
	out << dist.feet << "\' - " << dist.inches << "\"\n";
	return out;
}



int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	Distance dist1;
	dist1.getdist();
	Distance dist2 = dist1 + 2.0;
	Distance dist3 = 2.0 + dist1;
	cout << "\ndist1 = " << dist1;
	cout << "\ndist2 = " << dist2;
	cout << "\ndist3 = " << dist2;
}