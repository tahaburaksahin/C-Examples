#include <iostream>
#include <functional>
using std::cout; using std::endl;

double square(double x) {
    return x*x;
}

void invoke(std::function<double(double)> f, double arg) {
    double res = f(arg);
    cout << "invoke(" << arg << ")=" << res << endl;
}

int main() {
      // auxiliary lambda function
    auto print =
        [](double p1, double p2, double p3,
           double arg, double val) -> void
        {
            cout << " a=" << p1 << " b=" << p2
                 << " c=" << p3 << " x=" << arg
                 << " res=" << val << endl;
        };

      // lambda function a*x*x+b*x+c
    int a = 1, b = 1, c = 1;
      // all local variables captured by value
    auto pol1 =
        [=](double x) -> double
        {
            double res = c+x*(b+x*a);
            print(a,b,c,x,res);
            return res;
        };
    cout << "pol1=" << pol1(2) << endl;
    a = b = c = 2;
    cout << "pol1=" << pol1(2) << endl << endl;

      // all local variables captured by reference
    auto pol2 =
        [&](double x) -> double
        {
            double res = c+x*(b+x*a);
            print(a,b,c,x,res);
            return res;
        };
    cout << "pol2=" << pol2(2) << endl;
    a = b = c = 1;
    cout << "pol2=" << pol2(2) << endl << endl;

      // a and c by reference, b and print by value
    auto pol3 =
        [&a,b,&c,print](double x) -> double
        {
            double res = c+x*(b+x*a);
            print(a,b,c,x,res);
            return res;
        };
    cout << "pol3=" << pol3(2) << endl;
    a = b = c = 2;
    cout << "pol3=" << pol3(2) << endl << endl;

      // type specified explicitly
    std::function<double(double)> f = pol3;
    invoke(f,2);
      // converting 'plain' function pointer
    invoke(square,2);
    f = square;
    invoke(f,2);
      // lambda as an argument
    invoke([](double x) {return x*x*x;}, 3);

      // void->void only needs brackets and a body
    [] {
        cout << "Done" << endl;
    }(); // construct a function and invoke it immediately
}
