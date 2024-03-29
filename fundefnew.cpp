#include <iostream>
using namespace std;

auto D(int a, double b) -> decltype(a*b);

double A(int a, double b) {
    return a*b;
}

auto B(int a, double b) -> double {
    return a*b;
}

auto C(int a, double b) -> decltype(a*b) {
    return a*b;
}

double D(int a, double b) {
    return a*b;
}

int main() {
    cout << A(4,2.5) << " " << B(4,2.5) << " "
         << C(4,2.5) << " " << D(4,2.5) << endl;
}
