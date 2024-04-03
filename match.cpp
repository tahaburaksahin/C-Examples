#include <iostream>
#include <string>
using namespace std;

string fun1(   int) { return "\'int\'\n";    }
string fun1(  char) { return "\'char\'\n";   }
string fun1(double) { return "\'double\'\n"; }

string fun2( short) { return "\'short\'\n";  }
string fun2(double) { return "\'double\'\n"; }

int main() {
    int    kin =   0;
    char   kch = '\0';
    float  kfl =   0;
    double kdo =   0;

    cout << "fun1(   int) -> " << fun1(kin);
    cout << "fun1(  char) -> " << fun1(kch);
    cout << "fun1( float) -> " << fun1(kfl);
    cout << "fun1(double) -> " << fun1(kdo);

    cout << "fun2( float) -> " << fun2(kfl);
  //cout << "fun2(  char) -> " << fun2(kch);
  //cout << "fun2(   int) -> " << fun2(kin);
}
