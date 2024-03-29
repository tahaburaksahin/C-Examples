#include <iostream>
using namespace std;

double linear(double a, double b, double x) {
    return a*x + b;
}

int main() {
    double c = 2, z = 3;
    double result = linear(c,5,z);
    cout << "The result = " << result << endl;
}
