//https://scontent-hkg4-1.xx.fbcdn.net/v/t1.15752-9/224837502_254700492894828_4103716878884880282_n.png?_nc_cat=106&ccb=1-3&_nc_sid=ae9488&_nc_ohc=uNJEyYgnEkMAX_KQ3rP&tn=c-Lvvcr9_LyGospK&_nc_ht=scontent-hkg4-1.xx&oh=21e5dee2cb123749e63dcf68353cf402&oe=612A0918
#include<bits/stdc++.h>
#define faster() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define run() int N; cin>>N; cin.ignore(); while(N--)
using namespace std;
int main(){
    faster()
    vector<int> list;
    run(){
        int a; cin>>a;
        list.push_back(a);
    }
    int temp=0;
    vector<int> arr;
    for(int i=0; i < list.size(); i++){
        if(list[i]==0) temp++;
        else{
            if(temp>2){
                arr.push_back(temp);
            }
            temp=0;
        }
    }
    cout<<*std::min_element(arr.begin(), arr.end())<<endl;
}