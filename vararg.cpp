#include <iostream>
#include <cstdarg>
using namespace std;

void types(const char typ[] ...);

int main() {
    types("SxS", "John", 0, "Mary");
    types("issD", 17, "John", "Mary", 1.);
    types("iDdsiI", 17, 19.5, 1.5, "OK", -1, 8);
}

void types(const char typ[] ...) {
    int     i = 0, integ;
    char    c, *strin;
    double  doubl;

    va_list ap;

    va_start(ap,typ);

    while ( (c = typ[i++]) != '\0') {
        switch (c) {
            case 'i':
            case 'I':
                integ = va_arg(ap,int);
                cout << "An int  : " << integ << endl;
                break;
            case 'd':
            case 'D':
                doubl = va_arg(ap,double);
                cout << "A double: " << doubl << endl;
                break;
            case 's':
            case 'S':
                strin = va_arg(ap,char*);
                cout << "A string: " << strin << endl;
                break;
            default:
                cout << "Invalid typecode!!!" << endl;
                goto END;
        }
    }
    END:
    cout << endl;

    va_end(ap);
}
