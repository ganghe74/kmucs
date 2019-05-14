#include <iostream>
using namespace std;

void foo(int *ptr) {
    ptr = new int(50);
    cout << "In foo:\t" << *ptr << '\n';
    delete ptr;
}

void bar(int *&ptr) {
    ptr = new int(80);
    cout << "In bar:\t" << *ptr << '\n';
}

int main() {
    int temp = 100;
    int *p = &temp;

    cout << "Before foo:\t" << *p << '\n';
    foo(p);
    cout << "After foo:\t" << *p << '\n';

    cout << "Before bar:\t" << *p << '\n';
    bar(p);
    cout << "After bar:\t" << *p << '\n';
}