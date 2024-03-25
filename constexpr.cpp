#include <iostream>
using namespace std;

int main() {
    constexpr int hourfee = 7;
    constexpr int tim = 5;

    int arr[10 + (tim-1)*hourfee];

    cout << "number of elements in arr "
         << sizeof(arr)/sizeof(arr[0]) << endl;
}
