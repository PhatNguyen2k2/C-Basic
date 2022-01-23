/*cho một dãy a gồm n số tự nhiên. Hãy đưa ra số tự nhiên nhỏ nhất chưa xuất hiện trong dãy
Ví dụ: input: 4                         output: 3
              0 1 2 5
        input: 7                        output: 5
              0 0 1 4 2 4 3*/
#include<bits/stdc++.h>
#define faster() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define run() int T; cin>>T; cin.ignore(); while(T--)
using namespace std;
int main(){
    faster()
    set<int> arr;
    run(){
        int n; cin>>n;
        arr.insert(n);
    }
    vector<int> list;
    for(auto i : arr){
        list.push_back(i);
    }
    sort(list.begin(), list.end());
    for(int i=0; i < list.size()+1; i++){
        if(list[i]+1 != list[i+1]){
            cout<<list[i]+1<<endl;
            break;
        }
    }
}