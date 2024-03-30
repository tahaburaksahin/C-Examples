#include <iostream>
#include <memory>

using std::unique_ptr; using std::ostream; using std::cout;

template <typename T>
struct Del {
    void operator()(T* p) {
        cout << "Del deleting " << *p << '\n';
        delete p;
    }
};

struct Klazz {
    Klazz()  { cout << "Ctor Klazz\n"; }
    ~Klazz() { cout << "Dtor Klazz\n"; }
    friend ostream& operator<<(ostream& s, const Klazz& k) {
        return s << "object of type Klazz";
    }
};

int main() {
    std::cout << "Creating  u-pointer\n";
    std::unique_ptr<Klazz, Del<Klazz>>
                           p(new Klazz{}, Del<Klazz>{});
    std::cout << "Resetting u-pointer\n";
    p.reset(new Klazz{});
    std::cout << "Releasing and deleting\n";
    p.reset(); // or reset(nullptr)
}
