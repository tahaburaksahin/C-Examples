#include <iostream>
#include <cmath>
using std::cout; using std::endl;

struct Point {
    double x, y;
    Point(double x = 0, double y = 0) : x(x), y(y) { }
    operator double() const {
        return std::sqrt(x*x+y*y);
    }
};

struct Segment {
    Point A, B;
    Segment(Point A = Point(), Point B = Point())
        : A(A), B(B)
    { }
    operator Point() const {
        return Point( (A.x+B.x)/2, (A.y+B.y)/2 );
    }
};

void showPoint(Point A) {
    cout << "Point[" << A.x << "," << A.y << "]";
}

void showSegment(Segment AB) {
    cout << "Segment: ";
    showPoint(AB.A);
    cout << "--";
    showPoint(AB.B);
    cout << endl;
}

void showDouble(double d) {
    cout << "Double " << d;
}

int main() {
    Point A(3,4);
    showPoint(A);
    cout << endl;
    showDouble(A);

    cout << endl;

    Segment BC(Point(1,1),Point(3,3));
    showSegment(BC);
    showPoint(BC);

    cout << endl;
}
