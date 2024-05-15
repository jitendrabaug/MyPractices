#pragma once

#include<iostream>


class Point
{
private:
	double m_x;
	double m_y;
	double m_z;

public:
	Point(double x = 0.0, double y =0.0, double z=0.0) : m_x(x), m_y(y), m_z(z)
	{

	}

	friend std::ostream& operator<< (std::ostream& out, Point& p);
	friend std::istream& operator>>(std::istream& in, Point& p);
};

std::ostream& operator<<(std::ostream& out, Point& p)
{
	out << p.m_x << "," << p.m_y << "," << p.m_z << std::endl;
	return out;
}

std::istream& operator>> (std::istream& in, Point& p)
{
	in >> p.m_x;
	in >> p.m_y;
	in >> p.m_z;
	return in;
}


class MyClass {
private:
	int value;

public:
	// Constructor
	MyClass(int val) : value(val) {}

	// Overloading insertion operator (<<) as a member function
	std::ostream& operator<<(std::ostream& os) const {
		os << "Value: " << value;
		return os;
	}

	// Overloading extraction operator (>>) as a member function
	std::istream& operator>>(std::istream& is) {
		is >> value;
		return is;
	}
};



void Operator_main()
{
	Point p;
	std::cin >> p;
	std::cout << p;


	MyClass obj(0);
	// Example of using extraction operator (>>)
	std::cout << "Enter a value: ";
	obj >> std::cin;

	// Example of using insertion operator (<<)
	std::cout << "You entered: ";
	obj << std::cout << std::endl;


}