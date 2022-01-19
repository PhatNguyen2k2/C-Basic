//https://www.hackerrank.com/challenges/bigger-is-greater/problem
#include <bits/stdc++.h>
#define run() int T; cin>>T; cin.ignore(); while(T--)
using namespace std;
int main() {
    string s;
    run(){
        cin >> s;
        if (next_permutation(s.begin(), s.end())) cout<<s<<endl;
        else cout<<"no answer"<<endl;
    }
    return 0;
}