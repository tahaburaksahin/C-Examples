#include <iostream>
using namespace std;

int convert(char* str) {
    int w = 0, i = 0, c;
    while (c = str[i++], c >= '0' && c <= '9')
        w = 10*w + c - '0';
    return w;
}

int main() {
    char tab1[] = "123a";
    char tab2[] = "456 1";
    char tab3[] = " 56";

    cout << "tab1 -> " << convert(tab1) << endl;
    cout << "tab2 -> " << convert(tab2) << endl;
    cout << "tab3 -> " << convert(tab3) << endl;
}
