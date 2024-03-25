#include <iostream>
using namespace std;

void changeFirst(char* str, char c) {
    str[0]=c;
}

int main() {
    const char name[] = "Jenny";
    cout << name << endl;

    // name[0]='K';

    changeFirst(const_cast<char*>(name),'K');

    // changeFirst(name,'K');

    cout << name << endl;
}
