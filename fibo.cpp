#include <iostream>
#include <iomanip>
using namespace std;

int counter;

int fib(int n) {
    counter++;
    return (n < 2) ? n : fib(n-1) + fib(n-2);
}

int main() {
    cout << "\n  i    Fib(i)    # of calls\n"
            "---------------------------" << endl;
    for (int i = 10; i <= 43; i += 3) {
        counter = 0;
        int w = fib(i);
        cout << setw(3)  << i << setw(12) << w
             << setw(12) << counter << endl;
    }
}
