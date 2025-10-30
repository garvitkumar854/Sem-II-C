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

## 3️⃣ – Creating Prefix and Postfix Forms of ++ / --

You can overload increment (++) and decrement (--) in two forms:

- Prefix form: `++obj`
- Postfix form: `obj++`

```cpp
#include <iostream>
using namespace std;

class Counter {
    int value;
public:
    Counter(int v = 0) { value = v; }

    // Prefix (++obj)
    Counter operator ++() {
        ++value;
        return *this;
    }

    // Postfix (obj++)
    Counter operator ++(int) {
        Counter temp = *this;
        value++;
        return temp;
    }

    void show() { cout << value << endl; }
};

int main() {
    Counter c1(5);
    ++c1;     // prefix
    c1.show();   // Output: 6

    c1++;     // postfix
    c1.show();   // Output: 7
}
```

## 4️⃣ – Operator Overloading Restrictions

🚫 Operators that CANNOT be overloaded:

```cpp
.   (dot)
.*  (pointer to member)
::  (scope resolution)
?:  (ternary conditional)
sizeof
typeid
```

⚠️ Also note:

- You cannot create new operators, only overload existing ones.
- Overloading does not change operator precedence or associativity.
- Overloaded operators must involve at least one user-defined type (you can’t overload purely built-in types like `int` +` int`).

## 5️⃣ – Operator Overloading Using a Friend Function

When the left-hand operand of an operator is not an object (e.g., `2 + obj`), you must use a friend function.

```cpp
#include <iostream>
using namespace std;

class Complex {
    int real, imag;
public:
    Complex(int r = 0, int i = 0) { real = r; imag = i; }

    friend Complex operator + (Complex c1, Complex c2);
};

Complex operator + (Complex c1, Complex c2) {
    return Complex(c1.real + c2.real, c1.imag + c2.imag);
}

int main() {
    Complex a(2,3), b(1,4), c;
    c = a + b;
}
```

✅ Key Points:

- Friend function is declared inside class with keyword `friend`.
- It is **not called using object** (no `this` pointer).
- Both operands are passed as arguments.

## 6️⃣ – Using Friend to Overload ++ or --

```cpp
#include <iostream>
using namespace std;

class Count {
    int value;
public:
    Count(int v = 0) { value = v; }

    friend Count operator ++ (Count &obj); // prefix
    friend Count operator ++ (Count &obj, int); // postfix
};

Count operator ++ (Count &obj) {   // prefix
    obj.value++;
    return obj;
}

Count operator ++ (Count &obj, int) { // postfix
    Count temp = obj;
    obj.value++;
    return temp;
}
```

✅ Key Points:

- Friend functions require the object to be passed as argument.
- Prefix and postfix are differentiated using `int` dummy parameter.

## 7️⃣ – Overloading [ ] (Subscript Operator)

Allows using array-style indexing on objects.

```cpp
#include <iostream>
using namespace std;

class Array {
    int arr[5];
public:
    Array() { for(int i=0;i<5;i++) arr[i]=i+1; }

    int operator[](int index) {
        return arr[index];
    }
};

int main() {
    Array a;
    cout << a[2];   // Output: 3
}
```

✅ Key Points:

- Must take `one argument (index)`.
- Can return `reference` if you want to modify element (e.g., `a[2] = 10;`).
- Usually defined as member function.

## 8️⃣ – Overloading ( ) (Function Call Operator)

Allows objects to be **called like functions**.
Very useful in functor or **function-object** concepts.

```cpp
#include <iostream>
using namespace std;

class Multiply {
public:
    int operator()(int a, int b) {
        return a * b;
    }
};

int main() {
    Multiply m;
    cout << m(3, 4);   // Output: 12
}
```

✅ Key Points:

- `operator()` can take any number of arguments.
- Commonly used in STL functors.
- Must be defined as **member function**.
