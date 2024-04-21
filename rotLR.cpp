#include <bit>      // std::rotl, std::rotr
#include <cstdint>
#include <iostream>

template <typename T>
std::string showBits(T t) {
    size_t sz = 8*sizeof(T);
    std::string s(sz, ' ');
    for (size_t i = 0, j = sz-1; i < sz; ++i, --j)
        s[j] = (t & (1 << i)) ? '1' : '0';
    return s;
}

// C++20 required

int main() {
    using std::cout; using std::rotr; using std::rotl;

    std::uint8_t n = 0b01001101;
    cout << "n          : " << showBits(n) << '\n';
    cout << "n rotl by 2: " << showBits(rotl(n, 2)) << '\n';
    cout << "n rotl by 3: " << showBits(rotl(n, 3)) << '\n';
    cout << "n rotr by 2: " << showBits(rotr(n, 2)) << '\n';
    cout << "n rotr by 3: " << showBits(rotr(n, 3)) << '\n';
}
