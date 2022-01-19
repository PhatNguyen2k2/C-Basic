//Nguyen Hoang Phat - 6151071082
#include <iostream>
using namespace std;

class MyDate
{
    private:
        int day, month, year;
    public:
        MyDate();
        MyDate(int day, int month, int year);
        MyDate(const int a);
        void Nhap();
        void Xuat();
        bool operator ==(MyDate mydate);
        int getYear();
        int getMonth();
        int getDay();
};
MyDate::MyDate()
{
    this->day = 25;
    this->month = 8;
    this->year = 2001;
}
MyDate::MyDate(int day, int month, int year)
{
    this->day = day;
    this->month = month;
    this->year = year;
}
MyDate::MyDate(const int a)
{
    this->day = this->month = this->year = a;
}
void MyDate::Nhap()
{
    cout<<"\nNhap Ngay: "; cin>>day;
    cout<<"\nNhap Thang: "; cin>>month;
    cout<<"\nNhap Nam: "; cin>>year;
}
void MyDate::Xuat()
{
    cout<<day<<" - "<<month<<" - "<<year;
}
bool MyDate::operator ==(MyDate mydate)
{
    if((this->year == mydate.year) && (this->month == mydate.month) && (this->day == mydate.day)) 
        return true;
    return false;
}
int MyDate::getDay()
{
    return this->day;
}
int MyDate::getMonth()
{
    return this->month;
}
int MyDate::getYear()
{
    return this->year;
}
int main()
{
    MyDate a[5], x;

    for(int i = 0; i < 2; i++)
    {
        cout<<"Nhap vao MyDate thu "<<i + 1<<": "<<endl;
        a[i].Nhap();
    }
    
    for(int i = 0; i < 5; i++)
    {
        cout<<"MyDate thu"<<i + 1<<": "<<endl;
        a[i].Xuat(); 
    }

    cout<<"\nNhap MyDate can tim: ";
    x.Nhap();
    int dem = 0;
    for(int i = 0; i < 5; i++) 
    {
        if (a[i] == x) 
        {
            dem++;
            cout<<"Phan tu "; x.Xuat(); cout<<" co trong mang, xuat hien so lan: "<<dem<<endl; 
        } 
    }
    if(dem == 0)
        { 
            cout<<"Khong co phan tu " ; x.Xuat() ; cout<<" trong mang "<<endl; 
        }

    return 0;
}