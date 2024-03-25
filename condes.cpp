#include <iostream>
using namespace std;

struct K {
    char k;
    K(char kk = 'k') {
        k = kk;
        cout << "Ctor K\n";
    }

    ~K() {
        cout << "Dtor K\n";
    }
};

struct A {
    char a;
    A(char aa = 'a') {
        a = aa;
        cout << "Ctor A\n";
    }

    ~A() {
        cout << "Dtor A\n";
    }
};

struct B: public A {
    char b;
    K    k;
    B(char bb = 'b') : A(bb) {
        b = bb;
        cout << "Ctor B\n";
    }

    ~B() {
        cout << "Dtor B\n";
    }
};

struct C: public B {
    char c;
    C(char cc = 'c') : B(cc) {
        c = cc;
        cout << "Ctor C\n";
    }

    ~C() {
        cout << "Dtor C\n";
    }
};

int main() {
    C c;
}
