#include <iostream>
#include <cmath>
using namespace std;
class myComplex {
public:
    // Constructor (생성자)
    myComplex(int real = 0, int imag = 0) {
        realPart = real;
        imaginaryPart = imag;
    }
    // Copy constructor (복사 생성자)
    myComplex(const myComplex& number) {
        realPart = number.getRealPart();
        imaginaryPart = number.getImaginaryPart();
    }
    // Accessor functions (접근자)
    int getRealPart() const {
        return realPart;
    }
    int getImaginaryPart() const {
        return imaginaryPart;
    }
    // Mutator functions (변경자)
    void setRealPart(int real) {
        realPart = real;
    }
    void setImaginaryPart(int imag) {
        imaginaryPart = imag;
    }
    void set(int real, int imag) {
        realPart = real;
        imaginaryPart = imag;
    }
    // Overloaded binary operators
    myComplex operator +(const myComplex& number) const {
        return myComplex(realPart + number.getRealPart(), imaginaryPart + number.getImaginaryPart());
    }
    myComplex operator +(int value) const {
        return myComplex(realPart + value, imaginaryPart);
    }
    myComplex operator -(const myComplex &number) {
        return myComplex(realPart - number.getRealPart(), imaginaryPart - number.getImaginaryPart());
    }
    myComplex operator -(int value) {
        return myComplex(realPart-value, imaginaryPart);
    }
    myComplex operator *(const myComplex &number) {
        int a = realPart, b = imaginaryPart, c = number.getRealPart(), d = number.getImaginaryPart();
        return myComplex(a*c-b*d, a*d+b*c);
    }
    myComplex operator *(int value) {
        return myComplex(value * realPart, value * imaginaryPart);
    }


    // Overloaded assignment operators
    myComplex& operator =(const myComplex& number) {
        this->realPart = number.getRealPart();
        this->imaginaryPart = number.getImaginaryPart();
        return *this;
    }
    myComplex& operator =(int value) {
        this->realPart = value;
        this->imaginaryPart = 0;
        return *this;
    }
    myComplex& operator +=(const myComplex &number) {
        *this = *this + number;
        return *this;
    }
    myComplex& operator +=(int value) {
        *this = *this + value;
        return *this;
    }
    myComplex& operator -=(const myComplex &number) {
        *this = *this - number;
        return *this;
    }
    myComplex& operator -=(int value) {
        *this = *this - value;
        return *this;
    }
    myComplex& operator *=(const myComplex &number) {
        *this = *this * number;
        return *this;
    }
    myComplex& operator *=(int value) {
        *this = *this * value;
        return *this;
    }

     // Overloading relational operators
    bool operator ==(const myComplex &number) const {
        return (realPart == number.getRealPart()) && (imaginaryPart == number.getImaginaryPart());
    }
    bool operator !=(const myComplex &number) const {
        return !(*this == number);
    }
    bool operator >(const myComplex &number) const {
        return norm2() > number.norm2();
    }
    bool operator >=(const myComplex &number) const {
        return norm2() >= number.norm2();
    }
    bool operator <(const myComplex &number) const {
        return norm2() < number.norm2();
    }
    bool operator <=(const myComplex &number) const {
        return norm2() <= number.norm2();
    }
    // Overloaded unary operators
    myComplex operator -() {
        return myComplex(-realPart, -imaginaryPart);
    }
    myComplex operator ~() {
        return myComplex(realPart, -imaginaryPart);
    }
    myComplex& operator ++() {
        realPart += 1;
        return *this;
    }
    myComplex operator ++(int) {
        myComplex ret(realPart, imaginaryPart);
        ++(*this);
        return ret;
    }
    myComplex& operator --() {
        realPart -= 1;
        return *this;
    }
    myComplex operator --(int) {
        myComplex ret(realPart, imaginaryPart);
        --(*this);
        return ret;
    }
    
    int norm2() const {
        return realPart * realPart + imaginaryPart * imaginaryPart;
    }

private:
    int realPart;
    int imaginaryPart;
    int norm() const {
        return sqrt(realPart * realPart + imaginaryPart * imaginaryPart);
    }
};

ostream &operator <<(ostream &outStream, const myComplex& number)
{
    outStream << "(" << number.getRealPart() << "," << number.getImaginaryPart() << ")";
    return outStream;
    }
istream &operator >>(istream &cin, myComplex& number)
{
    int real, imag;
    cin >> real >> imag;
    number.set(real, imag);
    return cin;
}

myComplex operator +(int value, const myComplex &number) {
    return myComplex(value + number.getRealPart(), number.getImaginaryPart());
}

myComplex operator -(int value, const myComplex &number) {
    return myComplex(value - number.getRealPart(), -number.getImaginaryPart());
}

myComplex operator *(int value, const myComplex &number) {
    return myComplex(value * number.getRealPart(), value * number.getImaginaryPart());
}

void testSimpleCase();
void testDataFromFile();

int main(void)
{
    testSimpleCase();
    testDataFromFile();
}


void testSimpleCase()
{
    myComplex c0, c1(1), c2(2, 2);
    myComplex c3(c2);
    myComplex c4, c5, c6, c7, c8, c9;
    // test constructor
    cout << c0 << endl << c1 << endl << c2 << endl;
    // test copy constructor
    cout << c3 << endl;
    // test accessor function
    cout << c3 << endl;
    // test mutator function
    c3.set(3, 3);
    cout << c3 << endl;
    c3.setRealPart(4);
    cout << c3 << endl;
    c3.setImaginaryPart(4);
    cout << c3 << endl;
    // test binary operators
    c4 = c1 + c3;
    c5 = c1 - c3;
    c6 = c4 * c5;
    cout << c4 << endl << c5 << endl << c6 << endl;
    c7 = c6 + 2;
    c8 = c6 - 2;
    c9 = c6 * 2;
    cout << c7 << endl << c8 << endl << c9 << endl;
    c7 += c4;
    c8 -= c5;
    c9 *= c6;
    cout << c7 << endl << c8 << endl << c9 << endl;
    c7 += 2;
    c8 -= 2;
    c9 *= 2;
    cout << c7 << endl << c8 << endl << c9 << endl;
    // test comparison operators
    cout << (c8 != c9) << " " << (c8 == c9) << endl;
    cout << (c8 > c9) << " " << (c8 >= c9) << " " << (c8 < c9) << " " << (c8 <= c9) <<
    endl;
    c7 = c8 = c9;
    cout << (c8 != c9) << " " << (c8 == c9) << endl;
    cout << (c8 > c9) << " " << (c8 >= c9) << " " << (c8 < c9) << " " << (c8 <= c9) <<
    endl;
    // test prefix operators
    c7 = -myComplex(2, 3);
    c8 = (++c7) * 2;
    c9 = 2 * (c7++);
    cout << c7 << " " << c8 << " " << c9 << endl;
    c7 = ~myComplex(2, 3);
    c8 = (--c7) * 2; 
    c9 = 2 * (c7--);
    cout << c7 << " " << c8 << " " << c9 << endl;
    // test expressions with myComplex numbers
    c1 = myComplex(1,2);
    c2 = myComplex(2,3);
    c3 = myComplex(4,5);
    c4 = myComplex(5,6);
    c5 = myComplex(6,7);
    c6 = 3;
    cout << -(c1*c2) - 2*c3 + ~c4 * c5 * 3 + 2 - c6 << endl;
}

void testDataFromFile()
{
    int T;
    cin >> T;
    while (T--) {
        myComplex c1, c2, c3, c4;
        myComplex c5, c6, c7, c8, c9;
        cin >> c1 >> c2 >> c3 >> c4;
        cout << c1 << " " << c2 << " " << c3 << " " << c4 << endl;
        cout << (2 + c1 + 3) + (2 - c2 - 3) * (2 * c3 * 3) - ( 2 * c4 - 3) << endl;
        c5 = c6 = c7 = c8 = c1;
        cout << (c5 == c2) << " " << (c5 != c2) << endl;
        cout << (c5 > c2) << " " << (c5 >= c2) << " " << (c5 < c2) << " " << (c5 <= c2)
        << endl;
        cout << (c5 == c6) << " " << (c5 != c6) << endl;
        cout << (c5 > c6) << " " << (c5 >= c6) << " " << (c5 < c6) << " " << (c5 <= c6)
        << endl;
        c5 += c2;
        c6 -= c3;
        c7 *= c4;
        c8 = c2.getRealPart();
        c9 = c3.getImaginaryPart();
        cout << c5 << " " << c6 << " " << c7 << " " << c8 << " " << c9 << endl;
        c7 = -c6;
        c8 = (++c7) * 2;
        c9 = 2 * (c7++);
        cout << c7 << " " << c8 << " " << c9 << endl;
        c7 = ~c6;
        c8 = (++c7) * 2;
        c9 = 2 * (c7++);
        cout << c7 << " " << c8 << " " << c9 << endl;
    }
}