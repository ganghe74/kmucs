#include <iostream>
using namespace std;
int a[52];
int change[52];
int main() {
    int T, n, k;
    cin >> T;
    while (T--) {
        for (int i=0;i<52;++i) a[i] = 0;
        cin >> n >> k;
        for (int i=1;i<=n;++i) cin >> a[i];

        while (k--) {
            for (int i=1;i<=n;++i) {
                int naver = a[i-1] + a[i+1];
                if (naver < 3 || naver > 7) change[i] = -1;
                else if (naver == 3) change[i] = 0;
                else change[i] = 1;
            }
            for (int i=1;i<=n;++i) {
                a[i] += change[i];
                if (a[i] > 9) a[i] = 9;
                if (a[i] < 0) a[i] = 0;
            }
        }

        for (int i=1;i<=n;++i) cout << a[i] << ' ';
        cout << '\n';
    }
}