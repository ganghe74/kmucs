#include <iostream>
using namespace std;
int main() {

    const char *a[] = {"Coding", "never", "fail", "me", "Good", "luck"};
    

    char arr[5][7][6];
    char (*p)[5][7][6] = &arr;

    printf("%p\n%p\n", &arr, &arr+1);
    printf("%d\n", (&arr + 1) - &arr); // 210
    printf("%d\n", (char *)(&arr + 1) - (char *)(&arr)); // 210
    printf("%d\n", (unsigned)(*(arr + 1)) - (unsigned)(*arr));
    printf("%d\n", (unsigned)(arr + 1) - (unsigned)arr); // 42
    printf("%d\n", (unsigned)(p+1) - (unsigned)p); // 210
}