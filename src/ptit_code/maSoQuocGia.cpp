/*Trong mã hóa người ta thường ghi kèm mã số quốc gia sản xuất. Nếu sản xuất tại VN thì
mã sản xuất là 084. Cho 1 dãy mã dạng số nguyên không quá 18 chữ số, hãy loại bỏ
đoạn mã 084 ra khỏi mã ban đầu*/
#include <iostream>
#include <string>
using namespace std;
int main(){
    int T;
    cin>>T;
    while(T--){
        long long num;
        cin>>num;
        string a = to_string(num);//chuyển thành xâu
        for(int i=0; i< a.size(); i++){
            if(a[i]=='0' && a[i+1]=='8' && a[i+2]=='4'){
                a.erase(a.begin()+i, a.begin()+i+3);
                break;
            }
        }
        cout<<a<<endl;
    }
}