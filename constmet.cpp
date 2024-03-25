#include <iostream>
using namespace std;

class Point {
    double x, y;
public:
    Point(double x, double y) {
        this->x = x;
        this->y = y;
    }
    Point translate(double dx, double dy) const;
    void  translate(double dx, double dy);
};

Point Point::translate(double dx, double dy) const {
    cout << "const translate\n";
    return Point(x+dx,y+dy);
}

void Point::translate(double dx, double dy) {
    cout << "nonconst translate\n";
    x += dx;
    y += dy;
}

int main() {
    const Point p1(1,1);
    Point p2(2,2);

    p1.translate(3,3);
    p2.translate(4,4);
}
