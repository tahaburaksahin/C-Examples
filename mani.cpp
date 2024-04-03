#include <iostream>
using namespace std;

int main() {
    int a = 0xdf, b = 0771, c = 123;

    cout << "dec (default): "
         << dec << a << " " << b << " " << c << endl;

    cout << "hex, no showbase:   "
         << hex << a << " " << b << " " << c << endl;

    cout.setf(ios::showbase);

    cout << "hex, with showbase: "
         << a << " " << b << " " << c << endl;

    cout << "oct, with showbase: "
         << oct << a << " " << b << " " << c << endl;

    cout.unsetf(ios::showbase);

    cout << "oct, no showbase:   "
         << a << " " << b << " " << c << endl;
}
