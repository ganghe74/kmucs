#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}

ll lcm(ll a, ll b) {
    return a * b / gcd(a,b);
}

class myRational {
public:
    // Member Field
    ll _num;
    ll _den;
    // Constructor
    myRational(ll num=0, ll den=1) {
        if (den == 0) {
            num = 0;
            den = 1;
        }
        _num = num;
        _den = den;
        reduce();
    }
    myRational(const myRational &rat) { // Assume a is prefect.
        _num = rat._num;
        _den = rat._den;
    }
    // Accessor
    ll getNumerator() const { return _num; }
    ll getDenominator() const { return _den; }
    // Member Function
    myRational reciprocal() const { return myRational(_den, _num); }
    void reduce() {
        bool negative = false;
        if (_num < 0) {
            _num = -_num;
            negative = true;
        }
        ll divisor = gcd(_num, _den);
        _num /= divisor; _den /= divisor;
        if (negative) _num = -_num;
    }
    // Overloaded Operator
    myRational operator +(const myRational &rat) {
        ll den = lcm(_den, rat._den);
        ll num = _num * (den / _den) + rat._num * (den / rat._den);
        return myRational(num, den);
    }
    myRational operator +(int value) {
        return *this + myRational(value);
    }
    myRational operator -(const myRational &rat) {
        myRational you = rat;
        return *this + -you;
    }
    myRational operator -(int value) {
        return *this - myRational(value);
    }
    myRational operator *(const myRational &rat) {
        return myRational(_num * rat._num, _den * rat._den);
    }
    myRational operator *(int value) {
        return *this * myRational(value);
    }
    myRational operator /(const myRational &rat) {
        return *this * rat.reciprocal();
    }
    myRational operator /(int value) {
        return *this / myRational(value);
    }
    // Unary Operator
    myRational operator -() {
        return myRational(-_num, _den);
    }
    myRational& operator ++() {
        *this += 1;
        return *this;
    }
    myRational operator ++(int) {
        myRational ret(_num, _den);
        ++(*this);
        return ret;
    }
    myRational& operator --() {
        *this -= 1;
        return *this;
    }
    myRational operator --(int) {
        myRational ret(_num, _den);
        --(*this);
        return ret;
    }
    // Comparison Operator
    bool operator <(const myRational &rat) {
        return (*this - rat)._num < 0;
    }
    bool operator <=(const myRational &rat) {
        return (*this - rat)._num <= 0;
    }
    bool operator >(const myRational &rat) {
        return (*this - rat)._num > 0;
    }
    bool operator >=(const myRational &rat) {
        return (*this - rat)._num >= 0;
    }
    bool operator ==(const myRational &rat) {
        return (_num == rat._num && _den == rat._den);
    }
    bool operator !=(const myRational &rat) {
        return !(*this == rat);
    }
    // Assignment Operator
    myRational& operator =(const myRational &rat) {
        _num = rat._num;
        _den = rat._den;
        return *this;
    }
    myRational& operator =(int value) {
        _num = value;
        _den = 1;
        return *this;
    }
    myRational& operator +=(const myRational &rat) {
        *this = *this + rat;
        return *this;
    }
    myRational& operator +=(int value) {
        *this = *this + myRational(value);
        return *this;
    }
    myRational& operator -=(const myRational &rat) {
        *this = *this - rat;
        return *this;
    }
    myRational& operator -=(int value) {
        *this = *this - myRational(value);
        return *this;
    }
    myRational& operator *=(const myRational &rat) {
        *this = *this * rat;
        return *this;
    }
    myRational& operator *=(int value) {
        *this = *this * myRational(value);
        return *this;
    }
    myRational& operator /=(const myRational &rat) {
        *this = *this / rat;
        return *this;
    }
    myRational& operator /=(int value) {
        *this = *this / myRational(value);
        return *this;
    }
};

ostream &operator <<(ostream &outStream, const myRational& r) {
    if (r._num == 0) outStream << 0;
    else if (r._den == 1) outStream << r._num;
    else outStream << r._num << '/' << r._den;
    return outStream;
}

istream &operator >>(istream &inStream, myRational& r) {
    inStream >> r._num >> r._den;
    if (r._den == 0) {
        r._num = 0;
        r._den = 1;
    }
    if (r._den < 0) {
        r._num = -r._num;
        r._den = -r._den;
    }
    r.reduce();
    return inStream;
}

myRational operator +(int value, const myRational &rat) {
    return myRational(value) + rat;
}
myRational operator -(int value, const myRational &rat) {
    return myRational(value) - rat;
}
myRational operator *(int value, const myRational &rat) {
    return myRational(value) * rat;
}
myRational operator /(int value, const myRational &rat) {
    return myRational(value) / rat;
}

void testSimpleCase();

void swap(myRational *a, myRational *b) {
    myRational temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    testSimpleCase();
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<myRational> a(n);
        for (int i=0;i<n;++i) cin >> a[i];

        for (int i=0;i<n;++i) {
            for (int j=i+1;j<n;++j) {
                if (a[i] > a[j]) swap(a[i], a[j]);
            }
        }

        for (int i=0;i<a.size();++i) cout << a[i] << ' ';
        cout << '\n';
    }
}

void testSimpleCase()
{
    myRational frac1(2), frac2(3, 2), frac3(6, 4), frac4(12, 8), frac5, frac6, frac7;
    cout << frac1 << " " << frac2 << " " << frac3 << " "
    << frac4 << " " << frac5 << endl;
    cout << frac1.getNumerator() << " " << frac1.getDenominator() << endl;
    // Check arithmetic operators
    cout << frac1 * frac2 << " "
    << frac1 + frac3 << " "
    << frac2 - frac1 << " "
    << frac3 / frac2 << endl;
    // Check comparison operators 
    cout << ((frac1 < frac2) ? 1 : 0) << " "
    << ((frac1 <= frac2) ? 1 : 0) << " "
    << ((frac1 > frac2) ? 1 : 0) << " "
    << ((frac1 >= frac2) ? 1 : 0) << " "
    << ((frac1 == frac2) ? 1 : 0) << " "
    << ((frac1 != frac2) ? 1 : 0) << " "
    << ((frac2 < frac3) ? 1 : 0) << " "
    << ((frac2 <= frac3) ? 1 : 0) << " "
    << ((frac2 > frac3) ? 1 : 0) << " "
    << ((frac2 >= frac3) ? 1 : 0) << " "
    << ((frac2 == frac3) ? 1 : 0) << " "
    << ((frac2 != frac3) ? 1 : 0) << endl;
    cout << (frac6 = frac3) << " ";
    cout << (frac6 += frac3) << " ";
    cout << (frac6 -= frac3) << " ";
    cout << (frac6 *= frac3) << " ";
    cout << (frac6 /= frac3) << endl;
    cout << -frac6 << endl;
    frac6 = (++frac4) + 2;
    frac7 = 2 + (frac4++);
    cout << frac4 << " " << frac6 << " " << frac7 << endl;
    frac6 = (--frac4) - 2;
    frac7 = 2 - (frac4--);
    cout << frac4 << " " << frac6 << " " << frac7 << endl;
    cout << 2 * frac3 << " " << frac3 * 2 << " "
    << 2 / frac3 << " " << frac3 / 2 << endl;
}