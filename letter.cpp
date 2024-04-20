#include <iostream>
#include <cstring>
using namespace std;

class Letter {
    char* name;
public:
    Letter(const Letter& k)
        : name(strcpy(new char[strlen(k.name)+1],
                      k.name))
    { }

    Letter(const char* name)
        : name(strcpy(new char[strlen(name)+1],
                      name))
    { }

    Letter& operator=(const Letter&);
    char& operator[](int);

    ~Letter() { delete [] name; }

    friend ostream& operator<<(ostream&,const Letter&);
};

char& Letter::operator[](int n) {
    int len = strlen(name);
    if ( n < 0 || n >= len )
        // reference to NUL if index is wrong
        return name[len];
    else
        return name[n];
}

Letter& Letter::operator=(const Letter& k) {
    if (this == &k ) return *this;
    delete [] name;
    name = strcpy(new char[strlen(k.name)+1],k.name);
    return *this;
}

ostream& operator<<(ostream& str, const Letter& k) {
    return str << k.name;
}

int main() {
    Letter a("Benny");
    cout << "a=" << a << endl;

    char c = a[100];
    if (c == '\0') cout << "Out of range!" << endl;
    else           cout << "character: "   << c << endl;

    c = a[4];
    if (c == '\0') cout << "Out of range!" << endl;
    else           cout << "character: "   << c << endl;

    a[0] = 'J';
    cout << "a=" << a << endl;
}
