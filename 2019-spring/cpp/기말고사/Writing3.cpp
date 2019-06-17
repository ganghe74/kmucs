// 컴파일에러가 일어나는 부분을 모두 체크하시오.

#include <iostream>
using namespace std;

class GrandMother {
private:
    int pri;
protected:
    int pro;
public:
    int pub;
    GrandMother() {
        pri = 1;
        pro = 1;
        pub = 1;
    }
};

class Mother : public GrandMother {
public:
    Mother() {
        // pri = 1;
        pro = 1;
        pub = 1;
    }
};

class Dog : public GrandMother {
public:
    Dog() {
        // pri = 1;
        pro = 1;
        pub = 1;
    }
};

class Uncle : private GrandMother {
public:
    Uncle() {
        // pri = 1;
        pro = 1;
        pub = 1;
    }
};

class Cousin : public Uncle {
public:
    Cousin() {
        // pri = 1;
        // pro = 1;
        // pub = 1;
    }
};

class Me : public Mother {
public:
    Me() {
        // pri = 1;
        pro = 1;
        pub = 1;
    }
};

int main() {
    GrandMother gm;
    Mother m;
    Me i;
    // cout << gm.pri << endl;
    // cout << gm.pro << endl;
    cout << gm.pub << endl;

    // cout << m.pri << endl;
    // cout << m.pro << endl;
    cout << m.pub << endl;
    
    // cout << i.pri << endl;
    // cout << i.pro << endl;
    cout << i.pub << endl;
}