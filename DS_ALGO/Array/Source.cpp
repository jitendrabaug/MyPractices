#include"Maximum_Subarray_Sum.h"
#include"Majority.h"
#include"TimeCalc.h"

int main()
{
	using std::cout;
	using std::endl;

	/*vector<int> vec{ 2,3,-8,7,-1,2,3 };
	cout << "Naive approach maximum subarray sum result : " << Naive_SubArray_Sum(vec) <<std::endl;
	cout << "Efficient approach maximum subarray sum result : " << Efficient_SubArray_Sum(vec)<<std::endl;
	vector<int> vec1{ 3,-4,5,6,-8,7 };
	cout << "Naive approach Circular maximum subarray sum result : " << naive_Circular_SubArray_Sum(vec1) << std::endl;
	*/
	
	/*===============================================================
	| majority Element
	==================================================================*/
	vector<int> vec{ 2,3,-8,3,3,2,3 };
	auto start = std::chrono::high_resolution_clock::now();
	auto val = Naive_find_majority_element(vec);
	auto stop = std::chrono::high_resolution_clock::now();
	cout << "Majority Element is " << val << " and time taken in naive method is " << calculateTimeDifference(start,stop) << endl;

	 start = std::chrono::high_resolution_clock::now();
	 val = map_find_majority_element(vec);
	 stop = std::chrono::high_resolution_clock::now();
	 cout << "Majority Element is " << val << " and time taken in using map is " << calculateTimeDifference(start, stop) << endl;

	 start = std::chrono::high_resolution_clock::now();
	 val = find_majority_element(vec);
	 stop = std::chrono::high_resolution_clock::now();
	 cout << "Majority Element is " << val << " and time taken in using Moore's voting algorithm is " << calculateTimeDifference(start, stop) << endl;


	return 0;
}