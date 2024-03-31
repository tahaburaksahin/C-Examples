#include <iostream>

class A {
public:
    int i;
    double x;
};

void pr(const A* p) {
    std::cout << p->i << ", " << p->x << '\n';
}

int main() {
    A a1{1, 2.5};
    A a2;
    A a3{};
    A* pa4 = new A{3, 4.5};
    A* pa5 = new A{};
    pr(&a1); pr(&a2); pr(&a3); pr(pa4); pr(pa5);
}

