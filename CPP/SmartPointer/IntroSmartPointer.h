#pragma once
#include<iostream>
using namespace std;

template<typename T>
class Auto_ptr
{
	T* m_ptr{};

public:
	Auto_ptr(T* ptr = nullptr) :m_ptr(ptr){}
	~Auto_ptr() { delete m_ptr; }

	T& operator*() { return *m_ptr; }
	T* operator->() { return m_ptr; }

	Auto_ptr(Auto_ptr& ptr)
	{
		std::cout << "Copy constructor is called.." << std::endl;
		m_ptr = ptr.m_ptr;
		ptr.m_ptr = nullptr;
	}

	Auto_ptr& operator=(Auto_ptr& rhs)
	{
		std::cout << "Copy assignment operator is called.." << std::endl;
		if (&rhs == this)
			return *this;

		delete m_ptr;
		m_ptr = rhs.m_ptr;
		rhs.m_ptr = nullptr;

	}
};


class Resource
{
public:
	Resource() { std::cout << "Resource Created.." << std::endl; };
	~Resource() { std::cout << "Resource DESTROYED.." << std::endl; }
};

void PassbyValue(Auto_ptr<Resource> res)
{
	std::cout << "Hello" << std::endl;
}


void fun(int&& ref)
{
	std::cout << "R-Value reference is called with value : " << ref << std::endl;
}
void fun(const int& ref)
{
	std::cout << "const L-Value reference is called with value : " << ref << std::endl;
}


void main_smart()
{
	Auto_ptr<Resource> res(new Resource());
	//Both the below cases when the pointer resource is copied, it tries to delete the same resource 2 times.
	//PassbyValue(res);
	//Auto_ptr<Resource> res1(res);

	//After implementing the cpoy constructor

	int&& ref = 6;
	fun(ref);
}

