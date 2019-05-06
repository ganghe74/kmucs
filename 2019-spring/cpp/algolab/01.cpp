#include <iostream>
using namespace std;

int solution(int H, int M) {
    double h = H * 30 + M * 0.5;
    double m = M * 6;
    double angle = h-m;
    if (angle < -180) return angle + 360;
    if (angle < -0) return -angle;
    if (angle > 180) return 360 - angle;
    return angle;
}

int main() {
    int T, H, M;
    cin >> T;
    while (T--) {
        cin >> H >> M;
        cout << solution(H, M) << endl;
    }
}