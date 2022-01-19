/*Tam giác số:
https://cdn.discordapp.com/attachments/858894244553949187/863350591908347914/211873203_2898980537096634_3258095771815234159_n.png*/
#include<iostream>
using namespace std;
int main(){
    int n, temp = 1;
    cin>>n;
    for(int i=0; i<n;i++){
        for(int j=1; j<=temp;j++) cout<<j;
        temp +=2;
        cout<<endl;
    }
}