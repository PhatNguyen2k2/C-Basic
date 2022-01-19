#include<iostream>
#include<list>
using namespace std;
int main(){
    int T;
    cin>>T;
    while(T--){
        int n;
        list<int> arr;
        while(cin>>n){
            arr.push_front(n);
        }
        cin.clear();
        cin.ignore();
        for(list<int>::iterator it=arr.begin(); it!=arr.end(); it++){
            cout<<*it<<" ";
        }
        cout<<endl;
    }
}