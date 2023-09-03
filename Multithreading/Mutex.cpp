#include <iostream>
#include <thread>
#include <mutex>

int money = 0;
std::mutex m;

void incrementMoneyBy1()
{
	//lock the critical section before entering so that no other thread can enter
	m.lock();

	//critical section
	money++;

	//unlock the critical section before after permorming operations
	m.unlock();
}

int main()
{
	std::thread t1(incrementMoneyBy1);
	std::thread t2(incrementMoneyBy1);

	t1.join();
	t2.join();

	std::cout << money << std::endl;

}
