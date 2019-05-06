#include <iostream>
using namespace std;

void outputZigZag(int k) {
    int num;
    bool r;
    if (k % 2 == 0) {
        num = k * (k+1) / 2;
        r = true;
    }
    else {
        num = k * (k-1) / 2 + 1;
        r = false;
    }
    while (--k) {
        cout << num << "*";
        if (r) num--;
        else num++;
    }
    cout << num << '\n';
}

int main() {
    int t, n, k;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        outputZigZag(k);
    }
    return 0;
}