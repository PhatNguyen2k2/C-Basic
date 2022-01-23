/*Cho N nhập vào từ bàn phím (0<N<1000),sinh một số nguyên tố p<100. 
Hãy viết chương trình tìm tất cả các số nguyên a<N sao cho a^p mod N là số nguyên tố.*/
#include<bits/stdc++.h>
#define faster() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
int pow(int a, int b, int mod){ //big modulo
    int res = 1;
    for(int i=b; i; i>>=1 ) {
        if(i & 1)
        res = res * a % mod;
        a = a * a % mod;
    }
    return res;
}
bool check(int k){
    bool check = false;
    if(k<2) return false;
    for(int i = 2; i <= sqrt(k); i++){
        if(k%i==0) check = true;
    }
    return check;
}
int main(){
    faster()
    int n, p;
    cin>>n>>p;
    int count = 0;
    for(int i=1; i<=n; i++){
        if(check(pow(i,p,n))) count++;
    }
    cout<<count<<endl;
}