#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, l;
    cin>>n>>l;
    long long S = pow(l,2), sum = 0;
    for(int i=0; i<=n; i++){
        sum += S;
        S *= 4;
    }
    cout<<sum%1000009<<endl;
}