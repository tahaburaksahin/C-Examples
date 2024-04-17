#include <iostream>
using namespace std;

extern double x1;
double x2 = 22;

void func()
{
    cout << "func: x1 = " << x1 << endl;
    cout << "func: x2 = " << x2 << endl;
}
