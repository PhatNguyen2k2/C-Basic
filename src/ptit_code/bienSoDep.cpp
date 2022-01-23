/*-->Biển số đẹp
5 chữ số được xếp thứ tự tăng chặt từ trái -> phải *
Cả 5 chữ số đều = nhau
3 chữ số đầu và 2 chữ số cuối bằng nhau *
cả 5 chữ số là 6 và/hoặc 8 (sô lộc phát) *
ví dụ số đẹp: 29-T1 123.79; 29-T1 555.55; 29-T1 222.33; 29-T1 686 88 */
#include <iostream>
#include <string>
using namespace std;
bool increase(string a){ // tăng chặt
    return (a[6]<a[7] && a[7]<a[8] && a[8]<a[10] && a[10]<a[11]);
}
bool equal(string a){ //chữ số = nhau
    bool check1 = false, check2 = false;
    if(a[6]==a[7] && a[7]==a[8]) check1 = true;
    if(a[10]==a[11]) check2 = true;
    return (check1 && check2);
}
bool lucky(string a){ //số lộc phát
    bool check = true;
    if(a[6] != '6' && a[6] != '8') check = false;
    if(a[7] != '6' && a[7] != '8') check = false;
    if(a[8] != '6' && a[8] != '8') check = false;
    if(a[10] != '6' && a[10] != '8') check = false;
    if(a[11] != '6' && a[11] != '8') check = false;
    return check;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        string num;
        fflush(stdin);
        getline(cin, num);
        if(increase(num) || equal(num) || lucky(num)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}