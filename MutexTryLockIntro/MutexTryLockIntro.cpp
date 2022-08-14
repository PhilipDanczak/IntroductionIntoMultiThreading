// MutexTryLockIntro.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <thread>
#include <mutex>

int counter = 0;
std::mutex mtx;

void increaseTheCounterBy10K() {
	for (size_t i = 0; i < 10'000; i++)
	{
		if (mtx.try_lock()) {
			counter++;
			mtx.unlock();
		}
	}
}


int main()
{
	std::thread t1(increaseTheCounterBy10K);
	std::thread t2(increaseTheCounterBy10K);
	t1.join();
	t2.join();

	std::cout << "Current counter value:" << counter << std::endl;
}

