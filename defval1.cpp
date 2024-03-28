#include <iostream>
using namespace std;

#include "defval1h.h"

void color(int, int , int = 0, int);

int main() {
    color(100,150,250,199);
    color(100,150,250);
    color(100,150);
}

void color(int red, int green, int blue, int alpha) {
    cout << "Alpha = " << alpha << " (R,G,B) = (" << red
         << ","  << green  <<  "," << blue << ")" << endl;
}
