#include <iostream>
#define abs(a) (((a)>0)?(a):-(a))
using namespace std;
int main() {
    int T;
    cin >> T;
    while (T--) {
        int x[3], y[3];
        for (int i=0;i<3;++i) cin >> x[i] >> y[i];
        int SA = (x[1]-x[0])*(y[2]-y[0])-(x[2]-x[0])*(y[1]-y[0]);
        cout << abs(SA) << ' ';
        if (SA < 0) cout << -1 << '\n';
        else if (SA == 0) cout << 0 << '\n';
        else cout << 1 << '\n';
    }
}