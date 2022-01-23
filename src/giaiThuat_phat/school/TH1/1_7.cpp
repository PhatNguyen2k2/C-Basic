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
        friend ostream& operator<<(ostream& os, Fraction fraction);
        friend bool operator >=(Fraction a, Fraction b);
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
bool operator >=(Fraction a, Fraction b){
    return ((float)(a.numerator)/a.denominator > b.numerator/b.denominator) || ((float)(a.numerator)/a.denominator == b.numerator/b.denominator);
}
void input(Fraction a[], int n){
    for(int i=0; i<n;i++){
        cout<<"Enter fraction "<<i<<": "<<endl;
        cin>>a[i];
    }
}
void output(Fraction a[], int n){
    for(int i=0; i<n;i++){
        cout<<"Fraction "<<i<<": ";
        cout<<a[i];
    }
}
void max_min(Fraction a[], int n){
    for(int i=0; i<n-1;i++){
        for(int j=i+1; j<n; j++){
            if(a[i] >= a[j]){
                swap(a[j], a[i]);
            }
        }
    }
    cout<<"Max fraction: "<<a[5-1]<<endl;
    cout<<"Min fraction: "<<a[0]<<endl;
}
int main(){
    Fraction a, b;
    cin>>a>>b;
    cout<<a<<b;
    if(a >= b){
        cout<<"Bigger or equal"<<endl;
    }else cout<<"Smaller"<<endl;
    Fraction list[5];
    input(list, 5);
    output(list, 5);
    max_min(list, 5);
}