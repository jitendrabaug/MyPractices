#pragma once
#include<iostream>
#include<vector>
#include<algorithm>

using std::cout;
using std::vector;


int Naive_SubArray_Sum(vector<int>& vec)
{
	int sum = vec.at(0);
	for (int i = 0; i < vec.size(); i++)
	{
		int curr = 0;
		for (int j = i; j < vec.size(); j++)
		{
			curr = curr + vec.at(j);
			sum = std::max<int>(sum, curr);
		}
	}
	return sum;
}

int Efficient_SubArray_Sum(vector<int>& vec)
{
	int sum = vec.at(0);
	int maxending = vec.at(0);

	for (int i = 1; i < vec.size(); i++)
	{
		maxending = std::max<int>(vec.at(i), maxending + vec.at(i));
		sum = std::max<int>(maxending, sum);
	}

	return sum;
}

int naive_Circular_SubArray_Sum(vector<int>& arr)
{
	int n = arr.size();
	int res = arr[0];

	for (int i = 0; i < n; i++)
	{
		int curr_max = arr[i];
		int curr_sum = arr[i];

		for (int j = 1; j < n; j++)
		{
			int index = (i + j) % n;

			curr_sum += arr[index];

			curr_max = std::max(curr_max, curr_sum);
		}

		res = std::max(res, curr_max);
	}
	return res;
}


class IntList
{
private:
	int m_list[10]{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 }; // give this class some initial state for this example

public:
	// Use an explicit object parameter (self) and auto&& to differentiate const vs non-const
	auto&& operator[](this auto&& self, int index)
	{
		// Complex code goes here
		return self.m_list[index];
	}
};




