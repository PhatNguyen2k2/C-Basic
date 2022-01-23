//Nguyen Hoang Phat
//6151071082
#include<iostream>
using namespace std;
class TaiKhoan {
  private:
         float  m_fSoDu = 0;
  public:
      float baoSoDu(){   
            return m_fSoDu; 
      }
void napTien(float fSoTien){
       m_fSoDu += fSoTien;  
}
void rutTien(float fSoTien) {
   if (fSoTien <= m_fSoDu)
          m_fSoDu -= fSoTien;
  }  
};
class TaiKhoanTietKiem: public TaiKhoan{
    private:
        int kyHan;
        float laiSuat;
        int soThang;
    public:
        void input();
        void napTienTietKiem();
        void rutTienKyHan();
        void tangThang();
        float soDuHienTai();
};
void TaiKhoanTietKiem::input(){
    cout<<"Tang ky han gui them: ";
    cin>>kyHan;
    soThang = kyHan;
}
void TaiKhoanTietKiem::napTienTietKiem(){
    float fsoTien;
    cout<<"Nhap so tien can nap: ";
    cin>>fsoTien;
    napTien(fsoTien);
    soThang = 0;
}
void TaiKhoanTietKiem::rutTienKyHan(){
    if(soThang<kyHan){
        cout<<"Chua den han"<<endl;
        return;
    }else{
        float fsoTien;
        cout<<"Nhap so tien can rut: ";
        cin>>fsoTien;
        if(fsoTien <= baoSoDu()){
            rutTien(fsoTien);
            cout<<"Da rut "<<fsoTien<<endl;
        }else{
            cout<<"Khong du so du"<<endl;
        }
    }
}
void TaiKhoanTietKiem::tangThang(){
    cout<<"Ky han gui: ";
    cin>>kyHan;
    soThang += kyHan;
}
float TaiKhoanTietKiem::soDuHienTai(){
    return baoSoDu();
}
int main(){
    TaiKhoanTietKiem a;
    a.input();
    a.napTienTietKiem();
    a.tangThang();
    a.rutTienKyHan();
    cout<<"So du: "<<a.soDuHienTai()<<endl;
}