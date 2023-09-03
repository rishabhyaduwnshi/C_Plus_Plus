#include <iostream>
#include <thread>
#include <chrono>

void printHello()
{
	while (true)
		std::cout << "Hello ";
}

void printWorld()
{
	while (true)
		std::cout << "World ";
}

int main()
{
	std::thread t1(printHello);
	std::thread t2(printWorld);

	t1.detach();
	t2.detach();

	std::this_thread::sleep_for(std::chrono::seconds(1));
}

