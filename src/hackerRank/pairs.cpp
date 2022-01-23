//https://www.hackerrank.com/challenges/pairs/problem
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
    //2 pointer technique
    int i=0,j=1,temp=0,count=0;
    while(j < arr.size()){
        temp = arr[j] - arr[i];
        if (temp == k) {
            count++;
            j++;
        } else if (temp > k) {
            i++;
        } else if (temp < k) {
            j++;
        }
    }
    cout<<count<<endl;
}