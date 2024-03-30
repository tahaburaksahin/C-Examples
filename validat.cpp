#include <fstream>
#include <iostream>
using namespace std;

int main() {
    const int DIM = 80;
    char      name[DIM];
    ifstream  infile;
    double    x;

    do {
        cout << "Name of input file: ";
        cin.getline(name, DIM);

        infile.clear();
        infile.open(name);
    } while (!infile);

    cout << "File = " << name << endl;
    infile.close();

    do {
        if (!cin) {
            // order important!
            cin.clear();
            cin.ignore(1024,'\n');
        };
        cout << "Enter a number: ";
        cin >> x;
    } while (!cin);

    cout << "Number = " << x << endl;
}
