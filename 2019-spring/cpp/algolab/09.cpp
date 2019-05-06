#include <iostream>
using namespace std;
int main() {
    int t, y;
    cin >> t;
    while (t--) {
        cin >> y;
        y--;
        cout << (y * 365 + y / 4 - y / 100 + y / 400 + 1) % 7 << endl;
    }
}