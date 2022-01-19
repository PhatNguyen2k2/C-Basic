//Nguyen Hoang Phat - 6151071082 - CNTT K61
#include<bits/stdc++.h>
using namespace std;
int main(){ 
    ifstream in("OLP2021_05.INP");
    ofstream out("OLP2021_05.OUT");
    int m,n,k;
    in>>m>>n>>k;
    int sum=(m+n)-k;
    if(m>=n) 
        out<<sum/3;
    else 
        out<<(sum/3)-1;
    return 0;
}