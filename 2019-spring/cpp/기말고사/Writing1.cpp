// 복사생성자, 소멸자, 대입연산자(=), 비교연산자(==) 의 원형을 선언하고 정의하시오.
// 복사생성자, 소멸자, 대입연산자(=) 는 멤버함수이며, 비교연산자(==)는 전역함수이다.
// 그리고 프로그램 실행시 출력을 쓰시오.

#include <iostream>
using namespace std;
class Point {
private:
    int x, y;
public:
    Point() : x(0), y(0) {}
    Point(int x, int y) : x(x), y(y) {};
    Point(Point& obj);
    ~Point();
    Point& operator=(Point& obj);
    friend bool operator==(Point &p1, Point &p2);
};

Point::Point(Point& obj) {
    x = obj.x;
    y = obj.y;
}

Point::~Point() {}

Point& Point::operator=(Point& obj) {
    x = obj.x;
    y = obj.y;
    return *this;
}

bool operator==(Point& p1, Point& p2) {
    return (p1.x == p2.x) && (p1.y == p2.y);
}

int main() {
    Point p1, p2(1,2), p3(3,4);
    cout << (p1 == p2) << endl;
    p2 = p3 = p1;
    cout << (p1 == p2);
}