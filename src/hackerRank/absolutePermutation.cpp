//https://www.hackerrank.com/challenges/absolute-permutation/problem
#include<bits/stdc++.h>
#define run() int T; cin>>T; cin.ignore(); while(T--)
using namespace std;
int main(){
    int arr[100000];
    run(){
        int n, k;
        bool check[100000]={false};
        cin>>n>>k;
        if(k==0){
            for(int i=1; i<=n; i++) cout<<i<<" ";
        }else if(n%(2*k)!=0) cout<<-1;
        else{
            for(int i=1; i<=n; i++) arr[i]=i;
            for(int i=1; i<=n; i++){
                if(!check[i]){
                    swap(arr[i], arr[i+k]);
                    check[i]=true;
                    check[i+k]=true;
                }
            }
            for(int i=1;i<=n;i++) cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
}