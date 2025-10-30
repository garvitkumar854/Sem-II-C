// Multiple Inheritance
#include <iostream>
using namespace std;

class A {
public:
    void show(){ 
        cout << "Class A\n"; 
    }
};

class B {
public:
    void show(){ 
        cout << "Class B\n"; 
    }
};

// Derived from both A and B
class C : public A, public B {
public:
    void show(){
        A::show();
        B::show();
    }

};

int main() {
    C obj;
    obj.show();
}