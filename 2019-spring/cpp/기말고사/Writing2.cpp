// 출력을 쓰시오.

#include <iostream>
using namespace std;

class Human {
public:
    Human() { cout << "Human()\n"; }
    Human(Human& obj) { cout << "Humman(Human&)\n"; }
    ~Human() { cout << "~Human()\n"; }
    virtual void print() { cout << "Human::print()\n"; }
};

class Korean : public Human {
public:
    Korean() { cout << "Korean()\n"; }
    Korean(Korean& obj) { cout << "Korean(Korean&)\n"; }
    ~Korean() { cout << "~Korean()\n"; }
    virtual void print() { cout << "Korean::print()\n"; }
};

Human f(Human &obj) {
    obj.print();
    return obj;
}

int main() {
    Human h;
    Korean k;
    h = f(k);
}