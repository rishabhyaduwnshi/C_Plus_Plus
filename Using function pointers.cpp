#include <bits/stdc++.h>
using namespace std;

int add(int a, int b)
{
    return a+b;
}

int multiply(int a, int b)
{
    return a*b;
}

int invoke(int a, int b, int (*function)(int, int))
{
    return function(a,b);
}


int main()
{
    int x = 10;
    int y = 20;

    cout<<"Addition is "<<invoke(x,y,&add)<<endl;
    cout<<"Multiplication is "<<invoke(x,y,&multiply)<<endl;
}
