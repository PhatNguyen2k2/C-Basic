//https://www.hackerrank.com/challenges/hackerland-radio-transmitters/problem
#include<bits/stdc++.h>
#define faster() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define run() int T, k; cin>>T; cin>>k; cin.ignore(); while(T--)
using namespace std;
int main(){
    faster()
    vector<int> arr;
    run(){
        int a; cin>>a;
        arr.push_back(a);
    }
    sort(arr.begin(), arr.end());
    int n = arr.size();
    //greedy algorithm
    int count = 0, i = 0;
    while(i<n){
        count++;
        /*sử dụng tham lam để luôn đặt radio ở 
        ngôi nhà xa nhất về bên phải có thể để bao phủ phạm vi*/
        int location = arr[i]+k; // i gốc
        //đi về bên phải xa nhất có thể bao phủ i gốc
        while(i<n && arr[i] <= location) i++;
        i--; //đây là nơi đặt radio
        /*đi tiếp về bên phải của arr[i] bằng k bởi vì 
        radio tại arr[i] cũng bao phủ các ngôi nhà ở bên phải của nó*/
        location = arr[i]+k;
        while(i<n && arr[i] <= location) i++;
    }
    cout<<count<<endl;
}