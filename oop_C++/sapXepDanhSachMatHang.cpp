/*Sắp xếp danh sách mặt hàng
https://cdn.discordapp.com/attachments/862633303210459176/862633962828333067/unknown.png
https://cdn.discordapp.com/attachments/811609122805907466/862904552898691072/210509963_308930190979581_8164554273404551471_n.png*/
#include <bits/stdc++.h>
using namespace std;
class Mathang{
    private:
            int maMatHang;
            string tenMatHang, tenNhomHang;
            double giaMua, giaBan, loiNhuan;
    public:
            Mathang(){
                this->maMatHang = 0;
                this->tenMatHang = "tenMatHang";
                this->tenNhomHang = "tenNhomHang";
                this->giaMua = 1000.5;
                this->giaBan = 2000.6;
                this->loiNhuan = 1000.1;
            }
            Mathang(int maMatHang, string tenMatHang, string tenNhomHang, double giaMua, double giaBan, double loiNhuan){
                this->maMatHang = maMatHang;
                this->tenMatHang = tenMatHang;
                this->tenNhomHang = tenNhomHang;
                this->giaMua = giaMua;
                this->giaBan = giaBan;
                this->loiNhuan = loiNhuan;
            }
            void setMaMatHang(int a){
                this->maMatHang = a;
            }
            void setLoiNhuan(){
                this->loiNhuan = giaBan-giaMua;
            }
            double getLoiNhuan(){
                return loiNhuan;
            }
            friend istream &operator>>(istream &input, Mathang &mathang){
                fflush(stdin);
                getline(cin, mathang.tenMatHang);
                fflush(stdin);
                getline(cin, mathang.tenNhomHang);
                fflush(stdin);
                cin>>mathang.giaMua;
                cin>>mathang.giaBan;
            }
            void display(){
                cout<<maMatHang<<" "<<tenMatHang<<" "<<tenNhomHang<<" "<<loiNhuan;
            }
};
class compare{
    public:
        bool operator () (Mathang first, Mathang second){
            return first.getLoiNhuan()<second.getLoiNhuan();
        }
};
class MATHANG{
    private:
            vector<Mathang> list;
    public:
            MATHANG(){
                list = vector<Mathang>();
            }
            void add(Mathang mathang){
                this->list.push_back(mathang);
            }
            void sort(){
                std::sort(list.begin(),list.end(), compare());
            }
            void display(){
                for(auto i : list){
                    i.display();
                    cout<<endl;
                }
            }
};
int main(){
    Mathang mathang;
    MATHANG arr = MATHANG();
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>mathang;
        mathang.setMaMatHang(i);
        mathang.setLoiNhuan();
        arr.add(mathang);
    }
    arr.sort();
    arr.display();
}