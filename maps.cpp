#include <iostream>
#include <iomanip>   // left, setw
#include <string>
#include <map>
#include <utility>   // pair
#include <algorithm>
using namespace std;

using Emp = pair<string,int>;
using MAP = map<string,Emp>;

class Range {
    int min,max;
public:
    Range(int min,int max) : min(min), max(max) {}

    bool operator()(const pair<const string,Emp>& p) const {
        int salary = p.second.second;
        return  (min < salary) && (salary < max);
    }
};

void print(const MAP& m) {
    for (auto [key, emp] : m) {
        auto [name, sal] = emp;
        cout << "Key: "    << left << setw(7) << key
             << "Name: "   << setw(10) << name
             << "Salary: " << sal << endl;
    }
}

int main() {
    MAP emp;

    emp["sue"]   = Emp("Sue K.",   1900);
    emp["jill"]  = Emp("Jill M.",  2100);
    emp["eve"]   = Emp("Eve S.",   3100);
    emp["boss"]  = Emp("Boss",     9900);
    emp["jane"]  = Emp("Jane A.",  1600);
    emp["emily"] = Emp("Emily P.", 2600);

    print(emp);

    int mn = 1100, mx = 2000;
    int cnt = count_if(emp.begin(),emp.end(),Range(mn,mx));

    cout << cnt << " employees have salary in range "
         << mn << " to " << mx << endl;
}
