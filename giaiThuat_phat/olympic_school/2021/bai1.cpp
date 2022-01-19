//Nguyen Hoang Phat - 6151071082 - CNTT K61
#include<bits/stdc++.h>
using namespace std;
int count(int n){
    if (n/10 == 0)  return 1;
    return 1 + count(n / 10);
}
int main(){
    int n, k = 5, temp = 0;  cin>>n;
    while(1){
        temp += count(k);
        if(temp >= n) break;
        k++;
    }
    cout<<k<<endl;
}