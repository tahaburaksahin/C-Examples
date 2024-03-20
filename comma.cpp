#include <iostream>
using namespace std;

int main() {
    int r = 0;
    int k;

    while (cin >> k, k) {
       r += k > 0 ? (cout << "Positive\n" , +1)
                  : (cout << "Negative\n" , -1);
    }
    cout << "Number of positive - Number of negative : "
         << r << endl;
}
