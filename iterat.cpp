#include <vector>
#include <iostream>
#include <string>
using namespace std;

int main() {
    vector<string> vs{"Mary", "Lucy", "Ella","Jill"};

    for ( vector<string>::iterator ite = vs.begin();
                                   ite!= vs.end(); ++ite)
        cout << *ite << " ";
    cout << endl;

    // or

    vector<string>::iterator it, kon = vs.end();

    for ( it = vs.begin(); it != kon; ++it )
        cout << *it << " ";
    cout << endl;

    // or

    using SIT=vector<string>::iterator;

    SIT iter, fin = vs.end();

    for ( iter = vs.begin(); iter != fin; ++iter )
        cout << *iter << " ";
    cout << endl;

    // or the best way to do it

    for ( auto i = vs.begin(); i != vs.end(); ++i )
        cout << *i << " ";
    cout << endl;
}
