#include <iostream>
using namespace std;

int d2i(double);
double i2d(int);

int main() {
    double x = 3.5;

    cout << "d2i(x) = " << d2i(x) << endl
         << "i2d(x) = " << i2d(x) << endl;
}

int d2i(double x) { return 3*x; }
double i2d(int k) { return 3*k; }
