// 출력과 같이 나타나도록 빈칸을 채우시오.
// 정렬함수를 사용하면안됨.
// 컴파일하기위한 헤더파일도 적으시오.

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    vector<int> v;
    v.push_back(4);
    v.push_back(0);
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    priority_queue<int> p;

    vector<int>::iterator it;
    for (it=v.begin();it!=v.end();++it) {
        p.push(*it);
    }

    while (!p.empty()) {
        cout << p.top() << endl;
        p.pop();
    }
}