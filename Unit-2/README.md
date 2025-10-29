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
- Use delete to free memory later.

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

