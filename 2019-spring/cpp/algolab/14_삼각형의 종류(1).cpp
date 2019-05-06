#include <iostream>
using namespace std;
int main() {
    int T;
    cin >> T;
    while (T--) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a + b <= c) cout << "0\n";
        else if (a == b && b == c) cout << "1\n";
        else if (a * a + b * b == c * c) cout << "2\n";
        else if (a == b || b == c || a == c) cout << "3\n";
        else cout << "4\n";
    }
}