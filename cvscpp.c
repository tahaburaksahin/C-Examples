#ifdef __cplusplus
    #include <iostream>
    using namespace std;
#else
    #include <stdio.h>
#endif

int main() {
#ifdef __cplusplus
    cout << "Hello, C++" << endl;
#else
    printf("Hello, C\n");
#endif
}
