/*https://scontent.fdad3-2.fna.fbcdn.net/v/t1.15752-9/226906182_335342394991150_2192720872163822781_n.png?_nc_cat=101&ccb=1-3&_nc_sid=ae9488&_nc_ohc=hR5S5IvUFc4AX-8hN1P&_nc_ht=scontent.fdad3-2.fna&oh=02c6100f473f4cc374c4b6164a3c1903&oe=6129D8C5
(không đếm kí tự trùng)*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    string s1, s2;
    cin>>s1>>s2;
    set<char>str1,str2;
    for(int i=0; i <s1.length(); i++) str1.insert(s1[i]);
    for(int i=0; i <s2.length(); i++) str2.insert(s2[i]);
    int count = 0;
    for(auto i : str1) {
        if(std::find(str2.begin(), str2.end(), i) != str2.end()) count++;
    }
    cout<<count<<endl;
}