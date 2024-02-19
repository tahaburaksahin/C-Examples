#include <iostream>
using namespace std;

class Vector {
    double x, y, z;
public:
    void set(double xx, double yy, double zz) {
        x = xx;
        y = yy;
        z = zz;
    }
    double dot_product(const Vector& w) {
        return x*w.x + y*w.y + z*w.z;
    }
};

int main() {
    Vector w1, w2;
    w1.set(1, 1, 2);
    w2.set(1,-1, 2);
    cout << "w1*w2 = " << w1.dot_product(w2) << endl;
}
