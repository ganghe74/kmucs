#include <iostream>
using namespace std;

int go(int a, int b, int c, int d) {
    int s = max(a, c), e = min(b, d);
    if (s > e) return -1;
    return e - s;
}

int main() {
    int t, a, b, c, d;
    cin >> t;
    while (t--) {
        cin >> a >> b >> c >> d;
        cout << go(a, b, c, d) << endl;
    }
    return 0;
}