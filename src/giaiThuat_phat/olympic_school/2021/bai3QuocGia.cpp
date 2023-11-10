#include <bits/stdc++.h>
using namespace std;
 
int mod  = 1000000007;
int kq;
 
int main(){
    int n; cin>>n;
    string a, b;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        int length = a.length();
        kq = 1;
        for(int j=0; j<length; j++){
            if(a[j] == 'X' && b[j] == 'X') kq *=2;
            else if(a[j] == 'O' && b[j] == 'O'){
                kq = 0;
                break;
            }
            kq %= mod;
        }
        cout<<kq<<endl;
    }
}