#include <iostream>
using namespace std;

int* fun(int *arr1, int *arr2, int size) {
    int i, x, y, s1{}, s2{};
    for (i = 0; i < size; ++i) {
        x = arr1[i];
        y = arr2[i];
        arr1[i] = y;
        arr2[i] = x;
        s1 += y;
        s2 += x;
    }
    return s1 > s2 ? arr1 : arr2;
}

void printArr(int *arr, int size) {
    for (int i = 0; i < size; ++i)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr1[]{1,2,3}, arr2[]{4,5,6}, *arr3;

    cout << "arr1 before: "; printArr(arr1,3);
    cout << "arr2 before: "; printArr(arr2,3);
    arr3 = fun(arr1,arr2,3);
    cout << "arr1  after: "; printArr(arr1,3);
    cout << "arr2  after: "; printArr(arr2,3);
    cout << "arr3       : "; printArr(arr3,3);
}
