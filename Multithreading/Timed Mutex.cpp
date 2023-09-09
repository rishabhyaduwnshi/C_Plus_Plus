#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>


std::timed_mutex my_mutex;
int my_money = 0;

void increment(int thread_number)
{
	if (my_mutex.try_lock_for(std::chrono::seconds(1)))
	{
		my_money++;
		std::this_thread::sleep_for(std::chrono::seconds(2));
		std::cout << "Thread number : " << thread_number << " Entered\n";
		my_mutex.unlock();
	}
	else
	{
		std::cout << "Thread number : " << thread_number << " cound not enter\n";
	}

}

int main()
{
	std::thread t1(increment, 1);
	std::thread t2(increment, 2);

	t1.join();
	t2.join();

	std::cout << "Total Money is : " << my_money;
}
