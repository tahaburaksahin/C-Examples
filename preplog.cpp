#if   defined(POL) && defined(FRA)
   #error Please define only one country
#elif !(defined(POL) || defined(FRA))
   #error Please define a country
#endif

#ifdef POL
   #define country "Poland"
   #define capital "Warsaw"
#elif defined(FRA)
   #define country "France"
   #define capital "Paris"
#endif

#include <iostream>
using namespace std;

int main() {
    cout << capital << " is the capital of "
         << country << "." << endl;
    return 0;
}
