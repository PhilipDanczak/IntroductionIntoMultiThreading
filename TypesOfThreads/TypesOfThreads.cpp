#include <iostream>
#include <thread>

//Types of threads that can be constructed
//1. Function
void func(int x) {
	std::cout << "Function Thread" << std::endl;
	while (x-- > 0) {
		std::cout << x << std::endl;
	}
}
//2. lamdba expression
	auto lambda_func = [](int x) {
		std::cout << "Lambda Expression Thread" << std::endl;
		while (x-- > 0) {
			std::cout << x << std::endl;
		}
	};

//3. Functor
	class BaseClass {
	public:
		void operator()(int x) {
			std::cout << "Functor Thread" << std::endl;
			while (x-- > 0) {
				std::cout << x << std::endl;
			}
		}
	};
//4. Non-static member function
	class NSBaseClass {
	public:
		void run(int x) {
			std::cout << "Non-Static Class Member Thread" << std::endl;
			while (x-- > 0) {
				std::cout << x << std::endl;
			}
		}
	};
	//5. static member function
	class SBaseClass {
	public:
		static void run(int x) {
			std::cout << "Static Class Member Thread" << std::endl;
			while (x-- > 0) {
				std::cout << x << std::endl;
			}
		}
	};
	int main() {
		//Join all threads
		std::thread t1(func, 10);
		t1.join();
		std::thread t2(lambda_func, 10);
		t2.join();
		std::thread t3(BaseClass(), 10);
		t3.join();
		NSBaseClass ns;
		std::thread t4(&NSBaseClass::run, &ns, 10);
		t4.join();
		std::thread t5(&SBaseClass::run, 10);
		t5.join();
		
		return EXIT_SUCCESS;
	}

