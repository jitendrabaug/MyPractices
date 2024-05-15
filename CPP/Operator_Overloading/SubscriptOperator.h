#pragma once
#include<iostream>


class IntList
{
	int m_list[10]{1,2,3,4,5,6,7,8,9,0};
public:
	int& operator[](int index)
	{
		return m_list[index];
	}

	void display()
	{
		for (auto& x : m_list)
		{
			std::cout << x << " ";
		}

		std::cout << std::endl;
	}

	const int operator[](int index) const
	{
		return m_list[index];
	}
};

void subs_main()
{
	IntList intl;
	intl[3] = 12;

	intl.display();
}