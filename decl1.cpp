#include <iostream>
using namespace std;

int main() {
    unsigned long int ul1 = 13UL;
    unsigned long     ul2 = 0xD;  // 13 in hex
    signed   short    ss1 = 015;  // 13 in oct
    short             ss2 = 13;   // 13 in dec
    unsigned char     aa1 = 65;
    signed   char     aa2 = 'A';  // ASCII('A') = 65
    int               aa3 = 65;
    int               aa4 = 'A';
    char              aa5 = '\101';   // 65 in oct
    char              aa6 = '\x41';   // 65 in hex
    cout << aa1 << " " << aa2 << endl
         << aa3 << " " << aa4 << endl
         << aa5 << " " << aa6 << endl;
}
