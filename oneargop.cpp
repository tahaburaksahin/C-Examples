#include <iostream>
#include <string>
using namespace std;

struct AClass {
    string name;

    AClass(const string& name)
        : name(name)
    { }
};

bool operator!(const AClass& c) {
    return c.name.size() > 5;
}

int main() {
    AClass t[] = { AClass("Marlon"), AClass("Henry"),
                   AClass("Dave"),   AClass("Horatio"),
                   AClass("Sue"),    AClass("Alice")   };

    for (int i = 0; i < 6; ++i)
        if ( !t[i] ) cout << t[i].name << endl;
}
