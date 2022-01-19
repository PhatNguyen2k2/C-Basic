//https://scontent-hkg4-2.xx.fbcdn.net/v/t1.15752-9/217393827_372590920925677_6172670411016772151_n.png?_nc_cat=110&ccb=1-3&_nc_sid=ae9488&_nc_ohc=XhvudQWGS0kAX8dD2gQ&_nc_ht=scontent-hkg4-2.xx&oh=c44c182d95e4b85998271c2e657e6c8b&oe=61275234
#include<bits/stdc++.h>
#define faster() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define run() int T; cin>>T; cin.ignore(); while(T--)
using namespace std;
bool checkStrongPassword(string password)
{
    string p = "!@#$%^&*()-+";
    bool check1=false, check2=false, check3=false, check4=false;
    for(auto i : password){
        if(i >= 65 && i <= 90) check1=true; //chữ in
        if(i >= 97 && i <= 122) check2=true; //chữ thường
        if(i >= 48 && i <= 57) check3=true; //số
        if(p.find(i)!= -1) check4=true; //kí tự special
    }
    return check1 && check2 && check3 && check4 && bool(password.size()>=6);
}
int main(){
    faster()
    run(){
        string s; cin>>s;
        cout<<boolalpha<<checkStrongPassword(s)<<endl;
    }
}