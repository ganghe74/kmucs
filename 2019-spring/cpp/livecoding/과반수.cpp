#include <iostream>
using namespace std;
int main() {
    int a[100];
    int T, n;
    cin >> T;
    while (T--) {
        int idx = 0, sum = 0;
        cin >> n;
        for (int i=0;i<n;++i) {
            cin >> a[i];
            sum += a[i];
            if (a[idx] < a[i]) {
                idx = i;
            }
        }
        if (a[idx] > sum/2) cout << idx+1 << endl;
        else cout << 0 << endl;
    }
}