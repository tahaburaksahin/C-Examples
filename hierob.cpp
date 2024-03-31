#include <iostream>
using namespace std;

class A { };
class B : public A { };

int main() {
    try {
        throw B();
    }
    catch(A) { cout << "A" << endl; }
    catch(B) { cout << "B" << endl; }
}
