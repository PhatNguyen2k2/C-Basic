//tren luoi khong deu
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, l, t, k;
    cout<<"Enter n: ";    cin>>n;
    float x[n], y[n], p[n][n], c, kq;
    for(int i=0; i<n;i++){
        cout<<"Enter x["<<i<<"], y["<<i<<"]: ";
        cin>>x[i]>>y[i];
    }
    for(int i=0; i<n;i++){
        p[i][0]=x[i];
        p[i][1]=y[i];
    }
    l = 1;
    for(int j=0;j<n;j++){
        k=j+2;
        for(t = l; t<n; t++){
            p[t][k]=(p[t][k-1]-p[t-1][k-1])/(x[t]-x[t-1]);
        }
        l=l+1;
    }
    for(int i=0; i<n;i++){
        for(int j=0; j<n+2;j++){
            cout<<p[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"Enter number need to calc: ";
    cin>>c;
    float mul;
    for(int i=0; i<n;i++){
        mul=1;
        for(int j=0; j<i;j++){
            mul *= (c-x[j]);
        }
        kq= kq+p[i][i+1]*mul;
    }
    cout<<"Answer: "<<kq<<endl;
}