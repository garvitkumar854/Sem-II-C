// Virtual Base Class
#include <iostream>
using namespace std;

class A { public: int x; };
class B : virtual public A { };
class C : virtual public A { };
class D : public B, public C { };

int main() {
    D obj;
    obj.x = 10;   // no ambiguity
    // without virtual keyword there is ambiguity occurs
    
}