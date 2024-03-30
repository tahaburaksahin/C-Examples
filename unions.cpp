#include <iostream>
#include <cassert>
using namespace std;

struct Bag;
enum Kind {NUMBER, POINTER, CHAR};

void put(Bag*,double);
void put(Bag*,int*);
void put(Bag*,char);

void get(const Bag*,double&);
void get(const Bag*,int*&);
void get(const Bag*,char&);

void info(const Bag&);

struct Bag {
    Kind kind;
    union {
        double dbl;
        int   *pnt;
        char   chr;
    };
};

int main() {
    Bag bag;
    double x = 3.14, y;
    int    i = 10, *pi = &i;
    char   c ='a', b;
    cout << "sizeof(bag) = " << sizeof(bag)
         << " bytes\nAddresses of members:\n dbl: "
         << &bag.dbl << "\n pnt: " <<  &bag.pnt
         << "\n chr: " << (void*)&bag.chr << endl;

    put(&bag,x);
    info(bag);
    get(&bag,y);
    cout << "From function main - y  = " <<    y << endl;

    put(&bag,&i);
    info(bag);
    get(&bag,pi);
    cout << "From function main - *pi = " << *pi << endl;

    put(&bag,c);
    info(bag);
    get(&bag,b);
    cout << "From function main - b   = " <<   b << endl;
}

void put(Bag *w, double x) {
    w->kind   = NUMBER;
    w->dbl = x;
}

void put(Bag *w, int *pi) {
    w->kind   = POINTER;
    w->pnt = pi;
}

void put(Bag *w, char c) {
    w->kind   = CHAR;
    w->chr = c;
}

void get(const Bag *w, double& x) {
    assert(w->kind == NUMBER);
    x  = w->dbl;
}

void get(const Bag *w, int*& pi) {
    assert(w->kind == POINTER);
    pi = w->pnt;
}

void get(const Bag *w, char& c) {
    assert(w->kind == CHAR);
    c  = w->chr;
}

void info(const Bag &w) {
    cout << "\nFrom function info - ";
    switch (w.kind) {
    case NUMBER:
        cout << "Number:    " << w.dbl    << endl;
        break;
    case POINTER:
        cout << "Pointer:   " << *(w.pnt) << endl;
        break;
    case CHAR:
        cout << "Character: " << w.chr    << endl;
        break;
    }
}
