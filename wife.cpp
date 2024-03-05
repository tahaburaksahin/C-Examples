#include <iostream>
#include <cstring>   // strcpy
using namespace std;

struct Husband;
struct Wife;

void prinfo(const Husband*);
void prinfo(const Wife*);

struct Wife {
    Husband *hus;
    char name[20];
} heather = { 0, "Heather" } ;

struct Husband {
    Wife *wif;
    char name[20];
} anthony  = { 0 } ;

int main() {
    strcpy(anthony.name, "Anthony");

    anthony.wif    = &heather;
    heather.hus = &anthony;

    Husband zachary  = { 0, "Zachary" };
    Wife    cecilia = { 0, "Cecilia"};

    prinfo(&anthony);
    prinfo(&heather);
    prinfo(&zachary);
    prinfo(&cecilia);
}

void prinfo(const Husband *h) {
    cout << "Man:   " << h->name;
    if ( h->wif )
        cout << "; wife    "
             << h->wif->name << "\n";
    else
        cout << "; (single)\n";
}

void prinfo(const Wife *w) {
    cout << "Woman: " << w->name;
    if ( w->hus )
        cout << "; husband "
             << (*((*w).hus)).name << "\n";
    else
        cout << "; (single)\n";
}
