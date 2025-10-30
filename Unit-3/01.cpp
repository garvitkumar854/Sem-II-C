// Function Overloading
#include <iostream>
using namespace std;

void add(int a, int b) {
    cout << "Sum (int): " << a + b << endl;
}

void add(double a, double b) {
    cout << "Sum (double): " << a + b << endl;
}

void add(int a, double b){
    cout << "Sum (int, double): " << a + b << endl;
}

void add(double a, int b){
    cout << "Sum (double, int): " << a + b << endl;
}

int main() {
    add(2, 3);        // calls int version
    add(2.5, 3.5);    // calls double version
    add(2, 3.5);    // calls int, double version
    add(2.5, 3);    // calls double, int version
    return 0;
}
