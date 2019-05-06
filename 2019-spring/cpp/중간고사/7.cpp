#include <iostream>
using namespace std;

void f(int **ptr, int n) {
    *ptr = new int[n];
    int *a = *ptr;
    for (int i=0;i<n;++i) a[i] = 2*i + 1;
}

void f2(int *&ptr, int size) {
    ptr = new int[size]();
    for (int i=0, num=0;i<size;++num) {
        if (!(num % 2)) continue;

        *(ptr + i++) = num;
    }
}

int main() {
    int *arr;
    int n = 10;
    f(&arr, n);
    for (int i=0;i<n;++i) printf("%d ", arr[i]);
}