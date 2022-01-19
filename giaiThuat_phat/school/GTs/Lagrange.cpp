#include<bits/stdc++.h>
#define run() int T; cin>>T; cin.ignore(); while(T--)
using namespace std;
int main(){
    float x[7],y[7];
    int n; cin>>n;
    for(int i=0;i<=n;i++){
        cin>>x[i]>>y[i];
    }
    cout<<setiosflags(ios::showpoint)<<setprecision(5);
    run(){
    float f=0, xx;
    cin>>xx;
    for(int i=0;i<=n;i++){
        float p=1;
        for(int j=0;j<=n;j++)
        if(j!=i) p*=(xx-x[j])/(x[i]-x[j]);
        f+=y[i]*p;
    }
    cout<<"f("<<xx<<")="<<f<<endl; 
    }
    return 0;
}