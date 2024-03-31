#include <iostream>
using namespace std;

struct A {
    const char* info() { return "A*"; }
};

struct B : A {
    const char* info() { return "B*"; }
};

int main()
{
    try {
        throw new B;
    }
    catch(A* a) { cout << a->info() << endl; }
    catch(B* b) { cout << b->info() << endl; }
}
