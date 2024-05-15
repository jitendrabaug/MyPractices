#include"ClassesHeader.h"
#include<string_view>


const std::string& firstAlphabetical(const std::string& a, const std::string& b)
{
	return (a < b) ? a : b; // We can use operator< on std::string to determine which comes first alphabetically
}

class Employee
{
	std::string m_name{};

public:
	void setName(std::string_view name) { m_name = name; }
	const std::string& getName() const { return m_name; } //  getter returns by const reference
};

// createEmployee() returns an Employee by value (which means the returned value is an rvalue)
Employee createEmployee(std::string_view name)
{
	Employee e;
	e.setName(name);
	return e;
}


int main()
{
	const Date date{ 12,3,2024 };
	cout << date.day << " " << date.month << " " << date.year << std::endl;
	//date.increment(); --> Compiler error :can't increment as date object is constant
	//date.day++; --> Compiler error : date object is constant
	//date.print(); Compiler error : non-const function can't be called.
	date.print();
	//-------------------------------------------------------------------------------------------

	std::string hello{ "Hello" };
	std::string world{ "World" };

	std::cout << firstAlphabetical(hello, world) <<std::endl; // either hello or world will be returned by reference
	//-------------------------------------------------------------------------------------------
	
	// Case 1: okay: use returned reference to member of rvalue class object in same expression
	std::cout << createEmployee("Frank").getName();

	// Case 2: bad: save returned reference to member of rvalue class object for use later
	const std::string& ref{ createEmployee("Garbo").getName() }; // reference becomes dangling when return value of createEmployee() is destroyed
	std::cout << "\nReference to rvalue : " << ref <<std::endl; // undefined behavior

	// Case 3: okay: copy referenced value to local variable for use later
	std::string val{ createEmployee("Hans").getName() }; // makes copy of referenced member
	std::cout << val; // okay: val is independent of referenced member

	Fraction f{ 5, 3 };  // Calls Fraction(int, int) constructor
	Fraction fCopy{ f }; // Calls Fraction(const Fraction&) copy constructor

	return 0;
}