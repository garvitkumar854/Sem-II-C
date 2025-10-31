#include <iostream>
using namespace std;

class Base {
    int x = 10;
    friend class Derived;
};

class Derived {
public:
    void show(Base b) { cout << b.x; } // allowed (friend)
};

int main() {
    Base b;
    Derived d;
    d.show(b); // Output: 10
    return 0;
}