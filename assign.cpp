#include <iostream>
using namespace std;

int main()
{
    int k;
    while ( (k = cin.get()) != '\n' )
        cout << "Entered char '"     << (char)k
             << "' with ASCII code " << k << endl;
}
