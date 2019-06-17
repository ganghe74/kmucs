#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream os;
    char c;
    os.open("output2.txt");
    while (cin.get(c)) {
        os.put(c);
    }
    os.close();
}