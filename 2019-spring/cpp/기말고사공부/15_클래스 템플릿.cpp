#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Box {
public:
    Box(T t); 
    T t;
};

template <typename T>
Box<T>::Box(T t) :t(t) {}

int main() {
    Box<int> b(1);
    cout << b.t;
}