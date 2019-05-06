#include <iostream>
using namespace std;

int find_number(int a[], int n, int find) {
    for (int i=0;i<n;++i) {
        if (a[i] == find) return i;
    }
    return -1;
}

int main() {
    int a[5] = {1,2,3,4,5};
    cout << find_number(a, 5, 3);
}