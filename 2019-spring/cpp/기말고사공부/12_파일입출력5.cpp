#include <bits/stdc++.h>
using namespace std;

int main() {
    int buffer[] = {10, 20, 30, 40, 50};
    ofstream os;
    os.open("output.dat", ofstream::binary);
    if (os.fail()) {
        cout << "Fail Open" << endl;
        exit(1);
    }
    os.write((char *)&buffer, sizeof(buffer));
    os.close();
}