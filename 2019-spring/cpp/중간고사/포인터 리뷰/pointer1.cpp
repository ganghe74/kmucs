#include <iostream>
using namespace std;

void pass_by_value(int *p) {
    p = new int;
}

void pass_by_reference(int *&p) {
    p = new int;
}

int main() {
    int *p1 = NULL;
    int *p2 = NULL;
    pass_by_value(p1);
    pass_by_reference(p2);
    cout << "p1 : " << p1 << " p2 : " << p2 << endl;
}