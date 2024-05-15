#pragma once
#include<iostream>

class Cent
{
	int m_cents;
public:
	Cent(int cents) : m_cents(cents){}
	 operator int()
	{
		 return m_cents;
	}
};



void cast_main()
{

	Cent cent(10);
	int val = static_cast<int>(cent);
	std::cout << "The integer value cast is : " << val << std::endl;
}
