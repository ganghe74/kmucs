#include <iostream>
using namespace std;

void print(int k) {
    int num = 1;
    int a[k][k];
    for (int i=0;i<k;++i) {
        for (int j=i;j<k;++j) a[j][i] = num++;
    }
    for (int i=0;i<k;++i) {
        for (int j=0;j<=i;++j) cout << a[i][j] << ' ';
        cout << '\n';
    }
}

int main() {
    int T, k;
    cin >> T;
    while (T--) {
        cin >> k;
        print(k);
    }
}