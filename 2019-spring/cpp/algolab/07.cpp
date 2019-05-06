#include <iostream>
using namespace std;
int main() {
    int t, n, num;
    cin >> t;
    while (t--) {
        int two = 0, five = 0;
        cin >> n;
        while (n--) {
            cin >> num;
            while (num % 2 == 0) {
                num /= 2;
                two++;
            }
            while (num % 5 == 0) {
                num /= 5;
                five++;
            }
        }
        cout << min(two, five) << endl;
    }
    return 0;
}