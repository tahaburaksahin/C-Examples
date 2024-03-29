#include <iostream>
using namespace std;

int main() {
    int arr[] = {1,2,3,4,9,8,7,6};

    for (int e  : arr) cout << e << " ";
    cout << endl;
    for (int& e : arr) e -= 1;
    for (auto e : arr) cout << e << " ";
    cout << endl;
}
