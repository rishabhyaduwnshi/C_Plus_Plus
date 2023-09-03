#include <iostream>
#include <thread>
#include <mutex>

int number = 0;
std::mutex my_mutex;

void incrementNumber()
{
	for(int i=0;i<100000;i++)
	{
		if (my_mutex.try_lock())
		{
     /* 
          This number might be equal to 200000 because some of the iterations might be skipped,
          If we had used lock instead of try_lock, in that case, it would have been 200000 for sure
      */
			number++;
			my_mutex.unlock();
		}
	}
	
}

int main()
{
	std::thread t1(incrementNumber);
	std::thread t2(incrementNumber);

	t1.join();
	t2.join();

	std::cout << number << std::endl;

}
