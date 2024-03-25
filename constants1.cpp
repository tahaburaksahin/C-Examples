#include <iostream>
using namespace std;

int main() {
    int i = 2;
    const int *pi = &i;

    i = 2*i;
    cout << "  i = " <<   i << endl;
    cout << "*pi = " << *pi << endl;
    //*pi = -1;
}
