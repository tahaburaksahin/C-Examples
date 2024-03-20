#include <iostream>
#include <string>
using namespace std;

class AClass {
    string name;
    int    age;
public:
    AClass(const string& name = "No Name", int age = 100) {
        this->name = name;
        this->age = age;
        cout << "ctor: " << this->name << endl;
    }

    int     getAge() { return age; }

    string getName() { return name; }
};

int main() {
    AClass ob("Adelaide");

    AClass ktab[5] = { AClass("Eleonora", 17),
                       AClass("Felicity"),
                       AClass("Merrilyn", 26),
                       ob
                     };

    for (int i = 0; i < 5; i++)
        cout << ktab[i].getName() << "; "
             << ktab[i].getAge()  << "y. old" << endl;
}
