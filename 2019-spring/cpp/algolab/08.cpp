#include <iostream>
using namespace std;
int main() {
    int t, a, b, m;
    cin >> t;
    while (t--) {
        cin >> a >> b >> m;
        cout << (a <= m && m <= b) << endl;
    }
    return 0;
}