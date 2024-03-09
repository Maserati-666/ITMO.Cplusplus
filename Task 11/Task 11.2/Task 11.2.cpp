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
	operator float() const
	{
		float fracfeet = inches / 12;
		fracfeet += static_cast<float>(feet);
		return fracfeet / MTF;
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
	Distance dist2;
	Distance dist1 = 2.35F;
	float mtrs;
	mtrs = static_cast<float>(dist1);
	cout << "mtrs = " << mtrs;
	dist2.getdist();
	mtrs = dist2;
	cout << "\ndist1 = " << dist1;
	cout << "\nmtrs = " << mtrs;
}