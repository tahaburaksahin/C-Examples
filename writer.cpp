#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

void insertionSort(string[],int);

int main() {
    int i;
    string writers[] = {
        string("Lampedusa"), string("Shakespeare"),
        string("Babel"),     string("Goethe"),
        string("Kafka"),     string("Schulz")
                        };

    const int ile = sizeof(writers)/sizeof(string);

    insertionSort(writers, ile);

    for ( i = 0; i < ile; i++ )
        cout << setw(11) << writers[i] << endl;
}

void insertionSort(string a[], int size) {
    if ( size <= 1 ) return;

    for ( int i = 1 ; i < size ; ++i ) {
        int j = i;
        string v = a[i];
        while ( j >= 1 && v < a[j-1] ) {
            a[j] = a[j-1];
            j--;
        }
        a[j] = v;
    }
}
