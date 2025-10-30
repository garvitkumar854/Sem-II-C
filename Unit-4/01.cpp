#include <iostream>
using namespace std;

class Demo{
    int value;
public:
    void setData(){
        cout << "Enter a Number: ";
        cin >> value;
    }

    void getData(){
        cout << "Value: " << value << endl;
    }

    Demo operator + (Demo b){
        Demo c;
        c.value = value + b.value;
        return c;           // returning object
    }

    Demo operator - (Demo b){
        Demo c;
        c.value = value - b.value;
        return c;
    }

};

int main(){
    Demo a, b, c, d;
    a.setData();
    b.setData();
    c = a + b;
    d = a - b;
    c.getData();
    d.getData();

    return 0;
}