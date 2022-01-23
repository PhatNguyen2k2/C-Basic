#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin>>n;
    vector<vector<int> > v;
    v.resize(n);
    for(int i=0; i<n;i++) v.at(i).resize(11);
    for(int i=0; i<n; i++){
        for(int j=0; j<11; j++){
            cin>>v.at(i).at(j);
        }
    }
    int temp = 0;
    for (int i=0; i<n-2; i++){
        int sum = 0;
        for(int j=0; j<11;j++){
            sum += max(v.at(i).at(j), max (v.at(i+1).at(j), v.at(i+2).at(j)));
        }
        if(temp < sum) temp = sum;
    }
    cout<<temp<<endl;
}