#include <iostream>
using namespace std;

void reverse(int *arr, int size) {
    if ( size < 2 ) return;

    for (int i = 0, k = size-1, aux; i < k; i++, k--) {
        aux    = arr[i];
        arr[i] = arr[k];
        arr[k] = aux;
    }
}

void printArr(int *arr, int size) {
    cout << "[ ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << "]" << endl;
}

int main() {
    int arr[] = { 1, 3, 5, 7, 2, 4, -9, 12 };
    int size = sizeof(arr)/sizeof(arr[0]);

    printArr(arr,size);
    reverse (arr,size);
    printArr(arr,size);
}
