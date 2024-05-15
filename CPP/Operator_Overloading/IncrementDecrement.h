#pragma once
#include<iostream>


class IncDec
{
public:

	double value;


	IncDec(int val = 0) : value(val)
	{

	}


	IncDec& operator++();
	IncDec& operator++(int);
	IncDec& operator--(); 
	IncDec& operator--(int);

	friend std::ostream& operator<<(std::ostream& out, IncDec& Inc);

};

std::ostream& operator<<(std::ostream& out, IncDec& Inc)
{
	out << Inc.value << std::endl;
	return out;
}


IncDec& IncDec::operator++()
{
	std::cout << " pre increment operator is called" << std::endl;
	++value;
	return *this;

}

IncDec& IncDec::operator++(int)
{
	std::cout << " post increment operator is called" << std::endl;
	auto temp(*this);
	++ this->value;
	return temp;

}

IncDec& IncDec::operator--()
{
	std::cout << " pre decrement operator is called" << std::endl;
	value--;
	return *this;
}

IncDec& IncDec::operator--(int)
{
	std::cout << " post decrement operator is called" << std::endl;

	auto temp(*this);
	--this->value;
	return temp;
} 


void Increment_Main()
{
	IncDec digit{ 5 };

	std::cout << digit;
	std::cout << ++digit; // calls Digit::operator++();
	std::cout << digit++; // calls Digit::operator++(int);
	std::cout << digit;
	std::cout << --digit; // calls Digit::operator--();
	std::cout << digit--; // calls Digit::operator--(int);
	std::cout << digit;
}