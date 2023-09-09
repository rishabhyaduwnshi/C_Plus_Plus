#include <iostream>
#include <thread>
#include <mutex>

std::recursive_mutex rm;
int my_money = 0;

void increment(int thread_id, int loop_for)
{
	if (loop_for < 1)
		return;

	rm.lock();
	my_money++;
	std::cout << "Mutex locked by Thread : " << thread_id << std::endl;
	std::cout << "Current Money : " << my_money << std::endl;
	increment(thread_id, loop_for-1);
	rm.unlock();
	std::cout << "Mutex Unlocked by Thread : " << thread_id << std::endl;


}

int main()
{
	std::thread t1(increment, 1, 10);
	std::thread t2(increment, 2, 10);

	t1.join();
	t2.join();
}
