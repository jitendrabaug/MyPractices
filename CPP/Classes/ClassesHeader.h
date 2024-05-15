#pragma once
#include<iostream>
using std::cout;

struct Date
{
	int day;
	int month;
	int year;

	void increment()
	{
		++day;
	}

	void print()
	{
		cout << day << " " << month << " " << year << std::endl;
	}
	
	void print() const
	{
		cout << day << "/" << month << "/" << year << std::endl;
	}
};
void Dispaly()
{
	cout << "Hello World!!!" << std::endl;
}


class Fraction
{
	int m_numerator{ 0 };
	int m_denominator{ 1 };
public:
	Fraction(int numerator = 0, int denominator = 1)
		: m_numerator{ numerator }, m_denominator{ denominator }
	{
	}
	Fraction(Fraction& fromFrac) : m_numerator{ fromFrac.m_numerator }
		, m_denominator{ fromFrac.m_denominator }
	{
		std::cout << "Copy constructor called\n"; // just to prove it works
	}
	void print() const
	{
		std::cout << "Fraction(" << m_numerator << ", " << m_denominator << ")\n";
	}
	
};