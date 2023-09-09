#include <iostream>
#include <thread>
#include <mutex>

std::mutex my_mutex;
int buffer = 1;

void incrementBuffer(int thread_id, int n)
{
	//defer lock
	//try_to_lock
	//adopt lock

	//in case of defer_lock, mutex only acquires the lock but not locks it, so we have explicitially lock the mutex
	std::unique_lock <std::mutex> lock(my_mutex,std::defer_lock);
	my_mutex.lock();
	for (int i = 1; i <= n; i++)
		std::cout << "Thread ID : " << thread_id << std::endl<< "Current Buffer Value : " << buffer++ << std::endl;
	//unlocking off the mutex happens automaticaly
}

int main()
{
	std::thread t1(incrementBuffer, 1, 10);
	std::thread t2(incrementBuffer, 2, 10);

	t1.join();
	t2.join();
}
