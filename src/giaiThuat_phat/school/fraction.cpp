// Nguyen Hoang Phat 6151071082
#include<iostream>
#include<string>
using namespace std;
class Fraction{
    private:
        int numerator;
        int denominator;
    public:
        void enter(){
            cout<<"Numerator: ";
            cin>>numerator;
            cout<<"Denominator: ";
            cin>>denominator;
        }
        int getNumerator(){
            return numerator;
        }
        int getDenominator(){
            return denominator;
        }
        void print(){
            cout<<numerator<<"/"<<denominator<<endl;
        }
};
void summationFraction(Fraction first_fraction, Fraction second_fraction)
{
    //tổng 2 phân số
    int Numerator = (first_fraction.getNumerator() * second_fraction.getDenominator()) + (second_fraction.getNumerator() * first_fraction.getDenominator());
    int Denominator = first_fraction.getDenominator() * second_fraction.getDenominator();
    cout<<Numerator<<"/"<<Denominator<<endl;
}
void subtractionFraction(Fraction first_fraction, Fraction second_fraction)
{
    //hiệu 2 phân số
    int Numerator = (first_fraction.getNumerator() * second_fraction.getDenominator()) - (second_fraction.getNumerator() * first_fraction.getDenominator());
    int Denominator = first_fraction.getDenominator() * second_fraction.getDenominator();
    cout<<Numerator<<"/"<<Denominator<<endl;
}
void multiplicationFraction(Fraction first_fraction, Fraction second_fraction)
{
    //Tích 2 phân số
    int Numerator = first_fraction.getNumerator() * second_fraction.getNumerator();
    int Denominator = first_fraction.getDenominator() * second_fraction.getDenominator();
    cout<<Numerator<<"/"<<Denominator<<endl;
}
void devisionFraction(Fraction first_fraction, Fraction second_fraction)
{
    //Thương 2 phân số
    int Numerator = first_fraction.getNumerator() * second_fraction.getDenominator();
    int Denominator = first_fraction.getDenominator() * second_fraction.getNumerator();
    cout<<Numerator<<"/"<<Denominator<<endl;
}
int main(){
    Fraction f1;
    Fraction f2;
    f1.enter();
    f2.enter();
    summationFraction(f1,f2);
    subtractionFraction(f1,f2);
    multiplicationFraction(f1, f2);
    devisionFraction(f1, f2);
}