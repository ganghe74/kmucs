#include <iostream>
using namespace std;

int main() {
    int i;
    int *pi;
    int **ppi;

    i = 1234;
    pi = &i;
    ppi = &pi;

    printf("%d\n", **ppi);
}