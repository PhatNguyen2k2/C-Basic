#include<iostream>
using namespace std;
class Fraction {
private:
    int numerator, denominator;
public:
    friend istream& operator >>(istream& is, Fraction& ps);
    friend ostream& operator <<(ostream& os, const Fraction& ps);
    Fraction operator + (Fraction ps);
    Fraction operator - (Fraction ps);
    Fraction operator * (Fraction ps);
    Fraction operator / (Fraction ps);
    Fraction operator += (Fraction ps);
    Fraction operator -= (Fraction ps);
    Fraction operator *= (Fraction ps);
    Fraction operator /= (Fraction ps);
    bool operator > (Fraction ps);
    bool operator < (Fraction ps);
    bool operator >= (Fraction ps);
    bool operator <= (Fraction ps);
    bool operator == (Fraction ps);
};
int main() {
    Fraction a, b, c;
    cout << "Enter fraction a : " << endl;
    cin >> a;
    cout << "Enter fraction b : " << endl;
    cin >> b;
    cout << a;
    cout << b;
    c = a + b;
    cout << c;
    c = a - b;
    cout << c;
    c = a * b;
    cout << c;
    c = a / b;
    cout << c;
    c = a+=b;
    cout << c;
    c = a-=b;
    cout<< c;
    c = a*=b;
    cout << c;
    c = a/=b;
    cout << c;
    if (a > b) {
        cout << "Bigger"<<endl;
    }
    if(a < b) cout<<"Smaller"<< endl;
    if(a >= b) cout<<"Bigger or equal"<< endl;
    if(a<=b) cout<<"Smaller or equal"<< endl;
    if(a==b) cout<<"Equal"<< endl;
}
istream& operator >>(istream& is, Fraction& ps) {
    cout << "Enter numerator: ";
    is >> ps.numerator;
    cout << "Enter denominator: ";
    is >> ps.denominator;
    return is;
}
ostream& operator <<(ostream& os, const Fraction& ps) {
    os << ps.numerator << "/" << ps.denominator << endl;
    return os;
}
Fraction Fraction::operator + (Fraction ps) {
    Fraction t;
    t.numerator = numerator * ps.denominator +  denominator * ps.numerator;
    t.denominator = denominator * ps.denominator;
    return t;
}
Fraction Fraction::operator - (Fraction ps){
    Fraction t;
    t.numerator = numerator * ps.denominator -  denominator * ps.numerator;
    t.denominator = denominator * ps.denominator;
    return t;
}
Fraction Fraction::operator * (Fraction ps){
    Fraction t;
    t.numerator = numerator * ps.numerator;
    t.denominator = denominator * ps.denominator;
    return t;
}
Fraction Fraction::operator / (Fraction ps){
    Fraction t;
    t.numerator = numerator * ps.denominator;
    t.denominator = denominator * ps.numerator;
    return t;
}
Fraction Fraction::operator += (Fraction ps){
    numerator = numerator * ps.denominator +  denominator * ps.numerator;
    denominator = denominator * ps.denominator;
    return *this;
}
Fraction Fraction::operator -= (Fraction ps){
    numerator = numerator * ps.denominator -  denominator * ps.numerator;
    denominator = denominator * ps.denominator;
    return *this;
}
Fraction Fraction::operator *= (Fraction ps){
    numerator = numerator * ps.numerator;
    denominator = denominator * ps.denominator;
    return *this;
}
Fraction Fraction::operator /= (Fraction ps){
    numerator = numerator * ps.denominator;
    denominator = denominator * ps.numerator;
    return *this;
}
bool Fraction::operator > (Fraction ps) {
    return ((numerator / denominator) > (ps.numerator / ps.denominator));
}
bool Fraction::operator < (Fraction ps) {
    return ((numerator / denominator) < (ps.numerator / ps.denominator));
}
bool Fraction::operator >=(Fraction ps){
    return ((numerator / denominator) > (ps.numerator / ps.denominator) || (numerator / denominator) == (ps.numerator / ps.denominator));
}
bool Fraction::operator <=(Fraction ps){
    return ((numerator / denominator) < (ps.numerator / ps.denominator) || (numerator / denominator) == (ps.numerator / ps.denominator));
}
bool Fraction::operator ==(Fraction ps){
    return ((numerator / denominator) == (ps.numerator / ps.denominator));
}