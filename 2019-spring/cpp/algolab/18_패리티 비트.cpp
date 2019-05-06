#include <iostream>
using namespace std;
int main() {
    unsigned int T, n;
    cin >> T;
    while (T--) {
        cin >> n;
        if (__builtin_popcount(n) % 2) {
            n += 1 << 31;
        }
        cout << n << '\n';
    }
}