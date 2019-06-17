#include <bits/stdc++.h>
using namespace std;

class Shape {
public:
    virtual void print() {
        cout << "Shape::print()" << endl;
    }
};

class Shape2 {
public:
    void draw() {
        cout << "Shape2::draw()" << endl;
    }
};

class Triangle : public Shape, public Shape2 {
public:
    void print() {
        cout << "Triangle::print()" << endl;
    }
};

class TriangleEx : public Triangle {
public:
    void print() {
        cout << "TriangleEx::print()" << endl;
    }
};

int main() {
    Shape *sptr = new TriangleEx();
    sptr->print();
    Triangle *tptr = (Triangle *)new Shape();
    tptr->print();
    ((Triangle *)sptr)->draw();
    (*((Triangle *)sptr)).draw();
}