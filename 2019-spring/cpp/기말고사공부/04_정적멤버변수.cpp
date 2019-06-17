#include <bits/stdc++.h>
using namespace std;

class Car {
public:
    Car() {
        numberOfCars++;
    }
    static int numberOfCars;
    static int getNumberOfCars() {
        return numberOfCars;
    }
};

int Car::numberOfCars = 0;

int main() {
    Car c1;
    cout << Car::numberOfCars << endl;
    Car c2;
    cout << Car::getNumberOfCars() << endl;
}