//https://www.hackerrank.com/challenges/angry-children/problem
#include<bits/stdc++.h>
#define faster() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define run() int T, k; cin>>T; cin>>k; cin.ignore(); while(T--)
using namespace std;
int maxMin(int k, vector<int> arr) {
    int m=INT_MAX;
    sort(arr.begin(),arr.end());
    for(int i=0;i<arr.size()-k+1;i++){
        int n=(arr[i+k-1]-arr[i]);
        if(n<m){
            m=n;
        }
    }
    return m;
}
int main(){
    faster()
    vector<int> arr;
    run(){
        int a; cin>>a;
        arr.push_back(a);
    }
    cout<<maxMin(k, arr)<<endl;
}