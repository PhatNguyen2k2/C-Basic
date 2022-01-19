//Nguyen Hoang Phat - 6151071082 - CNTT K61
#include<bits/stdc++.h>
using namespace std;
int main(){
    ifstream in("OLP2021_02.INP");
    ofstream out("OLP2021_02.OUT");
    int n, k;
    in>>n>>k;
    int a[n],b[n];
    for(int i=0; i < n; i++){
        in>>a[i];
    }
    for(int i=0; i < n; i++){
        in>>b[i];
    }
    int min=b[0];
    for(int i=1; i < n; i++){
        if(a[i]>=k){
            if(b[i]<min) min=b[i];
        }
    }
    int count=0;
    for(int i=0; i < n; i++){
        if(b[i]==min){
            if(min == b[0]){
                if(a[0]>=k) count++;
            }else   count++;
        }
    }
    if(count==0){
        out<<-1<<endl;
    }else   out<<count<<" "<<min<<endl;
}