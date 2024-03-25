#include <iostream>
using namespace std;

void bitsInt(int k) {
    unsigned int mask = 1<<31;
    for (int i = 0; i < 32; i++, mask >>= 1) {
        cout << (k & mask ? 1 : 0);
        if (i%8 == 7) cout << " ";
    }
    cout << endl;
}

int main() {
    unsigned int k = 255<<24 | 153<<16 | 255<<8 | 255;
    cout << "k before: "; bitsInt(k);
    (k <<= 8) >>= 24;
    cout << "k  after: "; bitsInt(k);
}
