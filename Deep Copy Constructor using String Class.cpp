#include <iostream>
#include <cstring>
using namespace std;

class String {
private:
    char* array;
    int length;

public:
    String(const char* str = NULL) 
    {
        length = strlen(str);
        array = new char[length + 1];
        strcpy(array, str);
    }

    // Copy Constructor (Deep Copy)
    String(const String& other) 
    {
        length = other.length;
        array = new char[length + 1];
        strcpy(array, other.array);
    }

    void change() {
        int index = 0;
        while (array[index] != '\0') {
            array[index] = 'x';
            index++;
        }
    }

    void print() {
        cout << array << " " << endl;
    }

    ~String() {
        delete[] array;
        cout << "\nDeleted Object";
    }
};

int main() {
    String str1 = "Rishabh";
    String str2 = str1;

    cout << "before calling change function \n"<<endl;

    str1.print();
    str2.print();

    str2.change();

    cout << "\nafter calling change function \n"<<endl;

    str1.print();
    str2.print();

    return 0;
}
