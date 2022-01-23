/*Ma Trận xoắn ốc
https://cdn.discordapp.com/attachments/858894244553949187/863732346510901248/212681317_586886746050227_3231578418643373183_n.png*/
#include <iostream>
using namespace std;
int a[100][100];
void spiralMatrix(int n){
    int count = 0;
    int pos = 0;
    int check = n*n;//count==check thì out
    while(1){
        for(int i=pos; i<n-pos;i++){//hàng ngang trên
            count++;
            a[pos][i]=count;
            if(count==check) return;
        }
        for(int i=pos+1; i<n-pos-1; i++){//cột dọc phải
            count++;
            a[i][n-pos-1]=count;
            if(count==check) return;        
        }
        for(int i=n-pos-1; i>=pos;i--){//hàng ngang dưới
            count++;
            a[n-pos-1][i]=count;
            if(count==check) return;
        }
        for(int i=n-pos-2; i>pos; i--){//cột dọc trái
            count++;
            a[i][pos]=count;
            if(count==check) return;        
        }
        pos++;
    }
}
int main(){
    int n; cin>>n;
    spiralMatrix(n);
    for(int i=0; i<n;i++){
        for(int j=0; j<n;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}