#include <iostream>
using namespace std;

void fun1(double t[]) {
   cout << "Size of \'t\' in fun1: " << sizeof(t) << endl;
   cout << "Value of *t in fun1: "   << t[0]      << endl;
}

void fun2(double* t) {
   cout << "Size of \'t\' in fun2: " << sizeof(t) << endl;
   cout << "Value of *t in fun2: "   << t[0]      << endl;
}

int main() {
   double t[] = {6,2,3,2,1};
   cout << "Size of \'t\' in main: " << sizeof(t) << endl;
   cout << "Value of *t in main: "   << *t        << endl;
   fun1(t);
   fun2(t);
}
