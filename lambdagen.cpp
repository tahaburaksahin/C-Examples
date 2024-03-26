#include <iostream>

int main() {
    using namespace std::literals;

    auto pr = [] (auto e) {
        std::cout << "Result is " << e << '\n';
    };
    auto f = [] (auto e1, auto e2) {
        return e1 < e2 ? e1 : e2;
    };
    auto ri = f(3, 1);
    pr(ri);
    auto rs = f("Cindy"s , "Alice"s);
    pr(rs);
}
