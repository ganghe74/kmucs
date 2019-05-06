#include <iostream>
using namespace std;
int main() {
    int T, n, k;
    cin >> T;
    while (T--) {
        int num = 1;
        cin >> n >> k;
        for (int i=0;i<n;++i) {
            for (int j=i;j<n;++j) {
                if (j == k-1) {
                    cout << num;
                    if (i != k-1) cout << '*';
                }
                num++;
            }
        }
        cout << '\n';
    }
}