// 입력 (0, 1, 2) 각각 출력을 쓰시오.

#include <bits/stdc++.h>
using namespace std;

class ParentException {};
class ChildException : public ParentException {};

void f(int x) {
    try {
        if (x == 0) throw ChildException();
        if (x == 1) throw 1;
        cout << "F1" << endl;
    } catch (ParentException e) {
        cout << "F2" << endl;
        throw;
    } catch (ChildException e) {
        cout << "F3" << endl;
    } catch (...) {
        cout << "F4" << endl;
    }
    cout << "F5" << endl;
}

int main() {
    int number;
    try {
        cin >> number;
        f(number);
        cout << "M1" << endl;
    } catch (...) {
        cout << "M2" << endl;
    }
    cout << "M3" << endl;
}