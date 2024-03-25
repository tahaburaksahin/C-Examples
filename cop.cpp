#include <iostream>
using namespace std;

class A {
    int a;
public:
    A(const A& aa) {
        a = aa.a;
        cout << "Copy-ctor A, a = " << a << endl;
    }

    A(int aa = 0) {
        a = aa;
        cout << "Def-ctor  A, a = " << a << endl;
    }

    void showA() { cout << "a = " << a; }
};

class B: public A {
    int b;
public:
    B(const B& bb)
        : A(bb)
    {
        b = bb.b;
        cout << "Copy-ctor B, b = " << b << endl;
    }

    B(int bb = 1)
        : A(1)
    {
        b = bb;
        cout << "Def-ctor  B, b = " << b << endl;
    }

    void showB() {
        showA();
        cout << ", b = " << b << endl;
    }
};

int main() {
    B b1(2);
    b1.showB();

    B b2(b1);
    b2.showB();
}
