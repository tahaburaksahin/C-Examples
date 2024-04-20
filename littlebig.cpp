#include <iostream>
using namespace std;

int main() {
    // higher byte: 'a'; lower byte: 'b'
    short sh = 'b'+256*'a';

    void *v = static_cast<void*>(&sh);
    char *c = static_cast<char*>(v);
    cout << "Order in memory: first "
         << c[0] << " then " << c[1] << endl;
}
