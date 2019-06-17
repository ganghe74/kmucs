#include <bits/stdc++.h>
using namespace std;

template <typename T>
T get_max(T x, T y) {
    return x > y ? x : y;
}

template <>
int get_max(int x, int y) {
    cout << "Call int get_max(int,int)" << endl;
    return x > y ? x : y;
}

int main() {
    cout << get_max(10,11) << endl;
    cout << get_max(1.2,2.5);
}