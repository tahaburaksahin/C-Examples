#include <iostream>
using namespace std;

int main () {
    int k = 7, *p = &k, &refk = *p, m = 9;

    p = &m;
    k = 11;

    cout << "  *p = " <<   *p << endl;
    cout << "refk = " << refk << endl;
}
