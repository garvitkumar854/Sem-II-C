# Unit 4

## 1️⃣ – What is Operator Overloading?

Operator overloading allows us to **redefine operators** (`+`, `-`, `++`, etc.) so they can work with **user-defined types (objects)**.

It is a form of **compile-time polymorphism**.

**Example (basic):**

```cpp
#include <iostream>
using namespace std;

class Complex {
    int real, imag;
public:
    Complex(int r = 0, int i = 0) { real = r; imag = i; }

    Complex operator + (Complex obj) {   // operator overloading
        Complex temp;
        temp.real = real + obj.real;
        temp.imag = imag + obj.imag;
        return temp;
    }

    void display() { cout << real << " + " << imag << "i\n"; }
};

int main() {
    Complex c1(2, 3), c2(4, 5);
    Complex c3 = c1 + c2;   // uses overloaded +
    c3.display();
}
```

✅ Output:

```cpp
6 + 8i
```

✅ Key Points:

- Syntax:

```cpp
return_type operator<symbol>(argument_list);
```

- Operator functions can be:
  - **Member functions** (using the calling object as left operand)
  - **Friend functions** (if you need access to private data)
- Overloading cannot change operator precedence or associativity.

## 2️⃣ – Creating a Member Operator Function

Member operator functions are defined inside the class using the keyword `operator`.

**General Syntax**

```cpp
class ClassName {
public:
    returnType operator op (argList) {
        // body
    }
};
```

**Example:**

```cpp
class Number {
    int n;
public:
    Number(int x) { n = x; }
    Number operator - (Number obj) {
        return Number(n - obj.n);
    }
    void show() { cout << n << endl; }
};
```

**✅ Usage:**

```cpp
Number n1(20), n2(5);
Number n3 = n1 - n2;
n3.show();  // Output: 15
```
