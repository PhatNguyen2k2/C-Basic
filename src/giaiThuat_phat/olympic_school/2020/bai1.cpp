#include<iostream>
using namespace std;
int main(){ 
    int m,n,k;
    cin>>m>>n>>k;
    int sum=(m+n)-k;
    if(m>=n) 
        cout<<sum/3;
    else 
        cout<<(sum/3)-1;
}