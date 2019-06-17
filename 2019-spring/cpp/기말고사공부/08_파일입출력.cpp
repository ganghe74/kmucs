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

    int number;
    char name[30];
    int score;
    is >> number >> name >> score;
    
    ofstream os;
    os.open("output.txt");
    os << number << " " << name << " " << score << endl;

    is.close();
    os.close();
}