#include <iostream>
using namespace std;

int swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

int min(int a, int b) {
    return a < b ? a : b;
}

int max (int a, int b) {
    return a > b ? a : b;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int ans;
        int x[4], y[4];
        for (int i=0;i<4;++i) cin >> x[i] >> y[i];
        if (x[0] != x[1]) {
            for (int i=0;i<2;++i) {
                swap(x[i], x[i+2]);
                swap(y[i], y[i+2]);
            }
        }
        if (y[2] > max(y[0], y[1]) || y[2] < min(y[0], y[1])) ans = 0;
        else if (x[0] > max(x[2], x[3]) || x[0] < min(x[2], x[3])) ans = 0;
        else {
            if (x[0] == x[2] || x[0] == x[3] || y[2] == y[0] || y[2] == y[1]) ans = 2;
            else ans = 1;
        }
        cout << ans << '\n';
    }
}