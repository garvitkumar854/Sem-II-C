# Unit I

## 1️⃣ What is Object-Oriented Programming (OOP)?

OOP = Programming paradigm based on objects (real-world entities) that contain data and functions.

### 4 Main Principles of OOPS

| Concept           | Meaning                                           | Example                                         |
| ----------------- | ------------------------------------------------- | ----------------------------------------------- |
| **Encapsulation** | Binding data + functions together                 | Class with private data and public functions    |
| **Abstraction**   | Hiding complexity; showing only essential details | Using class methods without knowing inner logic |
| **Inheritance**   | Acquiring properties of another class             | `class Car : public Vehicle {}`                 |
| **Polymorphism**  | One interface, many forms                         | Function Overloading / Virtual functions        |

#### Advantages:

- Code reusability
- Maintainability
- Real-world modeling
- Security (data hiding)

## 2️⃣ Classes and Objects

🔹 Class

- A user-defined data type.
- Contains data members (variables) and member functions (methods).
  🔹 Object
- An instance of a class.
- Has memory allocated when created.
  Syntax Example:

```cpp
#include <iostream>
using namespace std;

class Student {
private:
    int roll;
    string name;
public:
    void input() {
        cout << "Enter Roll and Name: ";
        cin >> roll >> name;
    }
    void display() {
        cout << "Roll: " << roll << ", Name: " << name << endl;
    }
};

int main() {
    Student s1;   // Object creation
    s1.input();
    s1.display();
    return 0;
}
```

##### Key Points:

- Use . (dot operator) to access members.
- Class defines structure; object uses it.

## 3️⃣ Encapsulation

Encapsulation = **Data hiding** + **Data protection**
→ Keep data private, expose through public functions.
<br>
Example:

```cpp
class Account {
private:
    double balance;
public:
    void deposit(double amount) { balance += amount; }
    double getBalance() { return balance; }
};
```

## 4️⃣ Polymorphism

Poly = many, morph = form → Same function behaves differently
Two types:

1. Compile-time (Static)

- unction Overloading
- perator Overloading

2. Run-time (Dynamic)

- Virtual functions
- Function overriding (Inheritance)

Example:

```cpp
class Math {
public:
    int add(int a, int b) { return a + b; }
    double add(double a, double b) { return a + b; }
};
```

## 5️⃣ Inheritance (Intro)

Allows a **class to use properties of another.**
<br>

Syntax

```cpp
class Derived : public Base { };
```

Example:

```cpp
class A {
public:
    void displayA() { cout << "Class A" << endl; }
};

class B : public A {
public:
    void displayB() { cout << "Class B" << endl; }
};

int main() {
    B obj;
    obj.displayA();  // Inherited
    obj.displayB();
}
```

✅ Types of Inheritance:

- Single
- Multiple
- Multilevel
- Hierarchical
- Hybrid

## 6️⃣ Control Structures (Basics in C++)

- **If / else**
- **Switch**
- **Loops:** `for`, `while`, `do-while`
- **Break / continue**

## 7️⃣ Functions

### Function Prototyping

#### Definition:

A function prototype tells the compiler the name, return type, and parameter types before the function is actually defined.
<br>Syntax

```cpp
return_type function_name(parameter_list);
```

### Call and Return by Reference

#### Call by Reference:

When a function receives a reference (address) of a variable — changes inside the function affect the original variable.
<br>Example

```cpp
#include <iostream>
using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int x = 5, y = 10;
    swap(x, y);
    cout << x << " " << y; // Output: 10 5
}
```

### Inline Functions

A function declared as inline tells the compiler to insert its code directly at the point of call (avoids function call overhead).

```cpp
#include <iostream>
using namespace std;

inline int square(int n) {
    return n * n;
}

int main() {
    cout << square(4); // Output: 16
}
```

### Default Arguments

Provides default values for parameters that are automatically used if no argument is passed during the call.

```cpp
#include <iostream>
using namespace std;

void display(string name = "Guest") {
    cout << "Welcome, " << name << endl;
}

int main() {
    display();           // Uses default: Guest
    display("Garvit");   // Overrides default
}
```

### Const Arguments

Declaring parameters as const prevents modification of their value inside the function.

```cpp
void print(const int x) {
    // x++; ❌ Not allowed
    cout << x;
}
```

### Friend Functions

A non-member function that can access private and protected members of a class.

```cpp
#include <iostream>
using namespace std;

class Box {
private:
    int length;
public:
    Box(int l) : length(l) {}
    friend void show(Box);  // friend declaration
};

void show(Box b) {
    cout << "Length = " << b.length;
}

int main() {
    Box b1(10);
    show(b1);
}
```

✅ Key Points:

- Declared with friend keyword inside class
- Not called using object (normal call)
- Breaks encapsulation — use carefully

### Friend Classes

One class can be made a friend of another, giving it access to private members.

```cpp
class B;  // forward declaration

class A {
private:
    int data = 10;
    friend class B;   // B is friend
};

class B {
public:
    void show(A obj) {
        cout << obj.data;
    }
};

int main() {
    A a;
    B b;
    b.show(a);
}
```

✅ Key Points:

- friend class allows all functions of B to access A’s private data
- Often used for tight cooperation between two related classes

### Static Data Members

A data member declared as static is shared by all objects of the class (only one copy exists).

```cpp
#include <iostream>
using namespace std;

class Counter {
public:
    static int count;
    Counter() { count++; }
};

int Counter::count = 0; // Definition outside class

int main() {
    Counter a, b, c;
    cout << Counter::count; // Output: 3
}
```

✅ Key Points:

- Shared by all objects
- Declared inside class, defined outside
- Useful for counting objects or shared values

### Static Member Functions

A function declared as static can be called without an object and can access only static data members.

```cpp
#include <iostream>
using namespace std;

class Test {
    static int x;
public:
    static void show() {
        cout << "x = " << x;
    }
};

int Test::x = 50;

int main() {
    Test::show();  // Called without object
}
```

✅ Key Points:

- Can access only static data
- Can be called using ClassName::function()
- Used for utility or class-level operations

### Nested Classes

A class defined inside another class.

```cpp
class Outer {
public:
    class Inner {
    public:
        void show() {
            cout << "Inner class function";
        }
    };
};

int main() {
    Outer::Inner obj;
    obj.show();
}
```

✅ Key Points:

- Useful for grouping related logic
- Inner class is independent of the outer class objects
- Access control can be managed using public / private
