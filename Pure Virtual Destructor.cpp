#include <bits/stdc++.h>
using namespace std;

class Base 
{
    public:
        virtual ~Base() = 0;  // Pure virtual destructor, helps in making the class abstract
};

Base::~Base() 
{
    // Destructor code for Base (can be empty if not needed)
}


class Derived : public Base 
{
    public:
        ~Derived() override {}
};

int main() 
{
    Base* ptr = new Derived();
    delete ptr;
    return 0;
}

