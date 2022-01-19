//https://scontent-hkg4-2.xx.fbcdn.net/v/t1.15752-9/220972008_1227046661077779_7090186196437096459_n.png?_nc_cat=111&ccb=1-3&_nc_sid=ae9488&_nc_ohc=q_vA5aOMIWQAX8gNFos&_nc_ht=scontent-hkg4-2.xx&oh=88be6831a6e90d9cb19075dd9fef171b&oe=612B63D1
#include<bits/stdc++.h>
using namespace std;
int main(){
    int N, i = 1, sum = 0;
    cin>>N;
    while(1){
       sum +=log(i);
       if(round(sum)==N){
           cout<<i<<endl;
           break;
       }
       if(round(sum)>N){
           cout<<-1<<endl;
           break;
       }
       i++;
    }
}