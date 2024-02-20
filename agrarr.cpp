#include <iostream>
using namespace std;

class AClass {
public:
    char name[4];
    int  age;
};

int main() {
    AClass arr[5] = {{"Joe",11},{"Sue",17},
                     {"Ian",26},{"Jim",29}};
    arr[4].age = 22;

    for (int i = 0; i < 5; i++)
        cout << arr[i].name << ";  "
             << arr[i].age  << " years old" << endl;
}
