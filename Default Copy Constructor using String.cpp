#include<bits/stdc++.h>
using namespace std;

class String
{
    private:
        char *array;
        int length;
        
    public:
        String(const char* str=NULL)
        {
            length = strlen(str);
            array = new char[length+1];
            strcpy(array,str);
        }
        
        void change ()
        {
            int index = 0;
            while(array[index] != '\0')
            {
                array[index] = 'x';
                index++;
            }
        }
        
        void print()
        {
            cout<<array<<" "<<endl;
        }
        
        ~String()
        {
            delete array;
            cout<<"\nDeleted Object";
        }
};

int main()
{
    String str1 = "Rishabh";
    String str2 = str1;
    
    cout<<"before calling change function \n";
    
    str1.print();
    str2.print();
    
    // changing only str2 but it will also reflect in str1, this is shallow copy, this constructor is given by compiler
    // if we don't write our owm copy constructor, this will happen
    str2.change(); 
    
    cout<<"after calling change function \n";
    
    str1.print();
    str2.print();

  //since both the objects are pointing to same memory location and we have created a destructor as well,
  // once the first object goes out of scope, it'll call destructor and meory gets freed but for the second object it is already freed
  // so when the destructor gets called for second time, it will give free(): double free detected in tcache 2 warning.
    
}
