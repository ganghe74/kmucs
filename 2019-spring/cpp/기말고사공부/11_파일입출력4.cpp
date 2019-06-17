#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream is;
    ofstream os;
    is.open("input.txt");
    if(is.fail()) {
        cerr << "Fail open" << endl;
        exit(1);
    }
    os.open("output3.txt");
    if (os.fail()) {
        cerr << "Fail open" << endl;
        exit(1);
    }
    char c;
    int line_number = 1;
    is.get(c);
    os << line_number << ": ";
    while (!is.eof()) {
        os << c;
        if (c == '\n') {
            line_number++;
            os << line_number << ": ";
        }
        is.get(c);
    }
    is.close();
    os.close();
}