#include <iostream>
#include <thread>

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

	t1.join();
	t2.join();

}

