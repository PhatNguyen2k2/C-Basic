//https://www.hackerrank.com/challenges/reduced-string/problem
#include<bits/stdc++.h>
#define faster() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
int main(){
    faster()
    string s;
    cin>> s;
    for(int i=0; i < s.length(); i++){
        if(s[i] == s[i+1]){
            s.erase(i,2);
            i=-1;
        }
    }
    cout<<(s.length()==0?"Empty String":s)<<endl;
}