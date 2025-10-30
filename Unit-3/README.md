# Unit 3

## 1️⃣ – Function Overloading

Function overloading means having **multiple functions with the same name** but different parameter lists (number or type of parameters).

```cpp
#include <iostream>
using namespace std;

void add(int a, int b) {
    cout << "Sum (int): " << a + b << endl;
}

void add(double a, double b) {
    cout << "Sum (double): " << a + b << endl;
}

int main() {
    add(2, 3);        // calls int version
    add(2.5, 3.5);    // calls double version
}
```

✅ Key Points:

- Decided at compile time (static polymorphism).
- Function name is same but signature (parameters) must differ.
- Return type cannot be the only difference.

## 2️⃣ – Overloading Constructors

Constructor overloading means defining **multiple constructors in the same class** with different parameter lists to initialize objects in different ways.

```cpp
#include <iostream>
using namespace std;

class Box {
    int length, breadth;
public:
    Box() { length = breadth = 0; }           // default constructor
    Box(int l, int b) { length = l; breadth = b; } // parameterized constructor

    void show() { cout << length << " x " << breadth << endl; }
};

int main() {
    Box b1;           // calls default constructor
    Box b2(10, 5);    // calls parameterized constructor
    b1.show();
    b2.show();
}
```

✅ Key Points:

- Same class name, different constructor signatures.
- Used to initialize objects differently depending on situation.
- Compiler chooses the constructor based on arguments passed.

## 3️⃣ – Copy Constructor

A copy constructor **initializes an object using another object** of the same class.<br>
Syntax:

```cpp
ClassName (const ClassName &obj) {
   // copy data from obj
}
```

Example:

```cpp
#include <iostream>
using namespace std;

class Demo {
    int value;
public:
    Demo(int v) { value = v; }
    Demo(const Demo &d) {   // copy constructor
        value = d.value;
        cout << "Copy constructor called\n";
    }
    void show() { cout << "Value = " << value << endl; }
};

int main() {
    Demo d1(10);
    Demo d2 = d1;   // copy constructor invoked
    d2.show();
}
```

✅ Key Points:

- Called when:

  1. Object initialized from another (e.g., `Demo d2 = d1;`)
  2. Passed by value to a function.
  3. Returned by value from a function.

- If not defined, compiler provides a default copy constructor (shallow copy).
- You can define your own to perform deep copy (especially when using pointers).

## 4️⃣ – Default Function Arguments

A function can have default values for one or more parameters.
If the argument is not passed, the default value is used.

```cpp
#include <iostream>
using namespace std;

void show(int a, int b = 5, int c = 10) {
    cout << "a=" << a << " b=" << b << " c=" << c << endl;
}

int main() {
    show(1);          // uses defaults for b, c → 1 5 10
    show(1, 2);       // uses default for c → 1 2 10
    show(1, 2, 3);    // uses all passed values → 1 2 3
}
```

✅ Key Points:

- Default arguments are assigned from right to left.
- If a parameter has a default value, all parameters to its right must also have defaults.
- Declared only once in function declaration.

## 5️⃣ – Function Overloading and Ambiguity

Sometimes compiler cannot decide which overloaded function to call — this is called **function call ambiguity**.

**Example 1 – Ambiguity due to type conversion:**

```cpp
#include <iostream>
using namespace std;

void test(int a) { cout << "int\n"; }
void test(double a) { cout << "double\n"; }

int main() {
    test('a');   // ambiguous if conversions exist (char → int or double)
}
```

**Example 2 – Ambiguity with default arguments:**

```cpp
void display(int a, int b = 10);
void display(int a);

int main() {
    display(5);  // ambiguous: both match
}
```

✅ Causes of Ambiguity:

- Type conversion (char → int, float → double, etc.)
- Default arguments overlapping with other overloads.
- Multiple inheritance where same function name exists in both parents.

✅ Solutions:

- Use explicit casting (e.g., test((int)'a');).
- Remove unnecessary overloads or defaults.
- Use namespaces or scope resolution to clarify which version to call.
