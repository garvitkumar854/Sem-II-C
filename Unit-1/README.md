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


