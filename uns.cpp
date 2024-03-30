#include <iostream>
using namespace std;

union Bag;

void put(Bag*,float);
void put(Bag*,long double);
void inf(const Bag*);

union Bag {
    float       numberF;
    long double numberLD;
} bag ;

int main() {
    cout << "      sizeof(float)=" << sizeof(float) << endl;
    cout << "sizeof(long double)="
         << sizeof(long double) << endl;
    cout << "        sizeof(Bag)=" << sizeof(Bag) << endl;

    put(&bag, 3.14F);
    inf(&bag);

    put(&bag, 3.14L);
    inf(&bag);
}

void put(Bag *w, float f) {
    w->numberF = f;
}

void put(Bag *w, long double ld) {
    w->numberLD = ld;
}

void inf(const Bag *w) {
    cout << "\nnumberF : " << w->numberF  << endl;
    cout <<   "numberLD: " << w->numberLD << endl;
}
