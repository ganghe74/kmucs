#include <iostream>
using namespace std;

double sum_product(double a, double b, double &sum, double &product) {
    sum = a + b;
    product = a * b;
}

int main() {
    double x, y, sum, product;
    cin >> x >> y;
    sum_product(x,y,sum,product);
    cout << sum << " " << product;
}