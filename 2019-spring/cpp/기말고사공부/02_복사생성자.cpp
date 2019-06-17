#include <bits/stdc++.h>
using namespace std;

class Student {
public:
    Student(char *pn, int n) {
        name = new char[strlen(pn) + 1];
        strcpy(name, pn);
        number = n;
    }
    Student(Student& s) { // 깊은 복사
        cout << "Student(Student& s)" << endl;
        name = new char[strlen(s.name) + 1];
        strcpy(name, s.name);
        number = s.number;
    }
    ~Student() {
        delete[] name;
    }
    void setName(char *pn) {
        delete[] name;
        name = new char[strlen(pn) + 1];
        strcpy(name, pn);
    }
    void printInfo() {
        cout << "Name = " << name << " " ;
        cout << "Number = " << number << endl;
    }
private:
    char * name;
    int number;
};

void displayStudent(Student obj) {
    cout << "hi" << endl;
}

int main() {
    Student s1("Park", 20100001);
    displayStudent(s1);

    return 0;
}