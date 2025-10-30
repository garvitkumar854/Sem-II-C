// Copy Constructor

#include <iostream>
using namespace std;

class Student{
public:
    int roll;
    string name;

    // Parameterized Constructor (Sets value of both attributes)
    // requires to set the value
    Student(int r, string n){
        roll = r;
        name = n;
    }

    // Copy Constructor (Automatically Run when copying)
    Student(const Student &s){
        roll = s.roll;
        name = " ";          // use can skip any attrib if don't want to copy
    }   
};


int main(){
    Student s1(101, "Amit");
    Student s2 = s1;


    // Default copying (Object Assignment)
    // Student s2 = s1;    
    cout << s2.roll << "\n" << s2.name;
    
    return 0;
}