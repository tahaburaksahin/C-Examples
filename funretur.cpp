#include <iostream>
#include <cmath>
using namespace std;

typedef double (*FUNDtoD)(double);
typedef FUNDtoD ARRFUN[];

FUNDtoD funmax(ARRFUN,double);

double fun0(double x) { return log(x); }
double fun1(double x) { return x*x;    }
double fun2(double x) { return exp(x); }
double fun3(double x) { return sin(x); }
double fun4(double x) { return cos(x); }

int main() {
    ARRFUN arrfun = { fun0, fun1, fun2, fun3, fun4 };

    FUNDtoD fun = funmax(arrfun,1);

    int i;
    for (i = 0; i < 5; ++i)
        if (fun == arrfun[i]) break;

    cout.precision(14);
    cout << "Largest value at x=1 assumed by function no "
         << i << ".\nThe value is " << fun(1) << endl;
}

FUNDtoD funmax(ARRFUN f, double x) {
    double m = f[0](x),z;
    int    k = 0;

    for (int i = 1; i < 5; i++) {
        if ( (z = f[i](x)) > m) {
            m = z;
            k = i;
        }
    }
    return f[k];
}
