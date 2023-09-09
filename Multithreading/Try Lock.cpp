#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

int X = 0;
int Y = 0;

std::mutex mutex_m1, mutex_m2;

void doSomeWork(int second)
{
	std::this_thread::sleep_for(std::chrono::seconds(second));
}

void incrementXY(int &XorY, std::mutex &m, const char* desc)
{
	for (int i = 0; i < 5; i++)
	{
		m.lock();
		XorY++;
		std::cout << desc << XorY ;
		m.unlock();
		doSomeWork(1);
	}
}

void consumeXY()
{
	int use_count = 5;
	int XplusY = 0;
	while (true)
	{
		int lock_result = std::try_lock(mutex_m1, mutex_m2);
		if (lock_result == -1)
		{
			if (X != 0 && Y != 0)
			{
				use_count--;
				XplusY += X + Y;
				X = 0;
				Y = 0;
				std::cout <<" XplusY : "<< XplusY << std::endl;
			}

			mutex_m1.unlock();
			mutex_m2.unlock();

			if (use_count == 0)
				break;
		}
	}
}

int main()
{
	std::thread t1(incrementXY, std::ref(X), std::ref(mutex_m1), "X");
	std::thread t2(incrementXY, std::ref(Y), std::ref(mutex_m2), "Y");
	std::thread t3(consumeXY);

	t1.join();
	t2.join();
	t3.join();
}
