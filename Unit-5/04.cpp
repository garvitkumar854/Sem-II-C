// Function Overriding
/* Runtime Polymorphism: 
Means redefining a function of the base class in the derived class with the same 
function name, same parameter list, and same return type.
*/
#include <iostream>
using namespace std;

// Type 1
class A{
public:
    void show(){
        cout << "I'm Base" << endl;
    }
};

class B: public A{
public:
    void show(){
        cout << "I'm Derived" << endl;
    }
};

// Type 2
class AA{
public:
    virtual void show(){
        cout << "I'm Base" << endl;
    }
};

class BB: public AA{
public:
    void show(){
        cout << "I'm Derived" << endl;
    }
};




int main(){
    // ---TYPE 1---
    cout << "------TYPE 1------\n"<< endl; 
    B b1;
    b1.show();      // Derived one
    B b2;
    b2.A::show();       // Base one


    // ---TYPE 2---
    cout << "\n------TYPE 2------\n"<< endl; 
    AA* ptr;            // Pointer to the all objects of AA Class
    BB d;
    ptr = &d;
    ptr->show();



    return 0;
}