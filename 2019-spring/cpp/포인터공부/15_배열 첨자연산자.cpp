#include <iostream>
using namespace std;
int main() {
    int ar[5]  {1,2,3,4,5};

    printf("ar[2] = %d\n", ar[2]);
    printf("ar[2] = %d\n", *(ar+2));
    printf("ar[2] = %d\n", 2[ar]);
}