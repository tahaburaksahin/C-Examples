#include <vector>
#include <iostream>
using namespace std;

struct Person {
    char name[20];
    int  year;
    void print() const {
        cout << name << "-" << year << endl;
    }
} john = {"John",25}, mary = {"Mary",18}, sue = {"Sue",9};


void printPerson(const vector<const Person*>& list) {
    for (auto it = list.cbegin(); it != list.cend(); it++)
        (*it)->print();
}

int main() {
    vector<const Person*> list;

    list.push_back(&john);
    list.push_back(&mary);
    list.push_back(&sue);

    printPerson(list);
}
