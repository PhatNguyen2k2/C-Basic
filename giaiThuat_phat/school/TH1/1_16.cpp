//Nguyen Hoang Phat - 6151071082
#include<iostream>
using namespace std;
class Fraction{
	private:
		int tu, mau;
	public:
		Fraction();
        Fraction(int a, int b);
		void nhap();
		void xuat();	
        bool operator ==(Fraction ps);
};
Fraction::Fraction()
{
	tu=0;
	mau=1;
}

Fraction::Fraction(int a, int b)
{
	tu=a;
	mau=b;
}        
void Fraction::nhap(){
	cout<<"Nhap tu: ";
	cin>>tu;
	cout<<"Nhap mau: ";
	cin>>mau;
}
void Fraction::xuat(){
	if(this->mau==1)
		cout<<tu<<endl;
	else
		cout<<tu<<"/"<<mau;
}
bool Fraction::operator ==(Fraction ps)
{
    if((this->tu == ps.tu) && (this->mau == ps.mau)) 
        return true;
    return false;
}
int main(){
    Fraction ps[5], x;
 
    for(int i = 0; i < 5; i++)
    {
        cout<<"Nhap vao Phan So thu "<<i + 1<<": "<<endl;
        ps[i].nhap();
    }

    for(int i = 0; i < 5; i++)
    {
        cout<<"\nPhan So thu"<<i + 1<<": ";
        ps[i].xuat(); 
    }

    cout<<"\nNhap Phan So can tim: "; x.nhap();
    int dem = 0;
    for(int i = 0; i < 5; i++) 
    {
        if (ps[i] == x) 
        {
            dem++;
            cout<<"Phan So "; x.xuat(); cout<<" co trong mang"<<endl; 
        } 
    }
    if(dem == 0){ 
        cout<<"Khong co Phan So " ; x.xuat() ; cout<<" trong mang "<<endl; 
    }
    return 0;
}