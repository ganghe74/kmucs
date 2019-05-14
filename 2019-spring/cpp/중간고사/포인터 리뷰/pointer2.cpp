#include <iostream>
using namespace std;

void foo(int *&x, int**&y) {
    int z = 55, w = 555;
    *&x = &z;
    **&y = &w;
}

int main() {
    int val = 42;
    int *a = &val;
    int **b = &a;

    cout << "*a " << *a << " " << "**b :" << **b << endl;
    foo(a, b);
    cout << "*a " << *a << " " << "**b :" << **b << endl;
}