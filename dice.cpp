#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    int x, y, roll = 0;

    srand(unsigned(time(0)));

    do {
        x =  (int)(rand()/(RAND_MAX + 1.)*6)+1;
        y =  (int)(rand()/(RAND_MAX + 1.)*6)+1;
        cout << "Roll no " << ++roll   << ": ("
             <<  x << ", " << y << ")" << endl;
    } while (x + y != 12);
}
