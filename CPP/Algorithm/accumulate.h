#include <iostream>
#include <vector>
#include <numeric>
#include <functional>
#include <iterator>
#include<execution>
#include<chrono>

using namespace std;

int returnUserdef(int x, int y)
{
	return x * y;
}
void accumulate_basic() {
  vector<int> numbers {10, 3, -5, 12, 5, 35, 11, -19};
  
  auto start = std::chrono::high_resolution_clock::now();

  int sum = accumulate(begin(numbers), end(numbers), 0);
  long product = accumulate(begin(numbers), end(numbers), 1, std::multiplies<long>());  //std::multiplies<long>() is in functional header
  auto stop = std::chrono::high_resolution_clock::now();
  cout << "Sum: " << sum << "\n";
  cout << "Product: " << product << "\n";
  cout << "Time taken for accumulate :" << duration_cast<std::chrono::microseconds>(stop - start) << " ms" << std::endl;

  start = std::chrono::high_resolution_clock::now();
  sum = reduce(begin(numbers), end(numbers), 0);
  product = reduce(std::execution::par,begin(numbers), end(numbers), 1, std::multiplies<long>());
  stop = std::chrono::high_resolution_clock::now();

  cout << "Sum: " << sum << "\n";
  cout << "Product: " << product << "\n";
  cout << "Time taken for reduce with parallel :" << duration_cast<std::chrono::microseconds>(stop - start) << " ms" << std::endl;

  sum = accumulate(begin(numbers), end(numbers), 1 ,returnUserdef);
  cout << "Product: " << sum << "\n";
}

template<typename iterator, typename T>
void accumulate(iterator first, iterator last, T& val)
{
	val = std::accumulate(first, last, val);
}

template<typename iterator, typename T>
void parallel_accumulate(iterator start, iterator end, T& ref)
{
	unsigned MIN_BLOCK_SIZE = 1000;

	unsigned distance = std::distance(start, end);
	unsigned allowed_threads_by_elements = (distance + 1) / MIN_BLOCK_SIZE;
	unsigned allowed_threads_by_hardware = std::thread::hardware_concurrency();

	// this is due to the fact that some operating system may 
	// return 0 to indicate that this has not implemented
	if (allowed_threads_by_hardware < 1)
		allowed_threads_by_hardware = 2;

	unsigned allowed_threads = std::min(allowed_threads_by_elements,
		allowed_threads_by_hardware);

	//caculating the block size 
	unsigned block_size = (distance + 1) / allowed_threads;

	std::vector<T> results(allowed_threads);
	std::vector<std::thread> threads(allowed_threads - 1);

	//iterate and craeting new threads to calculate sum for each blocks
	iterator last;
	for (unsigned i = 0; i < allowed_threads - 1; i++)
	{
		last = start;
		std::advance(last, block_size);
		threads[i] = std::thread(accumulate<iterator, T>, start, last,
			std::ref(results[i]));
		start = last;
	}

	//final block will be calculated from this thread
	results[allowed_threads - 1] =
		std::accumulate(start, end, results[allowed_threads - 1]);

	//calling join on the newly craeted threads
	for_each(threads.begin(), threads.end(), std::mem_fn(&std::thread::join));
	ref = std::accumulate(results.begin(), results.end(), ref);
}
