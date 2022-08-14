// JoinAndDetachWithJoinable.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <thread>
#include <chrono>

void run(int count) {
	while (count-- > 0) 
		std::cout << count << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(3000));
	std::cout << "End Thread" << std::endl;
}


int main()
{
	std::thread t1(run , 1230);
	std::cout << "Before First thread join" << std::endl;
	//std::this_thread::sleep_for(std::chrono::milliseconds(3000));
	t1.detach();
	std::cout << "After First thread join" << std::endl;
	if(t1.joinable()) t1.join();

	//t1.detach();
	return EXIT_SUCCESS;
}