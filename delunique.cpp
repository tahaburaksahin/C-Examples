#include <functional>
#include <iostream>
#include <memory>
#include <string>

using std::unique_ptr; using std::string;

template <typename T>
struct Del {
    void operator()(T* p) {
        std::cout << "Del deleting " << *p << '\n';
        delete p;
    }
};

int main() {
    {
        unique_ptr<string, Del<string>>
            us{new string{"Hello"}, Del<string>{}};
    }
    std::cout << "us is now out of scope\n";

    {
        unique_ptr<double, std::function<void(double*)>>
            ud{new double{7.5},
               [](double* p) {
                   std::cout << "Deleting " << *p << '\n';
                   delete p;
               }
            };
    }
    std::cout << "ud is now out of scope\n";
}
