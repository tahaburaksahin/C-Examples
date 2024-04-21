#include <iostream>
#include <cstring>   // memcpy, memmove
using namespace std;

template <typename T>
T* rotate_left(T arr[], size_t size, size_t shift) {

    if ((shift %= size) == 0) return arr;

    T* aux = new T[shift];

    memcpy(aux,arr,shift*sizeof(T));
    memmove(arr,arr+shift,(size-shift)*sizeof(T));
    memcpy(arr+size-shift,aux,shift*sizeof(T));

    delete [] aux;
    return arr;
}

template <typename T>
void writeArr(const char* mes, const T arr[], size_t size) {
    cout << mes << ": " << "[ ";
    for (size_t i = 0; i < size; ++i)
        cout << arr[i] << " ";
    cout << "]" << endl;
}

int main() {
    char arrc[] = {'a','b','c','d','e','f'};
    writeArr("   char array",arrc,6);
    rotate_left(arrc,6,8);
    writeArr(" rotated by 8",arrc,6);
    rotate_left(arrc,6,1);
    writeArr("and then by 1",arrc,6);

    cout << endl;

    int arri[] = {1,2,3,4,5,6,7,8,9};
    writeArr("    int array",arri,9);
    rotate_left(arri,9,7);
    writeArr(" rotated by 7",arri,9);
}
