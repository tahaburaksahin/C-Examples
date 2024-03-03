#include <iostream>
#include <iomanip>   /* setw */
using namespace std;

struct Writer{
    int   born;
    char  name[40];
};

void insertionSort(Writer*[],int);

int main() {
    Writer gl = {1896,"Giuseppe Tomasi di Lampedusa"},
           ws = {1564,         "William Shakespeare"},
           ib = {1894,                 "Isaak Babel"},
           jg = {1749,  "Johann Wolfgang von Goethe"},
           fk = {1883,                 "Franz Kafka"},
           bs = {1892,                "Bruno Schulz"};

    Writer* writers[] = { &gl,&ws,&ib,&jg,&fk,&bs };

    const int ile = sizeof(writers)/sizeof(writers[0]);

    cout << "sizeof(Writer )=" << sizeof(Writer ) << endl;
    cout << "sizeof(Writer*)=" << sizeof(Writer*) << endl
                                                  << endl;
    insertionSort(writers, ile);

    for ( int i =0; i < ile; i++ )
        cout << setw(28) << writers[i]->name
             << setw(5)  << writers[i]->born << endl;
}

void insertionSort(Writer* a[], int size) {
    if ( size <= 1 ) return;

    for ( int i = 1 ; i < size ; ++i ) {
        int j = i;
        Writer* v = a[i];
        while ( j >= 1 && v->born < a[j-1]->born ) {
            a[j] = a[j-1];
            j--;
        }
        a[j] = v;
    }
}
