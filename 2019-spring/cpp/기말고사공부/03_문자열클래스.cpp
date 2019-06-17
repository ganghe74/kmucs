#include <bits/stdc++.h>
using namespace std;

class MyString {
public:
    MyString(const char *s = NULL);
    MyString(MyString& s);
    ~MyString();
    void print();
    int getSize();
private:
    char *pBuf;
};

MyString::MyString(const char *s) {
    if (s == NULL) {
        pBuf = new char[6];
        pBuf = "EMPTY";
    }
    else {
        pBuf = new char[strlen(s) + 1];
        strcpy(pBuf, s);
    }
}

MyString::MyString(MyString& s) {
    cout << "MyString& s" << endl;
    pBuf = new char[s.getSize() + 1];
    strcpy(pBuf, s.pBuf);
}

MyString::~MyString() {
    if (pBuf) delete[] pBuf;
}

void MyString::print() {
    cout << pBuf << endl;
}

int MyString::getSize() {
    return strlen(pBuf);
}

int main() {
    MyString str1("Hello");
    MyString str2 = str1;
    str2.print();
}