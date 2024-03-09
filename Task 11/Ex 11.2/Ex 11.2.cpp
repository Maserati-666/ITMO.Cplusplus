#include <iostream> 
#include <string> 
#include <vector> 
#include <algorithm> // для алгоритма сортировки 
using namespace std;

class Point
{
	friend std::ostream& operator<< (std::ostream& out, const Point& point);
private:
	double x;
	double y;
public:
	Point()
	{
		x = 0; y = 0;
	}

	Point(double x, double y)
	{
		this->x = x;
		this->y = y;
	}

	double distanceTo(Point point)
	{
		return sqrt(pow(point.x - x, 2) + pow(point.y - y, 2));
	}

	bool operator < (Point point)
	{
		return this->distanceTo(Point (0, 0)) < point.distanceTo(Point(0, 0));
	}
};

std::ostream& operator<< (std::ostream& out, const Point& point)
{
	out << "x: " << point.x << " y: " << point.y << "\"\n";
	return out;
}

int main()
{
	std::vector<Point> v;
	v.push_back(Point(1, 2));
	v.push_back(Point(10, 12));
	v.push_back(Point(21, 7));
	v.push_back(Point(4, 8));
	std::sort(v.begin(), v.end()); // требуется перегрузка оператора < для 
	// класса Point 
	for (auto& point : v)
		std::cout << point << '\n'; // требуется перегрузка оператора << для 
	// класса Point 
	return 0;
}
