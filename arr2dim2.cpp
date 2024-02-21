#include <iostream>
using namespace std;

void exchange(int* arr[], int w1, int w2,
                          int dim1, int dim2) {
    for (int k = 0; k < dim2; k++) {
        int t      = arr[w1][k];
        arr[w1][k] = arr[w2][k];
        arr[w2][k] = t;
    }
}

void printArray(int* arr[], int dim1, int dim2) {
    for (int w = 0; w < dim1; w++) {
        for (int k = 0; k < dim2; k++)
            cout << arr[w][k] << " ";
        cout << endl;
    }
}

int main() {
    int tt[3][4] = { {1,2,3,4}, {7,6}, {1} };

    const int dim1 = 3;
    const int dim2 = 4;

    int* arr[dim1];
    for (int i = 0; i < dim1; i++) arr[i] = tt[i];

    cout << "Before:\n"; printArray(arr,dim1,dim2);
    exchange(arr,0,1,dim1,dim2);
    cout << "After:\n";  printArray(arr,dim1,dim2);
}
