#include <stdio.h>

int main()
{
    //integer pointer
    int a = 10;
    int *ptr_a = &a;
    
    //constant pointer -> it will store the address of normal integer type variable only
    //but once it's done, it cannot point to any other memory address
    int b = 20;
    int c = 30;
    int *const ptr_b = &b;
    
    //this will throw error, becuase we cannot modify the memory address a const pointer is holding
    //ptr_b = &c;
    
    
    //pointer to an integer constant
    const int d = 40;
    //int *ptr_d = &d; //this will give compilation warning but still it's value can be changed
    
    //changing value of d which is constant
    //*ptr_d = 80;
    //printf("%d ",*ptr_d);
    
    //In this case the value pointer is holding cannot be modified
    // but the memory address where pointer is pointing can be chnaged
    const int e = 50;
    const int f = 60;
    const int *ptr_e;
    ptr_e = &e;
    ptr_e = &f; //changing the memory address where ptr_e is pointing
    
    //constant pointer to a constant variable
    const int g = 70;
    const int h = 80;
    const int *const ptr_g = &g; //in this case, neither the memory, nor value cannot be modified
    
    //changing value
    *ptr_g = 100; //error
    
    //changing address
    ptr_g = &h; //error
    
}
