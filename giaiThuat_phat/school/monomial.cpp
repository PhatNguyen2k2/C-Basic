//Ten: Nguyen Hoang Phat
//MSSV: 6151071082
#include<iostream>
#include<cmath>
using namespace std;
class Monomial{
    private:
        float exponential;//bac
        float coefficient;//he so
    public:
        void enter();
        void print();
        float replaceX(float x);
        void compare(Monomial p);
        void derivation();//dao ham
        void primitive();//nguyen ham
        float getExponential();
        float getCoefficient();
        Monomial summation(Monomial d);
        Monomial subtraction(Monomial d);
        Monomial multiplication(Monomial d);
        Monomial division(Monomial d);
};
void Monomial::enter(){
    cout<<"Enter exponential: ";
    cin>>exponential;
    cout<<"Enter coefficient: ";
    cin>>coefficient;
}
void Monomial::print(){
    cout<<coefficient<<"X^"<<exponential<<endl;
}
float Monomial::replaceX(float x){
    return coefficient*pow(x,exponential);
}
void Monomial::compare(Monomial p){
    if(exponential != p.exponential){
        cout<<"exponential arenot same"<<endl;
    }else{
        if(coefficient>p.coefficient){
            cout<<"Bigger"<<endl;
        }
        else if(coefficient<p.coefficient){
            cout<<"Smaller"<<endl;
        }
        else cout<<"Equal"<<endl;
    }
}
void Monomial::derivation(){
    if(coefficient==1){
        cout<<coefficient<<endl;
    }
    else{
    float a = exponential * coefficient;
    float b = exponential -1;
    cout <<a<<"X^"<<b<<endl;
    }
}
void Monomial::primitive(){
    float p = exponential + 1;
    cout<<"("<<coefficient<<"X^"<<p<<")/"<<p<<endl;
}
float Monomial::getExponential(){
    return this->exponential;
}
float Monomial::getCoefficient(){
    return this->coefficient;
}
Monomial Monomial::summation(Monomial d){
    Monomial t;
    if(exponential != d.exponential){//chi cung bac
        t.coefficient = t.exponential = 0;
    }else{
    t.coefficient = coefficient + d.coefficient;
    t.exponential = d.exponential;
    }
    return t;
}

Monomial Monomial::subtraction(Monomial d){
    Monomial t;
    if(exponential != d.exponential){//chi cung bac
        t.coefficient = t.exponential = 0;
    }else{
    t.coefficient = coefficient - d.coefficient;
    t.exponential = d.exponential;
    }
    return t;
}

Monomial Monomial::multiplication(Monomial d){
    Monomial t;
    if(exponential == d.exponential){//chi khac bac
        t.coefficient = t.exponential = 0;
    }
    else{
    t.coefficient = coefficient * d.coefficient;
    t.exponential = exponential + d.exponential;
    }
    return t;
}

Monomial Monomial::division(Monomial d){
    Monomial t;
    if(exponential == d.exponential){//chi khac bac
        t.coefficient = t.exponential = 0;
    }
    else{
    t.coefficient = float(coefficient / d.coefficient);
    t.exponential = exponential - d.exponential;
    }
    return t;
}
int main(){
    Monomial a,b;
    float x;
    a.enter();
    a.print();
    cout<<"Enter x: ";
    cin>>x;
    cout<<"After replace x: "<<a.replaceX(x)<<endl;
    cout<<"Derivation of monomial: ";
    a.derivation();
    cout<<"Primitive funtion of monomial: ";
    a.primitive();
    b.enter();
    b.print();
    cout<<"Compare first with second monomial: ";
    a.compare(b);
    cout<<"Summation: ";
    a.summation(b).print();
    cout<<"Subtraction: ";
    a.subtraction(b).print();
    cout<<"Multiplication: ";
    a.multiplication(b).print();
    cout<<"Division: ";
    a.division(b).print();
}