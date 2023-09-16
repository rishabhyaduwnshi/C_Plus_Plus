#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

std::condition_variable cv;
std::mutex my_mutex;
long current_balance = 0;

void add_money(int amount)
{
	my_mutex.lock();
	current_balance += amount;
	std::cout << "Current Balance after adding the money " << current_balance << std::endl;
	my_mutex.unlock();
	cv.notify_one();
}


void withdraw_money(int amount)
{
	std::unique_lock<std::mutex> ul(my_mutex);
	cv.wait(ul, [] { if (current_balance == 0) return false; else return true; });

	if (current_balance >= amount)
	{
		current_balance -= amount;
		std::cout << "Amount Withdrawn\n";
		std::cout << "Current Balance : " << current_balance << std::endl;
	}
	else
	{
		std::cout << "Insufficeint Balance\n";
	}
}


int main()
{
	std::thread t1(add_money, 500);
	std::thread t2(withdraw_money, 500);

	t1.join();
	t2.join();

	return 0;

}
