#pragma once
#include<iostream>

class Fraction
{
	int m_num;
	int m_den;
public:
	Fraction(int x, int y=1): m_num(x),m_den(y) {}

	Fraction(const Fraction& copy):m_num(copy.m_num), m_den(copy.m_den)
	{
		std::cout << "Copy constructor called\n";
	}

	Fraction& operator=(const Fraction& copy);

	friend std::ostream& operator<<(std::ostream& out, Fraction& f);

};

Fraction& Fraction::operator=(const Fraction& copy)
{
	m_num = copy.m_num;
	m_den = copy.m_den;

	return *this;
}

std::ostream& operator<<(std::ostream& out, Fraction& f)
{
	out << f.m_num << "/" << f.m_den << std::endl;
	return out;
}
