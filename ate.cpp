#include <vector>
#include <stdexcept>
#include <iostream>
#include <string>
using namespace std;

int main() {
    vector<string> vs;

    vs.push_back("Mary");
    vs.push_back("Lucy");
    vs.push_back("Ella");
    vs.push_back("Jill");

    try {
        for ( int i = 0; i < 5 /* ERROR */; i++ )
            cout << vs.at(i) << " " ;
    } catch(out_of_range) {
        cout << "\n*** Bad index! *** "
             << " vector has only " << vs.size()
             << " elements!" << endl;
    }
    cout << endl;

    cout << "First element: " << vs.front() << endl;
    cout << "Last  element: " << vs.back()  << endl;

    vs.pop_back();

    cout << "After pop_back: ";
    int size = (int)vs.size();
    for ( int i = 0; i < size; i++)
        cout << vs[i] << " " ;
    cout << endl;
}
