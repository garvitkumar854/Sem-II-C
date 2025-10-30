# Unit 5

## 1️⃣ – What is Inheritance?

**Inheritance** allows one class (derived class) to acquire the properties and behaviors of another class (base class).
<br>
Syntax:

```cpp
class Derived : access_specifier Base {
   // additional members
};
```

✅ Key Points:

- Promotes code reusability.
- Enables hierarchical class structures.
- Supports polymorphism.

### Types of Inheritance

C++ supports five main types of inheritance:
| Type | Diagram | Description |
| ---------------- | ------------ | --------------------------------------------------------- |
| 1️⃣ Single | A → B | One base class, one derived class |
| 2️⃣ Multiple | A,B → C | One derived class inherits from multiple base classes |
| 3️⃣ Multilevel | A → B → C | Derived class becomes base for another class |
| 4️⃣ Hierarchical | A → B, A → C | Multiple derived classes inherit from one base class |
| 5️⃣ Hybrid | Combination | Mixture of two or more types (like multiple + multilevel) |

<img src = "https://www.w3schools.in/wp-content/uploads/2014/07/inheritanc-cpp.jpg" width=700px>

#### Single Inheritance

One derived class inherits from one base class.

**Example:**

```cpp
#include <iostream>
using namespace std;

class Parent {
public:
    void showParent() { cout << "This is Parent class\n"; }
};

class Child : public Parent {
public:
    void showChild() { cout << "This is Child class\n"; }
};

int main() {
    Child c;
    c.showParent();
    c.showChild();
}
```

**✅ Output:**

```python
This is Parent class
This is Child class
```

#### Multiple Inheritance

One derived class inherits from two or more base classes.

**Example:**

```cpp
#include <iostream>
using namespace std;

class A {
public:
    void showA() { cout << "Class A\n"; }
};

class B {
public:
    void showB() { cout << "Class B\n"; }
};

// Derived from both A and B
class C : public A, public B {
public:
    void showC() { cout << "Class C\n"; }
};

int main() {
    C obj;
    obj.showA();
    obj.showB();
    obj.showC();
}
```

**✅ Output:**

```vbnet
Class A
Class B
Class C
```

#### Multilevel Inheritance

A derived class acts as a base for another derived class.

**Example:**

```cpp
#include <iostream>
using namespace std;

class A {
public:
    void showA() { cout << "Base Class A\n"; }
};

class B : public A {
public:
    void showB() { cout << "Derived Class B\n"; }
};

class C : public B {
public:
    void showC() { cout << "Derived Class C\n"; }
};

int main() {
    C obj;
    obj.showA();
    obj.showB();
    obj.showC();
}
```

**✅ Output:**

```vbnet
Base Class A
Derived Class B
Derived Class C
```

#### Hierarchical Inheritance

One base class is inherited by multiple derived classes.

**Example:**

```cpp
#include <iostream>
using namespace std;

class Animal {
public:
    void eat() { cout << "Eating...\n"; }
};

class Dog : public Animal {
public:
    void bark() { cout << "Barking...\n"; }
};

class Cat : public Animal {
public:
    void meow() { cout << "Meowing...\n"; }
};

int main() {
    Dog d;
    d.eat();
    d.bark();

    Cat c;
    c.eat();
    c.meow();
}
```

**✅ Output:**

```txt
Eating...
Barking...
Eating...
Meowing...
```

#### Hybrid Inheritance

Combination of two or more types (e.g. multiple + multilevel).<br>
This often leads to **ambiguity** if both `B` and `C` inherit from the same base `A` and then `D` inherits from both `B` and `C`.
To solve this, we use virtual base classes.

**Example:**

```cpp
#include <iostream>
using namespace std;

class A {
public:
    void showA() { cout << "Class A\n"; }
};

class B : virtual public A { };
class C : virtual public A { };

class D : public B, public C { };

int main() {
    D obj;
    obj.showA();   // No ambiguity due to virtual inheritance
}

// Output: Class A
```

## 2️⃣ – Base-Class Access Control

Access specifiers control how base class members are inherited.

| Access in Base | `public` inheritance | `protected` inheritance | `private` inheritance |
| -------------- | -------------------- | ----------------------- | --------------------- |
| `public`       | public in derived    | protected in derived    | private in derived    |
| `protected`    | protected in derived | protected in derived    | private in derived    |
| `private`      | not accessible       | not accessible          | not accessible        |

Example:

```cpp
class Base {
public: int a;
protected: int b;
private: int c;
};

class Derived : public Base {
    // a → public, b → protected, c → not accessible
};
```

✅ Commonly used:
`public` inheritance → "is-a" relationship.
Example: `Car` is a `Vehicle`.

## 3️⃣ – Inheritance and Protected Members

Protected members of a base class are accessible only within:

- The base class itself.
- Any **derived class** (but not from outside).

```cpp
#include <iostream>
using namespace std;

class Base {
protected:
    int value;
public:
    Base(int v) { value = v; }
};

class Derived : public Base {
public:
    Derived(int v) : Base(v) {}
    void show() { cout << "Value = " << value; } // accessible
};

int main() {
    Derived d(10);
    d.show();
}
```

✅ Key Point: `protected` = like `private` outside the class, but accessible inside derived classes.

## 4️⃣ – Protected Base-Class Inheritance

When a class is inherited using `protected`, both public and protected members of base class become protected in the derived class.

```cpp
class A {
public: int x;
protected: int y;
};

class B : protected A {
public:
    void show() { cout << x << " " << y; } // both accessible
};

int main() {
    B obj;
    // obj.x; ❌ Error - becomes protected in B
}
```

✅ Use case: When you want derived classes to use base features, but `don’t expose them publicly`.

## 5️⃣ – Inheriting Multiple Base Classes

C++ supports multiple inheritance, meaning a class can inherit from `more than one base class`.<br>
Syntax:

```cpp
class Derived : public Base1, public Base2 {
    // members
};
```

Example:

```cpp
#include <iostream>
using namespace std;

class A { public: void showA() { cout << "A "; } };
class B { public: void showB() { cout << "B "; } };
class C : public A, public B {
public: void showC() { cout << "C"; }
};

int main() {
    C obj;
    obj.showA();
    obj.showB();
    obj.showC();
}
```

✅ Output: A B C

✅ Key Points:

- If both base classes have same function name, ambiguity occurs.
  Use `scope resolution` (e.g., `A::display();`).
- Common problem: `Diamond problem` → solved by `virtual base classes` (explained later).

## 6️⃣ – Constructors, Destructors, and Inheritance

Rules:

- **Base class constructors** are called first, then **derived class** constructors.
- **Destructor**s are called in reverse order.

```cpp
#include <iostream>
using namespace std;

class Base {
public:
    Base() { cout << "Base Constructor\n"; }
    ~Base() { cout << "Base Destructor\n"; }
};

class Derived : public Base {
public:
    Derived() { cout << "Derived Constructor\n"; }
    ~Derived() { cout << "Derived Destructor\n"; }
};

int main() {
    Derived obj;
}
```

✅ Output:

```txt
Base Constructor
Derived Constructor
Derived Destructor
Base Destructor
```

✅ Key Point: Always ensure base destructors are virtual if base pointers delete derived objects.

## 7️⃣ – When Constructors and Destructors Are Executed

**Execution Order:**

- Constructors:
  `→ Base → Derived`

- Destructors:
  `→ Derived → Base`

If multiple inheritance is used:
→ Constructors executed left to right (based on inheritance list).

```cpp
class A { public: A() { cout<<"A "; } };
class B { public: B() { cout<<"B "; } };
class C : public A, public B { public: C() { cout<<"C"; } };
```

✅ Output: A B C

## 8️⃣ – Passing Parameters to Base-Class Constructors

Derived class constructors can pass arguments to base class constructors using an **initializer list**.

```cpp
#include <iostream>
using namespace std;

class Base {
    int a;
public:
    Base(int x) { a = x; cout << "Base " << a << endl; }
};

class Derived : public Base {
    int b;
public:
    Derived(int x, int y) : Base(x) { b = y; cout << "Derived " << b << endl; }
};

int main() {
    Derived d(5, 10);
}
```

✅ Output:

```nginx
Base 5
Derived 10
```

✅ Key Point:

- You must use member initializer list for calling parameterized base constructors.
- If not explicitly called, default constructor of base runs automatically.

## 9️⃣ – Granting Access (Friendship and Protected)

A derived class cannot automatically access private members of base class.
To give access:

- Declare base members as protected (for inheritance access), or
- Use a friend class/function.

```cpp
class Base {
    int x = 10;
    friend class Derived;
};

class Derived {
public:
    void show(Base b) { cout << b.x; } // allowed (friend)
};
```

✅ Key Point:

- Friendship is not inherited.
- A friend function can access private/protected data of a class.

## 🔟 – Virtual Base Classes

Used to solve diamond (ambiguity) problem in multiple inheritance.

**Problem Example:**

```cpp
class A { public: int x; };
class B : public A { };
class C : public A { };
class D : public B, public C { };
```

Here D inherits x twice (once via B, once via C).

**Solution → Use Virtual Base Class**

```cpp
class A { public: int x; };
class B : virtual public A { };
class C : virtual public A { };
class D : public B, public C { };

int main() {
    D obj;
    obj.x = 10;   // no ambiguity
}
```

✅ Key Points:

- Declared using keyword virtual before public.
- Ensures only one copy of base class members exists.
- Prevents data duplication in multiple inheritance.
