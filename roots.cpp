#include <iostream>
#include <cmath>
#include <cassert>
using namespace std;

const double PI = 4*atan(1.);

typedef double (*FD2D)(double);

double root(FD2D, double, double);

double polyn(double x) {return 3 - x*(1 + x*(27 - x*9));}

int main() {
    double r;

    cout.precision(15);

    r = root(sin, 3, 4);
    cout << "sin      " <<  r    << endl
         << "exactly: " <<  PI   << endl << endl;

    r = root(cos, -2, -1.5);
    cout << "cos:     " <<  r    << endl
         << "exactly: " << -PI/2 << endl << endl;

    r = root(polyn, 0, 1);
    cout << "polyn:   " <<  r    << endl
         << "exactly: " <<  1./3 << endl;

    r = root([] (double x) -> double {
                 return 3-x*(1+x*(27-x*9));
             }, 0, 1);
    cout << "lambda:  " <<  r    << endl
         << "exactly: " <<  1./3 << endl;
}

double root(FD2D fun, double a, double b) {
    /* Finding root of function using bisection.
       fun(a) and fun(b)  must be of opposite sign */
    static const double EPS = 1e-15;
    double f, s, h = b-a, f1 = fun(a), f2 = fun(b);

    if (f1 == 0) return a;
    if (f2 == 0) return b;
    assert(f1*f2 < 0);

    do {
        if ((f = fun((s=(a+b)/2))) == 0) break;
        if (f*f1 < 0) {f2 = f;b = s;}
        else          {f1 = f;a = s;}
    } while ((h /= 2) > EPS);

    return (a+b)/2;
}
