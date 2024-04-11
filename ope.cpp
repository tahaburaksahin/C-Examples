#include <iostream>
#include <cstring>   // memcpy
using namespace std;

class ArrInt {
    static int ID;
    int        id;
    int      size;
    int      *arr;
public:
    ArrInt(const int *t, int size)
        : id(++ID), size(size),
          arr((int*)memcpy(new int[size], t,
                           size*sizeof(int))) {
        cout << "      ctor: id = " << id << endl;
    }

    ArrInt(const ArrInt& t)
        : id(++ID), size(t.size),
          arr((int*)memcpy(new int[size], t.arr,
                           size*sizeof(int))) {
        cout << " copy-ctor: id = " << t.id
             << "-->" << id << endl;
    }

    ~ArrInt() {
        cout << "  Deleting: id = " << id << endl;
        delete [] arr;
    }

    ArrInt& operator=(const ArrInt& t) {
        cout << "Assignment: id = " << id
             << "<--" << t.id << endl;
        if (this != &t) {
            delete [] arr;
            size = t.size;
            arr = (int*)memcpy(new int[size], t.arr,
                               size*sizeof(int));
        }
        return *this;
    }
};
int ArrInt::ID = 0;

int main() {
    int arr[] = {1,2,3};
    int size  = sizeof(arr)/sizeof(int);

    ArrInt *pt1 = new ArrInt(arr,size);
    ArrInt   t2 = *pt1;
    ArrInt   t3(t2);

    *pt1 = t2;
}
