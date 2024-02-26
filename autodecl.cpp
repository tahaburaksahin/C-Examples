#include <iostream>
using namespace std;

int main() {
    auto k = 7;             // k has type int
    auto x = 1.;            // x has type double
    decltype(x) y = 7;      // y has type double, although
                            // '7' is a literal of type int
    decltype(k*x) z = 7;    // product k*x has type double
    cout << "k/2="   << k/2 << ", y/2=" << y/2
         << ", z/2=" << z/2 << endl;
}
