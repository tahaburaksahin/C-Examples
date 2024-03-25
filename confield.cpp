#include <iostream>
#include <cstring>
using namespace std;

// Note: incomplete classes - assignment
// operator should be overloaded here

class Employee;

enum position {plain, boss, CEO};

class Person {
    char* name;
    int   birth_year;

      // declaration of friendship
    friend void emplinfo(const Employee*);
public:
    Person(char* n, int r)
        : name(strcpy(new char[strlen(n)+1],n)),
          birth_year(r)
    { }

      // copy-ctor
    Person(const Person& p)
        : name(strcpy(new
              char[strlen(p.name)+1],p.name)),
          birth_year(p.birth_year)
    { }

      // dtor
    ~Person() {
        cout << "Deleting person " << name << endl;
        delete [] name;
    }
};

class Employee {
    static int     ID;
    Person       pers;
    const int &income;
    const int      id;

      // declaration of friendship
    friend void emplinfo(const Employee*);
public:
    Employee(char* n, int r, int& sal)
        : pers(n,r), income(sal), id(++ID)
    { }

      // copy-ctor
    Employee(const Employee& e)
        : pers(e.pers), income(e.income), id(++ID)
    { }
};
int Employee::ID;

void emplinfo(const Employee* empl) {
    cout << empl->pers.name          << " (born "
         << empl->pers.birth_year    << ") id="
         << empl->id << "; income: " << empl->income
                                     << endl;
}

int main() {
    int salary[] = { 1600, 2100, 8900 };

    Employee johny(  "Johny   ", 1978, salary[plain]);
    Employee billy(  "Billy   ", 1980, salary[plain]);
    Employee henry(  "Henry   ", 1965, salary[boss]);
    Employee MrHenry("Mr Henry", 1955, salary[CEO]);

    emplinfo(&johny);
    emplinfo(&billy);
    emplinfo(&henry);
    emplinfo(&MrHenry);

    cout << "\nChanging salaries\n\n";

    salary[plain] -=  300;
    salary[CEO] += 1000;

    emplinfo(&johny);
    emplinfo(&billy);
    emplinfo(&henry);
    emplinfo(&MrHenry);

    cout << "\nEnd of program\n\n";
}
