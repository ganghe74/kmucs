#include <iostream>
using namespace std;

const int SIZE = 10;
void rotateArray(int array[], int size);
void printArray(int array[], int size);

int main() {
    int t;
    unsigned int size;
    int array[SIZE];

    cin >> t;

    while (t--) {
        cin >> size;
        for (int i=0;i<size;++i) cin >> array[i];
        rotateArray(array, size);
        printArray(array, size);
    }
}

void rotateArray(int array[], int size) {
    int originalArray[SIZE];
    for (int i=0;i<size;++i) originalArray[i] = array[i];
    int idx = 0;
    for (int i=0;i<size;++i) {
        if (originalArray[i] % 2 == 1) array[idx++] = originalArray[i];
    }
    for (int i=0;i<size;++i) {
        if (originalArray[i] % 2 == 0) array[idx++] = originalArray[i];
    }
}

void printArray(int array[], int size) {
    for (int i=0;i<size;++i) cout << array[i] << ' ';
    cout << endl;
}