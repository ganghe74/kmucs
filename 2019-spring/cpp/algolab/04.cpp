#include <iostream>
#define abs(a) (((a)>0)?(a):-(a))
using namespace std;

int closestNumber(int n, int m) {
    int l = n, r = n;
    while (l % m != 0 && r % m != 0) l--, r++;
    if (l % m == 0 && r % m == 0) {
        if (abs(l) > abs(r)) return l;
        return r;
    }
    if (l % m == 0) return l;
    return r;
}

int main() {
    int t, n, m;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        cout << closestNumber(n,m) << '\n';
    }
}