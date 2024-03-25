#include <iostream>
using namespace std;

int main() {
    int *p, k = 5, m = 7;

    const int cnts = 3;        // constant
    const int *q = &k;         // q - pointer to constant
    int *const r = &k;         // r - constant pointer
    const int arr[] = {1,2,3}; // array of constants

    p = &cnts;
    cnts = 1;
    *q = m;
    q = &m;
    r = &m;
    k = 10;
    arr[1] = 9;
}
