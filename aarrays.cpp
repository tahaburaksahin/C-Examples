#include <array>
#include <cstddef>   // size t
#include <iostream>
#include <string>
using std::array; using std::cout;

void printArray(const array<int,8>& a) {
    cout << "Version <int,EIGHT>: "
         << "a.size() = " << a.size() << "\n";
    for (const auto& e : a) cout << e << " ";
    cout << "\n";
}

template <typename E, std::size_t SIZE>
void printArray(const array<E,SIZE>& a) {
    cout << "Template version: "
         << "std::size(a) = " << std::size(a) << "\n";
    for (std::size_t i = 0; i < a.size(); ++i)
        cout << a.at(i) << " ";
    cout << "\n";
}

int main() {
    array<int,8> ai{1,2,3,4,5};
    for (auto& e : ai) ++e;
    printArray(ai);

    array<std::string,5> as{"K","L","M","D"};
    for (auto& e : as) e += "!";
    printArray(as);
}
