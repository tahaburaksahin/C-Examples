#include <iostream>
#include <vector>
#include <memory>

struct B {
    virtual void f() { std::cout << "f from B\n"; }
    virtual ~B() { }
};
struct D : B {
    D() { std::cout << "Ctor D\n"; }
    void f() override { std::cout << "f from D\n"; }
    ~D(){ std::cout << "Dtor D\n"; }
};

int main() {
    {
        std::vector<std::unique_ptr<B>> vec;
        vec.push_back(std::make_unique<B>());
        vec.push_back(std::make_unique<D>());
        vec.emplace_back(std::make_unique<D>());
        std::unique_ptr<B> d{new D};
        vec.push_back(std::move(d));
        for (const auto& up : vec) up->f();
    }
    std::cout << "now vec is out of scope\n";
}
