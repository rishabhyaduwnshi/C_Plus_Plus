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

class Rectangle
{
    private:
        int length;
        int breadth;
    public:
        Rectangle(int length = 0, int breadth = 0)
        {
            this->length = length;
            this->breadth = breadth;
        }
        
        int getArea()
        {
            return length*breadth;
        }
};

int main()
{
    SmartPointer<Rectangle> sp(new Rectangle(20,10));
    cout<<"Area of Rectangle is : "<<sp->getArea();
    
}
