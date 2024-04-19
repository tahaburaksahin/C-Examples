#include <iostream>
using namespace std;

int main() {
    double x, y = 1.5, u;

    double *px;
    px = &x;

    double* py = &y;

    double *pz, *pu = &u, v;

    cout << "1. *py = "  << *py
         << " y = " << y << endl;

    x = 0.5;
    cout << "2. *px = "  << *px
         << " x = " << x << endl;

    *px = 5*x;
    cout << "3. *px = "  << *px
         << " x = " << x << endl;

    pz = px;
    cout << "4. *pz = "  << *pz << endl;

    *pu = v = *pz = 10;
    cout << "5. *pu = "  << *pu
         << " u = " << u << " v = "
         << v << " x = " << x << endl;

    cout << "6.  py = " <<  py << endl;
    cout << "7. &py = " << &py << endl;
}
