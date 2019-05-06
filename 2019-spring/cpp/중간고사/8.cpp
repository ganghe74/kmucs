#include <iostream>
using namespace std;
int main() {
    int **arr;
    int N, M;
    cin >> N;
    arr = new int*[N];
    for (int i=0;i<N;++i) {
        cin >> M;
        arr[i] = new int[M];
        for (int j=0;j<M;++j) {
            arr[i][j] = j;
            cout << arr[i][j] << ' ';
        }
        cout << endl;
    }


    for (int i=0;i<N;++i) {
        delete[] arr[i];
    }
    delete[] arr;
    

/*
    for (int i=0;i<N;++i) {
        printf("arr[%d]\n", i);
        for (int j=0;j<5;++j) {
            printf("%d ", arr[i][j]);
        }
        puts("");
    }
*/
}