#include <iostream>
using namespace std;

void printline(int k, int i) {
    bool c = true;
    for (int j=0;j<k;++j) {
        if (i <= j && j < k-i) {
            if (c) cout << '*';
            else cout << '+';
            c = !c;
        }
        else cout << '-';
    }
    cout << '\n';
}

int main() {
    int T, k;
    cin >> T;
    while (T--) {
        cin >> k;
        for (int i=0;i<=k/2;++i) printline(k, i);
        for (int i=k/2-1;i>=0;--i) printline(k, i);
    }
}