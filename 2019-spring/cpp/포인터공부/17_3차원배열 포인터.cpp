#include <iostream>
using namespace std;
int main() {
    int a[10][5][2] ={5};

    int i = 1;
    int *p = &i;
    printf("sizeof(p) = %d\n", sizeof(p));
    printf("sizeof(*p) = %d\n", sizeof(*p));

    //p = a;
    //p = a + 0;
    //p = a[0];

    printf("sizeof(a) = %d\n", sizeof(a));
    printf("sizeof(a+0) = %d\n", sizeof(a+0));
    printf("sizeof(a+1) = %d\n", sizeof(a+1));
    printf("sizeof(*(a+1)) = %d\n", sizeof(*(a+1)));
    printf("sizeof(*(a+1)+1) = %d\n", sizeof(*(a+1)+1));
    printf("sizeof(*(*(a+1)+1) = %d\n", sizeof(*(*(a+1)+1)));
}