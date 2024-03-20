#include <iostream>
using namespace std;

struct A {
    int x;
    int y;
    A() : x(1), y(2) {}
};

struct B : public A {
    int x;  // ????
};

int main() {
    B b, *pb = &b;
    b.x = 11;
    b.y = 12;

    cout << "b.x=" << b.x        << " b.y="
         << b.y    << " b.A::x=" << b.A::x
         << " b.A::y=" << b.A::y << endl;

    cout << "\n      pb->x=" <<    pb ->x   << endl;
    cout <<   "((A*)pb)->x=" << ((A*)pb)->x << endl;
    cout <<   "        b.x=" <<       b.x   << endl;
    cout <<   "  ((A&)b).x=" << ((A&)b).x   << endl;
    cout <<   "((A*)&b)->x=" << ((A*)&b)->x << endl;

    A* pa = new B;
    ((B&)*pa).x = 11;

    cout << "\n    (*pa).x=" << (*pa).x     << endl;
    cout <<   "((B&)*pa).x=" << ((B&)*pa).x << endl;
    cout <<   "      pa->x=" <<       pa->x << endl;
    cout <<   "((B*)pa)->x=" << ((B*)pa)->x << endl;

    cout << "\nsizeof(b) = " << sizeof b << endl;
    int* t = (int*) &b;
    cout << t[0] << " " << t[1] << " " << t[2] << endl;
}
