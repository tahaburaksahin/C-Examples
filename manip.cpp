#include <iostream>
#include <string>
using namespace std;

struct maniparg {
    string str;
    maniparg(int cnt, char c) : str(cnt,c) { }
    ostream& operator()(ostream& s) const {
        return s << str;
    }
};

ostream& operator<<(ostream& s, const maniparg& manip) {
    return manip(s);
}

int main() {
    cout << maniparg(7,'*') << "This is maniparg"
         << maniparg(3,'!') << maniparg(7,'*') << endl;

    maniparg threeexcls(3,'!');
    maniparg sevenstars(7,'*');

    cout << sevenstars <<  "This is maniparg"
         << threeexcls << sevenstars  << endl;
}
