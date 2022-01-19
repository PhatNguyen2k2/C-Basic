//https://www.hackerrank.com/challenges/climbing-the-leaderboard/problem
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin>>n;
    set<int> s;
    for (int i = 0; i < n; i++){
        int x;  cin>>x;
        s.insert(x);
    }
    cin>>m;
    vector<int> v(s.begin(), s.end());
    for (int i = 0; i < m; i++){
        int x;
        cin>>x;
        int pos = upper_bound(v.begin(), v.end(), x) - v.begin();
        cout<<v.size() - pos + 1<<endl;
    }
    return 0;
}