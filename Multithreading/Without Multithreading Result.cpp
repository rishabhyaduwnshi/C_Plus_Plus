#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

ull odd_sum = 0;
ull even_sum = 0;

void evenSum(ull start, ull end)
{
    for(int i=start;i<end;i++)
    {
        if(i%2 == 0)
            even_sum += i;
    }
}

void oddSum(ull start, ull end)
{
    for(int i=start;i<end;i++)
    {
        if(i%2 != 0)
            odd_sum += i;
    }
}

int main()
{
    int start = 0;
    int end = 1000000000;
    
    //starting time 
    auto start_time = chrono::high_resolution_clock::now();

    evenSum(start,end);
    oddSum(start,end);
    
    //ending time
    auto end_time = chrono::high_resolution_clock::now();
    
    //duration
    auto duration = duration_cast<chrono::duration<double>>(end_time - start_time);
    
    cout<<"even_sum is "<<even_sum<<endl;
    cout<<"odd_sum is "<<odd_sum<<endl;
    cout << "Time elapsed: " <<duration.count()<<"seconds"<<endl;
    
}
