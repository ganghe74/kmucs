#include <iostream>
using namespace std;

int solve(int n) {
    int ret = 0;
    while (n > 0) {
        ret = ret * 10 + n % 10;
        n /= 10;
    }
    return ret;
}

int main() {
    int T, n;
    cin >> T;
    while (T--) {
        cin >> n;
        cout << solve(n) << endl;
    }
}