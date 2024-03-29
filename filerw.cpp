#include <iostream>
#include <fstream>
using namespace std;

int main() {
    int tab[] = { 97, 105, 115, 255, 111 },k;

    int size = sizeof(tab)/sizeof(tab[0]);

    cout << "Array of size: " << size << endl;
    for (int i = 0; i < size; ++i)
        cout << tab[i] << " ";
    cout << endl;

    ofstream file_out("file.dat",ios::out|ios::binary);
    if (! file_out ) {
        cout << "Can\'t open file_out" << endl;
        return -1;
    }

    file_out.write((char*)tab, sizeof(tab));
    file_out.close();

    fstream file("file.dat",ios::in|ios::out|ios::binary);
    if (! file ) {
        cout << "Can\'t open file" << endl;
        return -1;
    }

    file.seekg(0,ios::end);
    streamsize len = file.tellg();
    cout << "File has length " << len << " bytes\n";
    file.seekg(0);

    cout << "Bytes in file:" << endl;
    while ( (k = file.get()) != EOF )
        cout << k << " ";
    cout << endl;

    file.clear(); // <-- NECESSARY !!!

    file.seekg(4);
    file.read((char*)&k,4);
    cout << "Integer from position 4: " << k << endl;

    file.seekp(12);
    file.write((char*)&k,4);

    file.seekg(0);
    cout << "Bytes in file now:" << endl;
    while ( (k = file.get()) != EOF )
        cout << k << " ";
    cout << endl;

    file.close();
}
