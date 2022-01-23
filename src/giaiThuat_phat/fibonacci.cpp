//https://baitapgiaithuat.com/problem/Doraemon_05
#include<bits/stdc++.h>
#define run() int T; cin>>T; cin.ignore(); while(T--)
using namespace std;
bool perfectSquare(int x){
    int s = sqrt(x);
    return (s*s == x);
}
bool fibonacci(int n){
    return perfectSquare(5*n*n + 4) || perfectSquare(5*n*n - 4);
}
int main(){
    run(){
        int n;  cin>>n;
        vector<int>a(n);
        for(auto &i : a)    cin>>i;
        int count = 0;
        for(int i = 0; i < n; i++){
            if(fibonacci(a[i])) count++;
        }
        cout<<count<<endl;
    }
}