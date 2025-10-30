// Destructor
#include <iostream>
using namespace std;

class Sqaure{
public:
    int area;
    
    Sqaure(int s){
        area = s*s;
        cout << "Constructor Called" << endl;
    }

    ~Sqaure(){
        cout << "Destructor Called" << endl;
    }
};

int main(){
    Sqaure s1(5);
    Sqaure s13(10);

    /* Output:
    Constructor Called
    Constructor Called
    Destructor Called
    Destructor Called
    */

    return 0;
}