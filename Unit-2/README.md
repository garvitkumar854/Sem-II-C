# Unit 2

## 1️⃣ – Arrays of Objects

An array that stores **multiple objects** of the same class type

```cpp
#include <iostream>
using namespace std;

class Student {
    int id;
public:
    void set(int x) { id = x; }
    void show() { cout << "ID: " << id << endl; }
};

int main() {
    Student s[3];     // array of 3 objects
    for (int i = 0; i < 3; i++)
        s[i].set(i + 1);

    for (int i = 0; i < 3; i++)
        s[i].show();
}
```

## 2️⃣ – Pointers

A pointer stores the **address of another variable** (or object).

```cpp
int a = 10;
int *p = &a;
cout << *p;   // dereferencing → prints 10
```

## 3️⃣ – Pointer Expressions

Operations performed using pointers — arithmetic and relational.

```cpp
int arr[3] = {10, 20, 30};
int *p = arr;
cout << *p << endl;    // 10
p++;
cout << *p << endl;    // 20
```

✅ Key Points:

- `p++` → moves to next element
- Pointer arithmetic valid only on arrays and same type objects
- You can compare pointers of same array using `<`, `>`, `==`

## 4️⃣ – Pointer as Function Arguments

Passing a pointer allows a function to directly modify the original variable.

```cpp
#include <iostream>
using namespace std;

void change(int *n) {
    *n = *n + 5;
}

int main() {
    int x = 10;
    change(&x);
    cout << x;  // Output: 15
}
```

## 5️⃣ – Functions Returning Pointers

A function can return the **address of a variable**

```cpp
#include <iostream>
using namespace std;

int* getSquare(int n) {
    int *p = new int;
    *p = n * n;
    return p;
}

int main() {
    int *result = getSquare(5);
    cout << *result;   // 25
    delete result;     // free memory
}
```

✅ Key Points:

- Return pointers to dynamically allocated memory only (avoid returning local addresses).
- Use `delete` to free memory later.

## 6️⃣ – Pointers to Functions

A pointer that holds the address of a function.

```cpp
#include <iostream>
using namespace std;

int add(int a, int b) { return a + b; }

int main() {
    int (*fptr)(int, int);  // function pointer
    fptr = add;
    cout << fptr(3, 4);     // Output: 7
}
```

✅ Key Points:

- Function pointer declaration syntax:
  `return_type (*pointer_name)(parameter_list);`
- Used in callback functions and event-driven programs.

## 7️⃣ – Creating Initialized Pointers (vs Uninitialized)

Always initialize pointers before using them.

```cpp
int *p = nullptr;   // good practice
int x = 10;
p = &x;
cout << *p;
```

❌ Uninitialized pointer:

```cpp
int *p;  // undefined behavior if used
```

✅ Key Points:

- Always initialize (nullptr or address).
- Avoid dangling pointers (pointing to deleted memory).

## 8️⃣ – Pointers to Objects

A pointer can point to an object, allowing access to members using -> operator.

```cpp
#include <iostream>
using namespace std;

class Box {
public:
    int length;
    void set(int l) { length = l; }
    void show() { cout << length; }
};

int main() {
    Box obj;
    Box *ptr = &obj;
    ptr->set(20);
    ptr->show();
}
```

✅ Key Points:

- Use -> instead of . with object pointers
- Used in dynamic object handling (`new` / `delete`)

## 9️⃣ – The this Pointer

`this` is an implicit pointer available inside non-static member functions that points to the calling object.

```cpp
#include <iostream>
using namespace std;

class Demo {
    int x;
public:
    Demo(int x) { this->x = x; }   // differentiate between local and member
    void show() { cout << "x = " << this->x; }
};

int main() {
    Demo d(10);
    d.show();
}
```

✅ Key Points:

- oints to current object.
- Used for method chaining or to avoid name conflicts.
- Not available in static functions.

## 🔟 – References

A reference is an alias (another name) for an existing variable.

```cpp
int a = 5;
int &b = a;  // reference
b = 10;
cout << a;   // Output: 10
```

✅ Key Points:

- Must be initialized when declared.
- Cannot be reassigned to another variable later.
- More secure and simpler than pointers.

### Reference Parameters

Passing parameters by reference lets a function directly access the caller’s variable.

```cpp
#include <iostream>
using namespace std;

void swap(int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;
}

int main() {
    int a = 3, b = 4;
    swap(a, b);
    cout << a << " " << b; // Output: 4 3
}
```

✅ Key Points:

- Uses & in parameter list
- No need to use \* or & in call
- Safer than pointer-based functions

### Passing References to Objects

Similar to reference parameters, but for class objects.

```cpp
class Test {
public:
    int val;
    Test(int v) { val = v; }
};

void modify(Test &t) {
    t.val += 5;
}

int main() {
    Test obj(10);
    modify(obj);
    cout << obj.val;  // 15
}
```

✅ Key Points:

- Avoids object copying
- Efficient for large objects

### Returning References

A function can return a reference instead of a value, allowing direct modification of data.

```cpp
#include <iostream>
using namespace std;

int& fun() {
    static int x = 10;
    return x;
}

int main() {
    fun() = 25;   // modifies x directly
    cout << fun(); // Output: 25
}
```

✅ Key Points:

- Must return reference to valid memory (like static variable).
- Returning reference allows chained assignment and direct updates.


### Dynamic Allocation Operators (`new` and `delete`)

C++ provides `new` and `delete` operators for dynamic memory allocation and deallocation.
```cpp
int *p = new int;     // allocates memory
*p = 10;
cout << *p;
delete p;             // frees memory
```

✅ Key Points:

- `new` returns pointer to allocated memory.
- `delete` must be used to avoid memory leaks.
- Works for both primitive and user-defined types.

### Initializing Allocated Memory
You can initialize memory while allocating.
```cpp
int *p = new int(100);     // initialized
cout << *p;                // Output: 100
delete p;
```

### Allocating Arrays
```cpp
int *arr = new int[5];    // array of 5 ints
for (int i = 0; i < 5; i++)
    arr[i] = i + 1;

for (int i = 0; i < 5; i++)
    cout << arr[i] << " ";

delete[] arr;  // free entire array
```

### Allocating Objects
```cpp
#include <iostream>
using namespace std;

class Box {
public:
    Box() { cout << "Constructor called\n"; }
    ~Box() { cout << "Destructor called\n"; }
};

int main() {
    Box *ptr = new Box;   // allocates object
    delete ptr;           // destroys object
}
```

✅ Key Points:

- Constructor and destructor are automatically called.
- Use `delete` to free object memory.