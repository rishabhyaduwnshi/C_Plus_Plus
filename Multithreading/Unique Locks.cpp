#include <iostream>
#include <thread>
#include <mutex>

std::mutex my_mutex;
int buffer = 1;

void incrementBuffer(int thread_id, int n)
{
	//automatically calls lock on the mutex, we don't need to explicitly lock it.
	std::unique_lock <std::mutex> lock(my_mutex);
	for (int i = 1; i <= n; i++)
		std::cout << "Thread ID : " << thread_id << std::endl<< "Current Buffer Value : " << buffer++ << std::endl;
	
	//unlocking of the mutex happens automatically in the destructor
}

int main()
{
	std::thread t1(incrementBuffer, 1, 10);
	std::thread t2(incrementBuffer, 2, 10);

	t1.join();
	t2.join();
}
