#include <iostream>
using namespace std;

class My2Vector {
public:
    My2Vector() : x(0), y(0) {};
    My2Vector(int coordX, int coordY) : x(coordX), y(coordY) {};

    My2Vector operator+(const My2Vector& obj) {
        return My2Vector(x + obj.x, y + obj.y);
    };
    My2Vector operator*(int c) {
        return My2Vector(c * x, c * y);
    };
    friend ostream& operator<<(ostream& os, const My2Vector& v);
private:
    int x, y;
};

ostream& operator<<(ostream& os, const My2Vector& v) {
    cout << "(" << v.x << "," << v.y << ")";
    return os;
}

int main() {    
    int numTestCases;
    cin >> numTestCases;

    for (int i=0;i<numTestCases;++i) {
        int coordX, coordY;
        cin >> coordX >> coordY;
        My2Vector v1(coordX, coordY);

        cin >> coordX >> coordY;
        My2Vector v2(coordX, coordY);

        cout << v1 << " " << v2 << endl;
        cout << v1*2 + v2*3 << endl;
    }
}