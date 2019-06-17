// 출력을 쓰시오, 컴파일하기위한 헤더파일 이름들을 쓰시오.

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

int main() {
    vector<int> x(2, 7);
    cout << x.size();

    x.push_back(0);
    x.insert(x.begin()+1, 1);
    x.push_back(2);
    for (int i=0;i<x.size();++i) cout << x[i] << " ";
    cout << endl;

    deque<int> d(x.begin()+1, x.begin()+4);
    for (int i=0;i<d.size();++i) cout << d[i] << " ";
    cout << endl;

    d.push_front(1);
    d.push_front(2);
    d.push_back(3);
    for (int i=0;i<d.size();++i) cout << d[i] << " ";
    cout << endl;

    deque<int>::iterator it = remove(d.begin(), d.end(), 7);
    for (int i=0;i<d.size();++i) cout << d[i] << " ";
    cout << endl;

    d.erase(it, d.end());
    for (int i=0;i<d.size();++i) cout << d[i] << " ";
    cout << endl;
}