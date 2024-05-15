#pragma once
#include<vector>
#include<list>
#include <numeric>
#include<iostream>
using namespace std;

void vector_creation()
{
	// 1. Creating the values using push_back
	int x = 20;
	vector<int> vect;
	vect.push_back(10); //calls push_back(int&& val) version
	vect.push_back(x); //calls push_back(const int& val) version

	//2. initializing the value with default value initialization
	vector<int> vec1(3, 10); //vector is containing {10,10,10}

	//3. Initialize with an initializer list
	vector<int> vec2{ 10,20,30 };

	//4. Initialize with an array
	int arr[] = { 10,20,30 };
	vector<int> vec3{ arr, arr + 3 };

	//5. initializing from another vector
	vector<int> temp{ 10,20,30,40,50 };
	vector<int> vec4{ temp.begin(), temp.end() };

	//6. initializing all the vector elements with a particular value
	int value = 5;
	vector<int> vec5(10);
	std::fill(vec5.begin(), vec5.end(), value);

	//7.Initialize an array with consecutive numbers using std::iota

	vector<int> vec6(5);

	// initializing using iota() 
	std::iota(vec6.begin(), vec6.end(), 1); // prints 1,2,3,4,5



}  

void vector_operation()
{
	/*
		begin() – Returns an iterator pointing to the first element in the vector
		end() – Returns an iterator pointing to the theoretical element that follows the last element in the vector
		rbegin() – Returns a reverse iterator pointing to the last element in the vector (reverse beginning). It moves from last to first element
		rend() – Returns a reverse iterator pointing to the theoretical element preceding the first element in the vector (considered as reverse end)
		cbegin() – Returns a constant iterator pointing to the first element in the vector.
		cend() – Returns a constant iterator pointing to the theoretical element that follows the last element in the vector.
		crbegin() – Returns a constant reverse iterator pointing to the last element in the vector (reverse beginning). It moves from last to first element
		crend() – Returns a constant reverse iterator pointing to the theoretical element preceding the first element in the vector (considered as reverse end)
	*/

	//CAPACITY

	/*
		size() – Returns the number of elements in the vector.
		max_size() – Returns the maximum number of elements that the vector can hold.
		capacity() – Returns the size of the storage space currently allocated to the vector expressed as number of elements.
		resize(n) – Resizes the container so that it contains ‘n’ elements.
		empty() – Returns whether the container is empty.
		shrink_to_fit() – Reduces the capacity of the container to fit its size and destroys all elements beyond the capacity.
		reserve() – Requests that the vector capacity be at least enough to contain n elements.
	*/

	//ELEMENT ACCESS

	/*
		reference operator [g] – Returns a reference to the element at position ‘g’ in the vector
		at(g) – Returns a reference to the element at position ‘g’ in the vector
		front() – Returns a reference to the first element in the vector
		back() – Returns a reference to the last element in the vector
		data() – Returns a direct pointer to the memory array used internally by the vector to store its owned elements
	*/

	vector<int> g1;

	for (int i = 1; i <= 10; i++)
		g1.push_back(i * 10);

	cout << "\nReference operator [g] : g1[2] = " << g1[2];

	cout << "\nat : g1.at(4) = " << g1.at(4);

	cout << "\nfront() : g1.front() = " << g1.front();

	cout << "\nback() : g1.back() = " << g1.back();

	// pointer to the first element 
	int* pos = g1.data();

	cout << "\nThe first element is " << *pos;

}


void vector_main()
{
	vector_creation();
}
