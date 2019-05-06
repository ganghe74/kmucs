#include <iostream>
using namespace std;

bool isYoon(int y) {
    if (y % 400 == 0) return true;
    if (y % 100 == 0) return false;
    if (y % 4 == 0) return true;
    return false;
}

int main() {
    int a[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int T, y, m, d;
    cin >> T;
    while (T--) {
        int ans = 0;
        cin >> y >> m >> d;
        for (int i=0;i<m-1;++i) ans += a[i];
        if (isYoon(y) && m > 2) ans++;
        ans += d;
        cout << ans << endl;
    }
}