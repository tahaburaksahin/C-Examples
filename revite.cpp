#include <vector>
#include <iostream>
#include <string>
using namespace std;

int main() {
    vector<string> vs{"Mary", "Lucy", "Ella", "Jill"};

    for (auto r = vs.rbegin(); r != vs.rend(); ++r)
        cout << *r << " ";
    cout << endl;
}
