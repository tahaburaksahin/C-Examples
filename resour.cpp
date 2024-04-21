#include <iostream>
#include <cstring>
#include <cstdio>  // FILE, fopen, fclose
using namespace std;

class A {
    struct nam {
        char* n;
        nam(const char* n)
            : n(strcpy(new char[strlen(n)+1],n))
        { }
        ~nam() {
            cerr << "dtor nam: " << n << endl;
            delete [] n;
        }
    };

    nam Name;
    FILE*    file;
public:
    A(const char* n, const char* p)
        : Name(n)
    {
        file = fopen(p,"r");
        // ...
//      throw 1;
        // ...
    }

    // other fields and methods

    ~A() {
        cerr << "dtor A" << endl;
        if (file) fclose(file);
    }
};

int main() {
    try {
        A a("Carrington","afile.cpp");
    } catch(...) {
        cerr << "object instantiation failed\n";
    }
}
