#include <bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        for(int i=1; i<=n;i++){
            if(i%2==1) cout<<i<<" ";
        }
        cout<<endl;
    }
    return 0;
}