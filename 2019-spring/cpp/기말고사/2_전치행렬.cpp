#include <iostream>
using namespace std;

const int SIZE = 10;
void transposeSquareMatrix(int squareMatrix[][SIZE], int size);
void printSquareMatrix(int squareMatrix[][SIZE], int size);

int main() {
    int t;
    unsigned int size;
    int squareMatrix[SIZE][SIZE];
    cin >> t;

    while (t--) {
        cin >> size;
        for (int i=0;i<size;++i) {
            for (int j=0;j<size;++j) cin >> squareMatrix[i][j];
        }
        transposeSquareMatrix(squareMatrix, size);
        printSquareMatrix(squareMatrix, size);
    }
}

void transposeSquareMatrix(int squareMatrix[][SIZE], int size) {
    int originalMatrix[SIZE][SIZE];
    for (int i=0;i<10;++i) {
        for (int j=0;j<10;++j) originalMatrix[i][j] = squareMatrix[i][j];
    }
    for (int i=0;i<10;++i) {
        for (int j=0;j<10;++j) {
            squareMatrix[i][j] = originalMatrix[j][i];
        }
    }
}

void printSquareMatrix(int squareMatrix[][SIZE], int size) {
    for (int i=0;i<size;++i) {
        for (int j=0;j<size;++j) cout << squareMatrix[i][j] << ' ';
        cout << endl;
    }
}