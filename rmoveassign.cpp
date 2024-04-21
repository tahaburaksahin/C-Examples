#include <cstring>
#include <iostream>
#include <utility>   // move

using std::cout; using std::endl;

class Arr {
    size_t size;
    int*    arr;
public:
    Arr(size_t s, const int* a)
        : size(s),
          arr(static_cast<int*>(
              std::memcpy(new int[size],a,
                          size*sizeof(int))))
    {
        cout << "ctor from array\n";
    }
    Arr(const Arr& other)
        : size(other.size),
          arr(static_cast<int*>(
              std::memcpy(new int[size],other.arr,
                          size*sizeof(int))))
    {
        cout << "copy-ctor\n";
    }
    Arr(Arr&& other) noexcept
        : size(other.size), arr(other.arr)
    {
        other.size = 0;
        other.arr = nullptr;
        cout << "move-ctor\n";
    }
    Arr& operator=(const Arr& other) {
        if (this == &other) return *this;
        int* a = new int[other.size];
        memcpy(a,other.arr,other.size*sizeof(int));
        delete [] arr;
        size = other.size;
        arr = a;
        cout << "copy-assign\n";
        return *this;
    }
    Arr& operator=(Arr&& other) noexcept {
        if (this == &other) return *this;
        delete [] arr;
        size = other.size;
        arr  = other.arr;
        other.size = 0;
        other.arr  = nullptr;
        cout << "move-assign\n";
        return *this;
    }
    ~Arr() {
        delete [] arr;
    }
    friend std::ostream& operator<<(std::ostream& str,
                                    const Arr& a) {
        if (a.size == 0) return cout << "Empty";
        str << "[ ";
        for (size_t i = 0; i < a.size; ++i)
            str << a.arr[i] << " ";
        return str << "]";
    }
};

Arr replicate(Arr a) {
    cout << "In replicate\n";
    return a;
}

int main() {
    cout << "**** 0 ****\n";
    int a[]{1,2,3,4};
    Arr arr(std::size(a),a);
    cout << "arr : " << arr  << endl;

    cout << "**** 1 ****\n";
    Arr arr1 = replicate(arr);
    cout << "arr1: " << arr1 << endl;
    cout << "arr : " << arr  << endl;

    cout << "\n**** 2 ****\n";
    arr = arr1;
    cout << "arr : " << arr  << endl;
    cout << "arr1: " << arr1 << endl;

    cout << "\n**** 3 ****\n";
    Arr arr2 = replicate(std::move(arr));
    cout << "arr2: " << arr2 << endl;
    cout << "arr : " << arr  << endl;

    cout << "\n**** 4 ****\n";
    arr  = replicate(std::move(arr2));
    cout << "arr : " << arr  << endl;
    cout << "arr2: " << arr2 << endl;

    cout << "\n**** 5 ****\n";
    arr2 = std::move(arr);
    cout << "arr2: " << arr2 << endl;
    cout << "arr : " << arr  << endl;
}
