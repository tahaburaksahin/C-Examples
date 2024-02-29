#include <iostream>

long long factorial(int n) {
    return n < 2 ? 1 : n*factorial(n-1);
}

int main() {
    for (auto n : {12, 14, 16, 18, 20}) {
        if (auto f = factorial(n); f > 1e17)
            std::cout << f << " is really big\n";
        else
            std::cout << f << " is not so big\n";
    }
}
