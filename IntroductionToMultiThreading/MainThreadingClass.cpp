#include <iostream>
#include <thread>
#include <algorithm>
#include <chrono>
#include <sstream>
#include <future>
#include <vector>


/*	This file is meant as a introduction into multi-threading from std::thread 
	as well as to serve as a benchmark for the current machine that it's run on 
	
*/
using ull = unsigned long long;

#define START 0
#define END 1'900'000'0000
ull odd_num_count = 0;
ull even_num_count = 0;
const auto processor_count = std::thread::hardware_concurrency();
void  findEven(ull starting_num, ull ending_num) {
	for (ull i = starting_num; i <= ending_num; ++i) {
		if ((i & 1) == 0) {
			even_num_count += i;
		}
#if 0 // print out for keeping track of threads
		if (i % 1'000'000 == 0) {
			std::cout << "passed 1 million:" << i << std::endl;
		}
#endif
	}
}
void findOdd(ull starting_num, ull ending_num) {
	for (ull i = starting_num; i <= ending_num; ++i) {
		if ((i & 1) == 1) {
			odd_num_count += i;
		}
#if 0 // print out for keeping track of threads
		if (i % 1'000'000 == 0) {
			std::cout << "passed 1 million:" << i << std::endl;
		}
#endif
	}

}

int main() {
	
	auto startTime = std::chrono::high_resolution_clock::now();
	size_t processor_count = std::thread::hardware_concurrency(); // get the total amount of avaliable threads on the current machine
	std::vector<std::thread> thread_vec;

	for (size_t i = 0; i < processor_count; i++)
	{
		if (i % 1 == 0) 
			thread_vec.push_back(std::thread(findOdd, START, END));
		else 
			thread_vec.push_back(std::thread(findEven, START, END));
	}

	for (size_t i = 0; i < thread_vec.size(); i++)
		thread_vec[i].join();
	

	auto stopTime = std::chrono::high_resolution_clock::now();
	auto duration =std::chrono::duration_cast<std::chrono::milliseconds> (stopTime - startTime);
	std::cout << "Total Time elapsed during operations: " << std::to_string(duration.count()) << "ms" << std::endl;
	std::cout << "Odd Number Count: " << odd_num_count << std::endl;
	std::cout << "Even Number Count: " << even_num_count << std::endl;



	return 0;
}