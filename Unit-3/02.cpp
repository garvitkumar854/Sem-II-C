// Constructor Overloading
#include <iostream>
using namespace std;

class Box{
    int length, width;
public: 
    // Default Constructor
    Box(){
        length = width = 0;
    }

    // Parameterized Constructor
    Box(int l, int w){
        length = l;
        width = w;
    }

    // Function to print the values
    void show(){
        cout << "Length: " << length << "\nWidth: " << width << endl;
    }
};

int main(){
    Box b1;
    b1.show();
    Box b2(3, 4);
    b2.show();
    return 0;
}