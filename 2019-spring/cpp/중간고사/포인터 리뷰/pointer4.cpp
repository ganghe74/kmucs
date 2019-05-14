#include <iostream>
using namespace std;

// Swap 안됨.
void swap(const char* x, const char* y) {
    const char* t = x;
    x = y;
    y = t;
}

// Swap 됨.
void real_swap(const char *&x, const char *&y) {
    const char *t = x;
    x = y;
    y = t;
}

int main() {
    const char *x = "Today";
    const char *y = "BigDay";
    const char *t;

    real_swap(x, y);
    cout << "(" << x << ", " << y << ")\n";

    t = x; x = y; y = t;

    cout << "(" << x << ", " << y << ")\n";
}