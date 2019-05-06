#include <iostream>
#include <vector>
#include <algorithm>
#define LIMIT 1000000000
using namespace std;
long long pow(int a, int b) {
    long long ret = 1;
    while (b--) ret *= a;
    return ret;
}
int main() {
    vector<int> a;
    for (int i2 = 0;i2<30;++i2) {
        for (int i3 = 0;i3<19;++i3) {
            if (pow(2, i2) * pow (3, i3) > LIMIT) break;
            for (int i5 = 0;i5<13;++i5) {
                if (pow(2, i2) * pow(3, i3) * pow(5, i5) > LIMIT) break; 
                a.push_back(pow(2, i2) * pow(3, i3) * pow(5, i5));
            }
        }
    }
    sort(a.begin(), a.end());

    int T, k;
    cin >> T;
    while (T--) {
        cin >> k;
        cout << a[k-1] << '\n';
    }
}