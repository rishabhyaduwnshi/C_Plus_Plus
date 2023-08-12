#include<bits/stdc++.h>
using namespace std;

class SmartPointer
{
    private:
        int *data;
    public:
        
        //constructor
        explicit SmartPointer(int *ptr = nullptr)
        {
            data = ptr;
        }
        
        //destructor
        ~SmartPointer()
        {
            delete data;
            cout<<"Destructor called";
        }
        
        //overloading dereferencing operator
        int & operator *()
        {
            return *data;
        }
};


int main()
{
    int *ptr = new int(10);
    SmartPointer sp = SmartPointer(ptr);
    cout<<*sp<<" \n";
}
