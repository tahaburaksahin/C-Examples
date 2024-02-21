#include <iostream>
using namespace std;

void exchange(int tab[][4], int w1, int w2) {
    int t,k;
    for (k = 0; k < 4; k++) {
        t          = tab[w1][k];
        tab[w1][k] = tab[w2][k];
        tab[w2][k] = t;
    }
}

void printArray(int tab[][4], int dim1) {
    int w,k;
    for (w = 0; w < dim1; w++) {
        for (k = 0; k < 4; k++)
            cout << tab[w][k] << " ";
        cout << endl;
    }
}

int main() {
    int tab[3][4] = { {1,2,3,4}, {5,6}, {1} };

    cout << "Array before:\n"; printArray(tab,3);
    exchange(tab,0,1);
    cout << "Array  after:\n"; printArray(tab,3);
}
