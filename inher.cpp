#include <iostream>
using namespace std;

class A {
public:
    int fun(int x) { return x*x; }
};

class B : private A {
    int fun(int x, int y) {
        return A::fun(x) + y*y;
    }
public:
    int pub(int x, int y) { return fun(x,y); }
};

int main() {
    A a;
    B b;
    cout << "a.fun(3)   = " << a.fun(3)   << endl;
    cout << "b.pub(3,4) = " << b.pub(3,4) << endl;
 // cout << "b.fun(3,4) = " << b.fun(3,4) << endl;
}
