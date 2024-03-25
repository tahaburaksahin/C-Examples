#include <iostream>
using namespace std;

struct Point {
    int x, y;
    Point(int x = 0, int y = 0) : x(x), y(y) { }
};

struct Segment {
    Point A, B;
    // explicit
    Segment(Point A = Point(), Point B = Point())
        : A(A), B(B)
    { }
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

int main() {
    int k = 7;
    showPoint(k);

    cout << endl;

    Point A(1,1);
    showSegment(A);
    // showSegment(k);
}
