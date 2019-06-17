#include <bits/stdc++.h>
using namespace std;

class Point{
public:
    int x, y;
    Point(int a) {
        x = a;
        y = 0;
    }
    Point(int a, int b) {
        x = a;
        y = b;
    }
    void print() {
        cout << "(" << x << "," << y << ")" << endl;
    }
    operator int() {
        return x;
    }
};

int main() {
    Point p1 = 10;
    p1.print();
    cout << p1;
}