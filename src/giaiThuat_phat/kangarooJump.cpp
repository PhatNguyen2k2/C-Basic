//https://scontent-sin6-2.xx.fbcdn.net/v/t1.6435-9/233381030_287426466475426_4654594164990844473_n.jpg?_nc_cat=102&ccb=1-4&_nc_sid=825194&_nc_ohc=Ob97FXjR8X8AX_u8CAw&_nc_ht=scontent-sin6-2.xx&oh=494e3ff69bf093c62a928c409a6a26aa&oe=6136077F
#include<bits/stdc++.h>
#define faster() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
int kangaroo(int n, int a, int b){
    int result = -1;
    if(n%b == 0) result = n/b;
    else{
        for(int i = round(n/b);i>0;i--){
            if((n-(i*b))%a == 0){
                long long count = ((n-(i*b))/a);
                result = i + count;
                break;
            }
        }
    }
    if(result == -1 && n%a == 0) result = n/a;
    return result;
}
int main(){
    faster()
    int n,a,b;
    cin>>n>>a>>b;
    cout<<kangaroo(n,a,b)<<endl;
}