#include <iostream>
using namespace std;

class A {
    int i;
public:
    A() : i(0)
    { }
};

class B {
    int i;
public:
    B() : i(0)
    { }
    ~B()
    { }
};

class C {
    int i;
public:
    C() : i(0)
    { }
    virtual ~C()
    { }
};

int main() {
   cout << "sizeof(A): " << sizeof(A) << endl;
   cout << "sizeof(B): " << sizeof(B) << endl;
   cout << "sizeof(C): " << sizeof(C) << endl;
}
