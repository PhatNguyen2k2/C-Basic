//Nguyen Hoang Phat - 6151071082
#include <bits/stdc++.h>
using namespace std;
class Fraction{
    private:
        float numerator;
        float denominator;
    public:
        Fraction();
        ~Fraction();
        friend istream& operator>>(istream& is, Fraction& fraction);
        friend float greatestCommonDivisor(float a, float b);
        friend void compactFraction(Fraction &fraction);
        friend ostream& operator<<(ostream& os, Fraction fraction);
};
Fraction::Fraction(){
    numerator = 0;
    denominator = 1;
}
Fraction::~Fraction(){}
istream& operator>>(istream& is, Fraction& fraction){
    cout<<"Enter numerator: ";
    is>>fraction.numerator;
    do{
    cout<<"Enter denominator: ";
    is>>fraction.denominator;
    }while(fraction.denominator == 0);
    return is;
}
ostream& operator<<(ostream& os, Fraction fraction){
    os<<fraction.numerator<< "/" <<fraction.denominator<<endl;
    return os;
}
void input(Fraction a[], int n){
    for(int i=0; i<n;i++){
        cout<<"Enter fraction "<<i<<": "<<endl;
        cin>>a[i];
    }
}
float greatestCommonDivisor(float a, float b)
{

    a = abs(a);
    b = abs(b);
    while (a != b)
    {
        if (a > b)
            a = a - b;
        else
            b = b - a;
    }
    return a;
}
void compactFraction(Fraction &fraction)
{
    float c = greatestCommonDivisor(fraction.numerator, fraction.denominator);
    fraction.numerator = fraction.numerator / c;
    fraction.denominator = fraction.denominator / c;
}
void output(Fraction a[], int n){
    for(int i=0; i<n;i++){
        cout<<"Fraction "<<i<<": ";
        compactFraction(a[i]);
        cout<<a[i];
    }
}
int main(){
    int n;
    cout<<"Enter n: ";  cin>>n;
    Fraction list[n];
    input(list,n);
    output(list, n);
}