#include <iostream>
#include <cstring>
using namespace std;

class Customer {
    static int ID;
    char*  name;
    const  int id;
    int    cr,db;

public:
    class Balance {
        int id;
        int balance;
    public:
        Balance(int id, int balance)
            : id(id), balance(balance)
        {}

        void printinfo();
    };

    Customer(const char* n)
        : name(strcpy(new char[strlen(n)+1],n)),
          id(++ID), cr(0), db(0)
    {}

    Customer& credit(int w) { cr += w; return *this; }
    Customer&  debit(int w) { db += w; return *this; }

    Balance* getBalance();

    ~Customer() { delete [] name; }
};
int Customer::ID = 0;

Customer::Balance* Customer::getBalance() {
    return new Balance(id, cr - db);
}

void Customer::Balance::printinfo() {
    cout << "id: " << id << " Balance: " << balance << endl;
}

int main() {
    Customer  joh("Johnson");
    Customer* pshe = new Customer("Sheldon");

    joh.credit(100).credit(50).debit(75);
    pshe->credit(200).debit(50).debit(25);

    Customer::Balance* psjoh =   joh.getBalance();
    Customer::Balance* psshe = pshe->getBalance();

    psjoh->printinfo();
    psshe->printinfo();

    Customer::Balance anonim(9,500);
    anonim.printinfo();

    delete psjoh;
    delete psshe;
    delete pshe;
}
