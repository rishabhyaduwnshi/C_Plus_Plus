#include <bits/stdc++.h>
using namespace std;

namespace mySpace
{
    int x;
    int y;
    
    class Dummy
    {
        public:
            int a;
            int b;
    };
}


int main()
{
    mySpace::x = 10;
    mySpace::y = 20;
    
    mySpace::Dummy d;
    d.a = 5;
    d.b = 10;
    
    cout<<d.a<<" "<<d.b<<" ";
    
}
