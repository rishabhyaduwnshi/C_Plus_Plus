#include <bits/stdc++.h>
using namespace std;

void signal_handler(int signal_number)
{
    cout<<"Given signal number is "<<signal_number;
    exit(signal_number);
}


int main()
{
    signal(SIGABRT,signal_handler);
    while(true)
    {
        cout<<"Rishabh";
    }
}
