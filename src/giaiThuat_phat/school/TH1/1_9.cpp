//Nguyen Hoang Phat - 6151071082
#include<bits/stdc++.h>
using namespace std;
 
class MyDate{
    private:
        int day,month,year;
    public:
        MyDate();
        ~MyDate();
        void input();
        void output();
        friend bool operator >(MyDate &a, MyDate &b);
};
MyDate::MyDate(){
    this->day =0;
    this->month =0;
    this->year =0;
}
MyDate::~MyDate(){}
void MyDate::input(){
    cout<<"\nNhap ngay: "; cin>>day;
    cout<<"\nNhap thang: "; cin>>month;
    cout<<"\nNhap nam: "; cin>>year;
}
void MyDate::output(){
    cout<<endl<<day<<"-"<<month<<"-"<<year;
}
bool operator >(MyDate &a, MyDate &b){
    if(a.year >b.year) return true;
    else if(a.year == b.year) {
        if(a.month >b.month) return true;
        else if(a.month == b.month) {
            if(a.day >b.day) return true;
        }
    }
    return false;
}
int main(){
    int n;
    cout<<"Enter n: "; cin>>n;
    MyDate a[n];
    for(int i=0; i<n; i++){
        a[i].input();
    }
    for(int i=0; i<n; i++){
        a[i].output();
    }
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(a[i] > a[j]) swap(a[i], a[j]);
        }
    }
    cout<<endl<<"-->After sort: ";
    for(int i=0; i<n; i++){
        a[i].output();
    }
    return 0;
}