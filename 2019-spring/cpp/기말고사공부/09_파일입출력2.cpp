#include <iostream>
#include <fstream>
using namespace std;
int main() {
    ifstream is;
    is.open("input.txt");
    if (!is) {
        cerr << "Fail Open!" << endl;
        exit(1);
    }

    char c;
    is.get(c);
    while (!is.eof()) {
        cout << c;
        is.get(c);
    }

    is.close();
}