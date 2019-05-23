#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class myTerm {
public:
    // Constructor
    myTerm(int c = 0, unsigned e = 0) {
        coeff = c;
        exp = e;
    }
    myTerm(const myTerm &term) {
        coeff = term.getCoeff();
        exp = term.getExp();
    };
    // overloaded operators
    bool operator == (const myTerm& term) const {
        return coeff == term.getCoeff() && exp == term.getExp();
    }
    bool operator != (const myTerm& term) const {
        return !(*this == term);
    }
    bool operator < (const myTerm& term) const {
        return exp > term.getExp();
    }
    bool operator <= (const myTerm& term) const {
        return exp >= term.getExp();
    }
    bool operator > (const myTerm& term) const {
        return exp < term.getExp();
    }
    bool operator >= (const myTerm& term) const {
        return exp >= term.getExp();
    }
    myTerm operator - () const {
        return myTerm(-coeff, exp);
    }
    // accessor functions
    int getCoeff() const { return coeff; }
    unsigned getExp() const { return exp; }
    // mutator functions
    void setCoeff(int c) { coeff = c; }
    void setExp(unsigned e) { exp = e; }
    // member functions
    myTerm ddx() const {
        if (exp == 0) return myTerm(0, 0);
        return myTerm(exp * coeff, exp - 1);
    }
    // friend functions and classes
    friend ostream& operator <<(ostream &outStream, const myTerm& term);
    // friend myPolynomial;
private:
    int coeff;
    unsigned exp;
};


class myPolynomial {
public:
    myPolynomial(int c = 0, unsigned e = 0) {
        degree = e;
        terms = 1;
        termArray.push_back(myTerm(c, e));
    }
    myPolynomial(int nTerms, int mono[]) {
        for (int i=0;i<nTerms;++i) {
            if (mono[i*2] == 0) continue;
            termArray.push_back(myTerm(mono[i*2], mono[i*2+1]));
        }
        if (termArray.size() == 0) *this = ZERO;
        else {
            terms = termArray.size();
            sort();
            degree = termArray[0].getExp();
        }
    }
    // // copy constructor
    // myPolynomial(const myPolynomial &poly);
    // // overloaded operators
    bool operator == (const myPolynomial &poly) const {
        if (terms != poly.terms) return false;
        for (int i=0;i<terms;++i) {
            if (termArray[i] != poly.termArray[i]) return false;
        }
        return true;
    };
    bool operator != (const myPolynomial &poly) const {
        return !(*this == poly);
    }
    myPolynomial& operator += (const myPolynomial &poly) {
        *this = *this + poly;
        return *this;
    }
    myPolynomial& operator -= (const myPolynomial &poly) {
        *this = *this - poly;
        return *this;
    };
    myPolynomial& operator *= (const myPolynomial &poly) {
        *this = *this * poly;
        return *this;
    }
    myPolynomial& operator *= (int k) {
        *this = *this * k;
        return *this;
    }
    myPolynomial operator -() const {
        myPolynomial ret(*this);
        for (int i=0;i<terms;++i) ret.termArray[i] = -ret.termArray[i];
        return ret;
    }
    myPolynomial operator *(int k) const {
        if (k == 0) return ZERO;
        myPolynomial ret(*this);
        for (int i=0;i<terms;++i) ret.termArray[i].setCoeff(ret.termArray[i].getCoeff() * k);
        return ret;
    }
    myPolynomial operator +(const myPolynomial &poly) const {
        vector<myTerm> a = termArray, b = poly.termArray, c;
        int i = 0, j = 0;
        while (i < terms && j < poly.terms) {
            if (a[i].getExp() == b[j].getExp()) {
                int coeff = a[i].getCoeff() + b[j].getCoeff();
                if (coeff != 0) c.push_back(myTerm(coeff, a[i].getExp()));
                ++i; ++j;
            }
            else if (a[i].getExp() > b[j].getExp()) {
                c.push_back(a[i++]);
            }
            else {
                c.push_back(b[j++]);
            }
        }
        while (i < terms) {
            if (a[i].getCoeff() != 0) c.push_back(a[i]);
            ++i;
        }
        while (j < poly.terms) {
            if (b[j].getCoeff() != 0) c.push_back(b[j]);
            ++j;
        }
        if (c.size() == 0) return ZERO;
        myPolynomial ret;
        ret.degree = c[0].getExp();
        ret.terms = c.size();
        ret.termArray = c;
        return ret;
    }
    myPolynomial operator -(const myPolynomial &poly) const {
        return *this + (-poly);
    }
    myPolynomial operator *(const myPolynomial &poly) const {
        if (*this == ZERO || poly == ZERO) return ZERO;
        myPolynomial ret;
        for (int i=0;i<terms;++i) {
            myPolynomial temp(poly);
            int coeff = termArray[i].getCoeff();
            unsigned exp = termArray[i].getExp();
            for (int j=0;j<temp.terms;++j) {
                temp.termArray[j].setCoeff(coeff * temp.termArray[j].getCoeff());
                temp.termArray[j].setExp(exp + temp.termArray[j].getExp());
            }
            ret += temp;
        }
        return ret;
    }
    long operator() (int x) const {
        long long ret = 0;
        for (int i=0;i<terms;++i)
            ret += termArray[i].getCoeff() * pow(x, termArray[i].getExp());
        return ret;
    }
    int getDegree() const { 
        if (*this == ZERO) return -1;
        return degree;
    }
    unsigned getNumTerms() const { return terms; }
    myPolynomial ddx() const {
        vector<myTerm> a;
        for (int i=0;i<terms;++i) {
            myTerm t = termArray[i].ddx();
            if (t.getCoeff() == 0) continue;
            a.push_back(t);
        }
        myPolynomial ret;
        if (a.size() == 0) return ZERO;
        ret.terms = a.size();
        ret.degree = a[0].getExp();
        ret.termArray = a;
        return ret;
    }
    // // friend operators and functions
    friend myPolynomial operator *(int k, const myPolynomial &poly);
    friend ostream& operator <<(ostream &outStream, const myPolynomial &poly);
    static const myPolynomial ZERO; // P(x) = 0
    static const myPolynomial ONE; // P(x) = 1
    static const myPolynomial X; // P(x) = x
// private:
    int degree; // maximum expnent
    int terms; // num of terms
    vector<myTerm> termArray; // sorted term array
    void sort() {
        for (int i=0;i<terms;++i) {
            for (int j=i+1;j<terms;++j) {
                if (termArray[i] > termArray[j]) swap(termArray[i], termArray[j]);
            }
        }
    }
};

myPolynomial operator *(int k, const myPolynomial &poly) {
    return poly * k;
}

ostream &operator <<(ostream &outStream, const myTerm &term) {
    if (term.exp == 0) {
        if (term.coeff == 0) return outStream;
        else return outStream << term.coeff;
    }
    
    if (term.coeff == 1) outStream << "x";
    else if (term.coeff == -1) outStream << "-x";
    else outStream << term.coeff << "x";
    
    if (term.exp == 1) return outStream;
    else return outStream << "^" << term.exp;
}

ostream &operator <<(ostream &outStream, const myPolynomial &poly) {
    if (poly == myPolynomial::ZERO) return outStream << 0;

    outStream << poly.termArray[0];
    for (int i=1;i<poly.terms;++i) {
        if (poly.termArray[i].getCoeff() > 0) cout << "+";
        cout << poly.termArray[i];
    }
    return outStream;
}

void swap(myTerm *a, myTerm *b) {
    myTerm temp = *a;
    *a = *b;
    *b = temp;
}

const myPolynomial myPolynomial::ZERO(0);
const myPolynomial myPolynomial::ONE(1, (unsigned)0);
const myPolynomial myPolynomial::X(1, 1);

void testSimpleCase();
void testDataFromFile();

int main() {
    testSimpleCase();
    testDataFromFile();
}

void testSimpleCase() {
    // test static variables
    cout << myPolynomial::ZERO << endl;
    cout << myPolynomial::ONE << endl;
    cout << myPolynomial::X << endl;
    myPolynomial p0, p1(1), p2(1, 1), p3(3, 5);
    int testData4[10] = {1, 0, 1, 1, 1, 2, 1, 3, 1, 4};
    int testData5[10] = {-1, 0, -1, 1, -1, 2, -1, 3, -1, 4};
    int testData6[10] = {1, 0, -1, 1, 1, 2, -1, 3, 1, 4};
    int testData7[10] = {2, 2, 5, 5, 4, 4, 1, 1, 3, 3};
    int testData8[12] = {1, 1000000000, 1, 100000000, 1, 1000000, 1, 10000, 1, 100, 1, 0};
    myPolynomial p4(5, testData4);
    myPolynomial p5(5, testData5);
    myPolynomial p6(5, testData6);
    myPolynomial p7(5, testData7);
    myPolynomial p8(6, testData8);
    myPolynomial p9(p7);
    // test constructor
    cout << p0 << endl << p1 << endl << p2 << endl;
    cout << p4 << endl << p8 << endl;
    // test copy constructor
    cout << p9 << endl;
    // test accessor function
    cout << p8.getDegree() << " " << p8.getNumTerms() << endl;
    // test evaluation function
    cout << p1(2) << " " << p2(2) << " " << p3(2) << " " << p4(2) << " " << endl;
    cout << p5(3) << " " << p6(3) << " " << p7(3) << " " << p9(3) << " " << endl;
    // test comparison operators
    cout << (p7 == p9) << " " << (p7 != p9) << endl;
    // // test derivative function
    cout << myPolynomial::ZERO.ddx() << endl;
    cout << myPolynomial::ONE.ddx() << endl;
    cout << myPolynomial::X.ddx() << endl;
    cout << p4.ddx() << endl;
    cout << p8.ddx() << endl;
    // test unary operator -
    cout << -myPolynomial::ZERO << endl;
    cout << -p4 << endl;
    // test k*p(x) or p(x) * k
    cout << 3*myPolynomial::ZERO << endl;
    cout << 3*myPolynomial::ONE << endl;
    cout << myPolynomial::X*3 << endl;
    cout << 3*p4 << " " << p4*3 << endl;
    cout << 0*p5 << " " << p5*5 << endl;
    // test binary operator +
    cout << p4 + p5 << endl;
    // test binary operator -
    cout << p6 - p7 << endl;
    // test binary operator *
    cout << p8 * p9 << endl;
    myPolynomial tmp1(p4), tmp2, tmp3, tmp4;
    tmp4 = tmp3 = tmp2 = tmp1;
    cout << (tmp1 += p5) << endl;
    cout << (tmp2 -= p5) << endl;
    cout << (tmp3 *= p5) << endl;
    cout << (tmp4 *= 3) << endl;
}

void testDataFromFile() {
    int numTestCases;
    cin >> numTestCases;
    for (int i=0; i<numTestCases; i++) {
        int numTerms, terms[100];
        /* read first polynomial */
        cin >> numTerms;
        for (int j=0; j<numTerms; j++)
            cin >> terms[2*j] >> terms[2*j+1];
        myPolynomial p1(numTerms, terms);
        /* read second polynomial */
        cin >> numTerms;
        for (int j=0; j<numTerms; j++)
            cin >> terms[2*j] >> terms[2*j+1];
        myPolynomial p2(numTerms, terms);
        cout << p1 << endl << p2 << endl;
        cout << p1.getDegree() << " " << p2.getNumTerms() << endl;
        cout << p1.ddx() << endl << p2.ddx() << endl;
        cout << (p1 == p2) << " " << (p1 != p2) << endl;
        cout << p1(1) << endl;
        cout << -p1 + p1 * 2 * p2 - p2 * 2 + 3 * p1 << endl;
        myPolynomial p3(myPolynomial::ZERO), p4(myPolynomial::ONE), p5(myPolynomial::X);
        p3 += p1;
        p4 -= p2;
        p5 *= p4;
        p5 *= 2;
        cout << p5 << endl;
    }
}