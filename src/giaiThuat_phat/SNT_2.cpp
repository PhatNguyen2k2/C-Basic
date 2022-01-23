//https://cdn.fbsbx.com/v/t59.2708-21/240562227_357409326045932_1376882015779484189_n.gif?_nc_cat=100&fallback=1&ccb=1-5&_nc_sid=041f46&_nc_ohc=jgNLee7h7UIAX9Kx6k9&_nc_ht=cdn.fbsbx.com&oh=b9ae77b5f332711fa9afc63ff3204d46&oe=612DA513
#include <bits/stdc++.h>
#define faster() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define run() int T; cin>>T; cin.ignore(); while(T--)
using namespace std;
bool separation_check(int n){
    bool check = true;
    if(n/10==0) return true;
    else{
        while(n){
            int k = n % 10;
            if(k<2) return false;
            for (int i = 2; i <= sqrt(k); i++){
                if (k % i == 0){
                    check = false;
                }
            }
            n /= 10;
        }
    }
    return check;
}
int main(){
    faster()
    run(){
    int a,b,count=0;
    cin>>a>>b;
    vector<bool> isPrime(a - b + 1, true);  
    for(int i = 2; i * i <= b; i++){
        for(int j = max(i * i, (a + i - 1) / i * i); j <= b; j += i){
            isPrime[j - a] = false;
        }
    }
    if (1 >= a){
        isPrime[1 - a] = false;
    }
    for (int i = a; i <= b; i++){
        if (isPrime[i - a] && separation_check(i)){
            count++;
        }
    }
    cout<<count<<endl;
    }
    return 0;
}