#include <iostream>
using namespace std;

int main() {
    int i = 1, m = 2;
    const int *const pi = &i;

    cout << "Before *pi = " << *pi << endl;
    i = 3;
    cout << "After  *pi = " << *pi << endl;

    *pi = 4; // NO: pi points to a constant
    pi = &m; // NO: pi is a constant pointer
}
