#include <iostream>
#include <cmath>     // sin, cos
using namespace std;

struct Point {
    double x, y;
};

struct Triangle {
    Point A, B, C;
};

void info(const Point*);
void info(const Triangle*);
void rot(Point*,double);
void rot(Triangle*,double);

int main() {
    Point A;
    A.x = -1;
    A.y =  2;

    Point B = { -1, 1 };

    Point C = { 2 };
    C.y = -1;

    Triangle T = { A, B };
    T.C = C;

    cout << "Initial points: ";
    info(&A); info(&B); info(&C);
    cout << "\nTriangle: ";
    info(&T);
    cout << endl;

    rot(&A,90); rot(&B,90); rot(&C,90);
    cout << "A, B, C after rot. through 90 deg:\n    ";
    info(&A); info(&B); info(&C);
    cout << endl;

    rot(&T,90); rot(&T,90);
    cout << "T after rot. through  90 deg. twice:\n    ";
    info(&T);

    rot(&T,180);
    cout << "T after rot. through 180 deg. again:\n    ";
    info(&T);
}

void info(const Point* pP) {
    cout << "(" << pP->x << ", " << pP->y << ") ";
}

void info(const Triangle* pT) {
    cout << "A="; info(&pT->A);
    cout << "B="; info(&pT->B);
    cout << "C="; info(&pT->C);
    cout << endl;
}

void rot(Point* pP, double phi) {
    static double conver = atan(1.)/45;
    phi = phi*conver; // degrees -> radians

    double c = pP->x;
    pP->x = pP->x * cos(phi) - pP->y * sin(phi);
    pP->y =     c * sin(phi) + pP->y * cos(phi);
}

void rot(Triangle* pT, double phi) {
    rot( &pT->A, phi);
    rot( &pT->B, phi);
    rot( &pT->C, phi);
}
