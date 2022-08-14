// MutexThreadingDemo.cpp : This is meant to demostrate the use of mutal exclusion on multiple threads when accessing critical sections
//

#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>

int wallet_sum = 0;
std::mutex m;

void addMoney(int id ) {
	for (size_t i = 0; i < 6; i++)
	{
	m.lock();
	wallet_sum += 50;
	std::cout << "Thread:" << id << " added 50 dollars to the wallet" << std::endl;
	m.unlock();
	std::this_thread::sleep_for(std::chrono::milliseconds(300));
	}
}

int main()
{
	std::thread t1(addMoney,0);
	std::thread t2(addMoney,1);

	t1.join();
	t2.join();

	std::cout << "Current wallet sum:" << wallet_sum << std::endl;

}
