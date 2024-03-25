#include <iostream>
using namespace std;

int main() {
    const int i = 2, j = 3;

    const int *p = &i;
    cout << "*p = " << *p << endl;

    p = &j;
    cout << "*p = " << *p << endl;
}
