#include <iostream>
#define abs(a) (((a)>0)?(a):-(a))
using namespace std;
int main() {
    int T, n;
    cin >> T;
    while (T--) {
        cin >> n;
        int x[n+1], y[n+1];
        for (int i=0;i<n;++i) cin >> x[i] >> y[i];
        x[n] = x[0]; y[n] = y[0];
        int SA = 0;
        for (int i=0;i<n;++i) SA += (x[i]+x[i+1])*(y[i+1]-y[i]);
        cout << abs(SA) << ' ';
        if (SA < 0) cout << -1 << '\n';
        else if (SA == 0) cout << 0 << '\n';
        else cout << 1 << '\n';
    }
}