#include <iostream>
using namespace std;

static int g = 10;
void f(int n) {
    static int g = 1;
    g += n;
    cout << ++g << endl;
}

int main() {
    f(g++);
    f(++g);
}