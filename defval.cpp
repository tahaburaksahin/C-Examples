#include <iostream>
using namespace std;

double PI = 3;

double disc(double, double = PI);

int main() {
    double r = 1;

    cout << "1. PI = " << PI << " Area = "
                       << disc(r) << endl;
    double PI = 3.14;
    cout << "2. PI = " << PI << " Area = "
                       << disc(r) << endl;
    ::PI = 3.14;
    cout << "3. PI = " << PI << " Area = "
                       << disc(r) << endl;
}

double disc(double r, double pi) {
    return pi*r*r;
}
