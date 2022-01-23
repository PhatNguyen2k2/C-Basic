/*https://scontent-hkg4-1.xx.fbcdn.net/v/t1.15752-9/219320867_967369480723623_8324033281009811615_n.png?_nc_cat=105&ccb=1-3&_nc_sid=ae9488&_nc_ohc=ZV1G5h6_iU4AX-QMWgE&_nc_ht=scontent-hkg4-1.xx&oh=dae65a318a92d2156abc367e9beacd07&oe=612EABCE
https://scontent-hkg4-1.xx.fbcdn.net/v/t1.15752-9/218088685_688626662535308_6454446790429964367_n.png?_nc_cat=100&ccb=1-3&_nc_sid=ae9488&_nc_ohc=FTDpBBW5X6AAX_J54T2&_nc_ht=scontent-hkg4-1.xx&oh=3796dd7862a696636907330bdaa85a1a&oe=612F1454*/
#include<bits/stdc++.h>
#define faster() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
int main(){   
    faster()
    int n; cin>>n;
    int start[n], finish[n], temp[n];
    for(int i=1; i<=n ; i++){
        cin>>start[i]>>finish[i];
        temp[i] = false;
    }
    // greedy algorithm
    int i = 1, count = 1;
    temp[i] = true;
    for(int j = 2; j<= n; j++){
        if(finish[i] <= start[j]){
            count++;
            i = j;
            temp[i] = true;
        }
    }
    cout<<count<<endl;
    for(int i=1; i <= n; i++){
        if(temp[i]) cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}