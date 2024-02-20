#include <iostream>
#include <string>
using namespace std;

class A  {
public:
    int  ia;
    char ca;
    void print() {
        cout << "A: ia = " << ia << " ca = " << ca << endl;
    }
};

struct B {
    A    obA;
    double x;
    void print() {
        cout << "B: x = " << x << " ";
        obA.print();
    }
};

int main() {
    B b{ {4,'a'}, 7.5 };
    b.print();
}
