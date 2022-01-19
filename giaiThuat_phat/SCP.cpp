#include<bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        for(int i=1; i <= n; i++){
            if(sqrt(i)==(int)(sqrt(i))){
                cout<<i<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}