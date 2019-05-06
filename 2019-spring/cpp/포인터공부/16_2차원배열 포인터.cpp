#include <iostream>
using namespace std;
int main() {
    int ar[3][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};

    printf("ar[2][1] = %d\n", ar[2][1]);
    printf("ar[2][1] = %d\n", *(*(ar+2)+1));

    printf("sizeof(ar) = %d\n", sizeof(ar));
    printf("sizeof(ar+2) = %d\n", sizeof(ar+2));
    printf("sizeof(*(ar+2)) = %d\n", sizeof(*(ar+2)));
    printf("sizeof(*(ar+2)+1) = %d\n", sizeof(*(ar+2)+1));
}