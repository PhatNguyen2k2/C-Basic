//Nguyen Hoang Phat - 6151071082
#include<iostream>
using namespace std;
class Fraction
{
	private:
		int tu, mau;
	public:
		Fraction();
        Fraction(int a, int b);
        Fraction(const int &c);
		void nhap();
		void xuat();
        bool operator >=(Fraction ps);
        bool operator <(Fraction ps);
        bool operator >(Fraction ps);
};
Fraction::Fraction()
{
	tu=1;
	mau=1;
}

Fraction::Fraction(int a, int b)
{
	tu=a;
	mau=b;
}  
Fraction::Fraction(const int &c)
{
	tu=c;
	mau=c;
} 
void Fraction::nhap()
{
	cout<<"Nhap tu: ";
	cin>>tu;
	cout<<"Nhap mau: ";
	cin>>mau;
}
void Fraction::xuat()
{
	if(this->mau==1)
		cout<<tu<<endl;
	else
		cout<<tu<<"/"<<mau<<endl;
}
bool Fraction::operator >=(Fraction ps)
{
    float a;
    a = this->tu*ps.mau - this->mau*ps.tu;
    if(a >= 0) 
        return true;
    return false;
}
bool Fraction::operator >(Fraction ps)
{
    float a;
    a = this->tu * ps.mau - this->mau * ps.tu;
    if(a > 0) 
         return true;
    return false;
}
bool Fraction::operator <(Fraction ps)
{
    float a;
    a = this->tu * ps.mau - this->mau * ps.tu;
    if(a < 0) 
        return true;
    return false;
}
int main()
{
    Fraction ps1, ps2;
    cout<<"Nhap phan so thu 1: "<<endl; ps1.nhap(); 
    cout<<"Nhap phan so thu 2: "<<endl; ps2.nhap();
    ps1.xuat();
    ps2.xuat();
    if(ps1 >= ps2)
        cout<<"Phan so 1 >= Phan so 2"<<endl;
    else
        cout<<"Phan so 1 < Phan so 2"<<endl;

    Fraction *p;
    p = new Fraction[5];
    for(int i = 0; i < 5; i++)
    {
        cout<<"Nhap phan so thu "<<i<<": "<<endl;
        p[i].nhap();
    }
    Fraction max, min;
    max = p[0]; min = p[0]; 
    for(int i = 1; i<5; i++)
    {
        if(p[i] > max)
            max = p[i];
        else if(p[i] < min)
            min = p[i];
    }
    cout<<"Phan so lon nhat: ";
    max.xuat();
    cout<<"Phan so nho nhat: ";
    min.xuat();

    return 0;
}