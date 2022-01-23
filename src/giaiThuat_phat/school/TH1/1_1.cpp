//Nguyen Hoang Phat - 6151071082
#include<iostream>
using namespace std;

class Complex{
    private:
        float a; //real part
        float b; //imag part
    public:
        Complex();
        ~Complex();
        void input();
        void output();
        friend Complex operator +(Complex &a,Complex &b);
        friend Complex operator -(Complex &a,Complex &b);
};
Complex::Complex(){
    this->a=0;
    this->b=0;
}
Complex::~Complex(){}
void Complex::input(){
    cout<<endl<<"Enter real part: ";cin>>a;
    cout<<endl<<"Enter imag part: ";cin>>b;
}
void Complex::output(){
    cout<<"Complex: "<<a<<"+"<<b<<"i"<<endl;
}
Complex operator+(Complex &a,Complex &b){
    Complex c;
    c.a=a.a+b.a;
    c.b=a.b+b.b;
    return c;
}
Complex operator-(Complex &a,Complex &b){
    Complex c;
    c.a=a.a-b.a;
    c.b=a.b-b.b;
    return c;
}
int main(){
    Complex a,b;
    a.input();
    b.input();
    cout<<endl<<"Sum: ";
    (a+b).output();
    cout<<endl<<"Subtrac: ";
    (a-b).output();
    return 0;
}