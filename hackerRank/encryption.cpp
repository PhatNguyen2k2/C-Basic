//https://www.hackerrank.com/challenges/encryption/problem
#include<bits/stdc++.h>
using namespace std;
int main(){
    string msg;
    int row,col;
    cin>>msg;
    int len=msg.length();
    row=(int)sqrt(len);
    if((row*row)==len) col=row;
    else if(len<=(row*(row+1))) col=row+1;
    else{
        row=row+1;
        col=row;
    }
    for(int i=0;i<col;i++){
        for(int j=i; j<len; j+=col)
            cout<<msg[j];
        cout<<" ";
    }
    cout<<endl;
    return 0;
}