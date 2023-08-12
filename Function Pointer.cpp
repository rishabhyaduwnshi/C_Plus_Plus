#include <bits/stdc++.h>
using namespace std;

void display()
{
    cout<<"Display Function";
}

int add(int x, int y)
{
    return x+y;
}


int main()
{
    //declaration
    void(*fp)(); //since return type of display Function was void
    
    //initilisation
    fp = display; 
    
    //calling
    //second brances is used for passing parameter
    //since in original Function dosent take any parameter , so it, empty
    (*fp)(); 
    
    //calling add Function
    
    //declaration
    int(*fp_add)(int,int);
    
    //initilisation
    fp_add = add;
    
    int result = (*fp_add)(10,20);
    
    cout<<endl<<result;
    
}
