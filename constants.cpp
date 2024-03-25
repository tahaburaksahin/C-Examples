#include <iostream>
using namespace std;

int fun(const int * pi) {
    //*pi = 2 * (*pi); // WRONG !!!
    return *pi;
}

int main() {
    int i = 2;
    int res = fun(&i);
    cout << "res = " << res << endl;
}
