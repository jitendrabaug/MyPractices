#pragma once
#include<vector>
#include<iostream>
#include<map>
using std::vector;
using std::cout;
using std::endl;
using std::map;


int Naive_find_majority_element(const vector<int>& vec)
{
	auto n = vec.size();
	int majority_count = n / 2 + 1;
	for (int i = 0; i < n; i++)
	{
		int search_elem = vec.at(i);
		int count = 0;
		for (int j = 0; j < n; j++)
		{
			if (vec.at(i) == vec.at(j))
				count++;
		}

		if (count >= majority_count)
			return vec.at(i);
	}
	return -1;
}

int map_find_majority_element(const vector<int>& vec)
{
	auto n = vec.size();
	int majority_count = n / 2 + 1;
	map<int, int> count_hash{};
	for (int i = 0; i < n; i++)
	{
		count_hash[vec.at(i)]++;
	}

	auto itr = count_hash.begin();
	while (itr != count_hash.end())
	{
		if (itr->second >= majority_count)
			return itr->first;
		itr++;
	}
	return -1;
}

int find_majority_element(const vector<int>& arr)
{
	int n = (int)arr.size();

	int res = 0, count = 1;
	// res will hold the location info to the majority element
	// this algorithm is based on boyece-moore algorithm of voting
	// if the elements are matching it will upvote and if not matching it will downvote
	for (int i = 0; i < n; i++)
	{
		if (arr[res] == arr[i])
			count++;
		else
			count--;

		if (count == 0)
		{
			res = i, count = 1;
		}
	}

	count = 0;
	//check here if the selected majority element in res is really a majority element
	for (int i = 0; i < n; i++)
		if (arr[res] == arr[i])
			count++;
	if (count <= n / 2)
		return -1;

	return arr[res];
}


