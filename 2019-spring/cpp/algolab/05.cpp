#include <iostream>
using namespace std;

int isLeapYear(int year) {
    if (year % 400 == 0) return 1;
    if (year % 100 == 0) return 0;
    if (year % 4 == 0) return 1;
    return 0;
}

int main() {
    int t, year;
    cin >> t;
    while (t--) {
        cin >> year;
        cout << isLeapYear(year) << endl;
    }
    return 0;
}