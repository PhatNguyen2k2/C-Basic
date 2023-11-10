#include<bits/stdc++.h>
using namespace std;

bool check(int n){
    if (n < 2) return false;
    int i;
    for (i = 2; i <= sqrt(n); i++){
        if (n % i == 0) return false;
    }
    return true;
}
int main(){
    int n;  cin>>n;
    vector<int> v;
    for(int i=0; i<n; i++){
        if(check(i))
            v.push_back(i);
    }
    return 0;
}