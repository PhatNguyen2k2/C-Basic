//https://scontent-sin6-4.xx.fbcdn.net/v/t1.15752-9/235050470_1189018828262885_8510889844917455894_n.png?_nc_cat=101&ccb=1-4&_nc_sid=ae9488&_nc_ohc=n3meP21i7aoAX9zBkBQ&_nc_ht=scontent-sin6-4.xx&oh=374a41f059c40a63d5a07569a0eca539&oe=6136A2D6
#include<bits/stdc++.h>
#define faster() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define run() int T; cin>>T; cin.ignore(); while(T--)
using namespace std;
int main(){
    faster()
    vector<int> arr;
    run(){
        int a; cin>>a;
        arr.push_back(a);
    }
    vector<int> S;
    S.push_back(arr[0]);
    for(int i=1; i < arr.size(); i++){
        if(S[i-1]<0) S.push_back(arr[i]);
        else S.push_back(S[i-1]+arr[i]);
    }
    cout<<*std::max_element(S.begin(),S.end())<<endl;
}