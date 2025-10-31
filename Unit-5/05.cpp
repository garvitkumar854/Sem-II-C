// Virtual Base Classes

#include <iostream>
using namespace std;

class A {
public:
    int x = 10;
};

class B : virtual public A {
public: 
    int y = 20;
};
class C : virtual public A {};

class D : public B {};
class E : public C {};

class F : public D, public E {};


int main() {
    F obj;
    cout << obj.x << endl;  // No ambiguity, only one copy of A
    cout << obj.y << endl;
    return 0;
}
