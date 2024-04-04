#include <iostream>

int& fun(int *k, int &m) {
    return *k > m ? *k : m;
}

int main() {
    using std::cout; using std::endl;
    int tab[]{1,2,3};

    int (&x)[3] = tab;
    cout << "x[2]    = " << x[2]    << endl;

    int *y[3] = {tab,tab,tab};
    cout << "y[2][0] = " << y[2][0] << endl;

    int *(&z)[3] = y;
    cout << "z[2][0] = " << z[2][0] << endl;

    int &(*f)(int*,int&);
    f = fun;
    int v1 =  f(&tab[1], tab[2]);
    int v2 = (*f)(&tab[1], tab[2]);
    cout << "v1      = " << v1      << endl;
    cout << "v2      = " << v2      << endl;
}
