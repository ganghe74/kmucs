#include <bits/stdc++.h>
using namespace std;

class Car {
public:
    Car(int x, int y) : x(x), y(y) {}
    friend ostream& operator<<(ostream& os, Car& obj);
private:
    int x, y;
};

ostream& operator<<(ostream& os, Car& obj) {
    cout << "(" << obj.x << "," << obj.y << ")" << endl;
}

int main() {
    Car c1(3,4);
    cout << c1;
}