// Multithreading Introduction.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <chrono>
#include <thread>

typedef unsigned long long ull;

ull even_sum = 0;
ull odd_sum = 0;

void find_odd_sum(ull start, ull end)
{
    for (ull i = start; i < end; i++)
    {
        if (i % 2 == 1)
            odd_sum += i;
    }
}


void find_even_sum(ull start, ull end)
{
    for (ull i = start; i < end; i++)
    {
        if (i % 2 == 0)
            even_sum += i;
    }
}

int main()
{
    ull start = 0;
    ull end = 1000000000;

    //get the time before starting the calculation
    auto start_time = std::chrono::high_resolution_clock::now();
    
    find_odd_sum(start, end);
    find_even_sum(start, end);

    //get the time after completing the calculation
    auto end_time = std::chrono::high_resolution_clock::now();

    //find the duration
    auto duration = std::chrono::duration_cast<std::chrono::duration<double>>(end_time - start_time);

    //even & odd sum results
    std::cout <<"Odd sum is : " << odd_sum <<std::endl;
    std::cout <<"Even sum is : " << even_sum << std::endl;

    //print the duration
    std::cout <<"Time required for this compuation was : " << duration.count() << std::endl;

}
