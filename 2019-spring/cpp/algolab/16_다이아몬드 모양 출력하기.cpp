#include <iostream>
using namespace std;

void printline(int k, int i) {
    for (int j=0;j<k;++j) {
        if (k/2 - i < j && j < k/2 + i) cout << '+';
        else cout << '*';
    }
    cout << '\n';
}

int main() {
    int T, k;
    cin >> T;
    while (T--) {
        cin >> k;
        for (int i=1;i<=k/2+1;++i) printline(k, i);
        for (int i=k/2;i>0;--i) printline(k, i);
    }
}