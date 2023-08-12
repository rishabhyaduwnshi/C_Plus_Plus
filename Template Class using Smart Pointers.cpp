#include <bits/stdc++.h>
using namespace std;

template<class T> class SmartPointer
{
    private:
        T *ptr; //actual pointer 
        
    public:
        explicit SmartPointer(T *ptr = nullptr)
        {
            this->ptr = ptr;   
        }
        
        ~SmartPointer()
        {
            delete ptr;
        }
        
        T& operator *()
        {
            return *ptr;
        }
        
        T* operator ->()
        {
            return ptr;
        }
};

int main()
{
    SmartPointer<int> sp(new int());
    *sp = 20;
    cout<<*sp;
}
