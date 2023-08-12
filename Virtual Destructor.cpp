#include <bits/stdc++.h>
using namespace std;

class Base 
{
public:
    //If we had not declared this virtual, then only base class destructor would be called
    // leading to the improper cleanup of an object
    virtual ~Base() 
    {
        cout<<"Base class Destructor \n";
    }
};

class Derived : public Base 
{
public:
    ~Derived()
    {
        cout<<"Derived class Destructor \n";
    }
};

int main() {
    Base* ptr = new Derived();
    delete ptr;  // This will call the Derived destructor via the virtual destructor of Base
    return 0;
}
