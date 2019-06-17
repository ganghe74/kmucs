#include <bits/stdc++.h>
using namespace std;

void raiseError() {
    throw 1.1;
}

int main() {
    try {
        raiseError();
    } catch (int e) {
        cout << "Catch " << e << endl;
    } catch (double e) {
        cout << "Catch " << e << endl;
    } catch (...) {
        cout << "Catch" << endl;
    }
}