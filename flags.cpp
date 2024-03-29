#include <iostream>
using namespace std;

typedef ios_base::fmtflags FFLAG;

int main() {
    int    m =  49;
    double x = 21.73;

    cout << "1. m = " << m << ", x = " << x << endl;

    FFLAG  newf = ios::hex | ios::showbase
                           | ios::showpoint;
    FFLAG  oldf = cout.flags(newf);
    cout << "2. m = " << m << ", x = " << x << endl;

    cout.setf(ios::scientific, ios::floatfield);
    cout.unsetf(ios::showbase);
    cout << "3. m = " << m << ", x = " << x << endl;

    cout.setf(ios::fixed, ios::floatfield);
    cout.setf(ios::showbase | ios::uppercase);
    cout << "4. m = " << m << ", x = " << x << endl;

    cout.flags(oldf);
    cout << "5. m = " << m << ", x = " << x << endl;
}
