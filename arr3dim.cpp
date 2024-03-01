#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

class Arr3D {
    int  dim1, dim2, dim3;
    int* arr;
public:
    Arr3D() : dim1(1),dim2(1),dim3(1),
              arr(new int[1])
    { }

    Arr3D(int dim1, int dim2, int dim3)
        : dim1(dim1), dim2(dim2), dim3(dim3),
          arr(new int[dim1*dim2*dim3])
    { }

    Arr3D(const Arr3D& t)
        : dim1(t.dim1), dim2(t.dim2), dim3(t.dim3),
          arr((int*)memcpy(new int[dim1*dim2*dim3],
                           t.arr,
                           dim1*dim2*dim3*sizeof(int)))
    { }

    ~Arr3D() { delete [] arr; }

    Arr3D& operator=(const Arr3D&);
    int& operator()(int,int,int);
};

int& Arr3D::operator()(int n1, int n2, int n3)  {
    return *(arr + n1*dim2*dim3 + n2*dim3 + n3);
}

Arr3D& Arr3D::operator=(const Arr3D& t) {
    if ( this != &t ) {
        delete [] arr;
        dim1 = t.dim1;
        dim2 = t.dim2;
        dim3 = t.dim3;
        arr  = (int*)memcpy(new int[dim1*dim2*dim3],
                            t.arr,
                            dim1*dim2*dim3*sizeof(int));
    }
    return *this;
}

int main() {
    int dim1 = 1000, dim2 = 1000, dim3 = 50;

    Arr3D T1(dim1,dim2,dim3), T2;

    for (int i = 0; i < dim1; i++)
        for (int j = 0; j < dim2; j++)
            for (int k = 0; k < dim3; k++)
                T1(i,j,k) = i+j+k;
    T2 = T1;

    cout << "T2(999, 999 , 2) = "
         << setw(4) << T2(999,999,2) << endl;

    cout << "T2(  0,    0, 9) = "
         << setw(4) << T2(  0,  0,9) << endl;
}
