//https://www.hackerrank.com/challenges/countingsort4/problem
#include<bits/stdc++.h>
#define faster() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
int main() {
    faster()
    long int n;
    cin >> n; 
    string arr[n];
    for(long int i = 0; i < n/2; i++){
        int x;
        cin >> x;
        string s;
        cin >> s;
        arr[x] = arr[x] + "-" + " ";    
    }
    for(long int i = n/2; i < n; i++){
        int x;
        cin >> x;
        string s;
        cin >> s;
        arr[x] = arr[x] + s + " ";  
    }
    for(int i = 0; i < n; i++)
        cout << arr[i];
    return 0;
}