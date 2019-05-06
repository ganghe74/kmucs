#include <iostream>
using namespace std;
int main() {
    char ar[] = "Great People";
    char ars[2][3][10] = {
        {"LEE", "KIM", "KIM"},
        {"YOU", "UL", "SIN"}
    };

    printf("ar = %s\n", ar);
    printf("ars[1][1] = %s\n", ars[1][1]);
}