#include <iostream>
using namespace std;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    int x, y;

    x = 732591; y = 1272585;
    cout << "gcd(" << x << "," << y << ")\t= "
         << gcd(x,y) << endl;

    x = 732591; y = 1270;
    cout << "gcd(" << x << "," << y << ")\t= "
         << gcd(x,y) << endl;
}
