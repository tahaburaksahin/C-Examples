#include <iostream>
#include <cmath>
using namespace std;

struct Point {
    double x, y;
    Point(double x = 0, double y = 0)
        : x(x), y(y)
    { }
    double r2() { return  x*x + y*y; }
    double dd() { return sqrt(r2()); }
};

int main() {
    double  Point::*pi[2];
    double (Point::*pf[2])();

    pi[0] = &Point::x;
    pi[1] = &Point::y;

    pf[0] = &Point::r2;
    pf[1] = &Point::dd;

    Point P(3,4), *p = &P;

    cout << " P.*pi[0]     = " <<  P.*pi[0]     << endl;
    cout << " P.*pi[1]     = " <<  P.*pi[1]     << endl;
    cout << "(P.*pf[0])()  = " << (P.*pf[0])()  << endl;
    cout << "(P.*pf[1])()  = " << (P.*pf[1])()  << endl;

    cout << endl;

    cout << " p->*pi[0]    = " <<  p->*pi[0]    << endl;
    cout << " p->*pi[1]    = " <<  p->*pi[1]    << endl;
    cout << "(p->*pf[0])() = " << (p->*pf[0])() << endl;
    cout << "(p->*pf[1])() = " << (p->*pf[1])() << endl;
}
