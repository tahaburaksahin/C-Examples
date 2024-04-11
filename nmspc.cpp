#include <iostream>

namespace A {
    const int two = 2;
    const int six = 6;
    void write() { std::cout << "ns-A" << " "; }
}

namespace B {
    void write() { std::cout << "ns-B" << " "; }
}

namespace C {
    const int two = 22;
    const int six = 66;
}

int main() {
    using A::write;
    using namespace C;

    write();
    B::write();
    std::cout << six << std::endl;
}
