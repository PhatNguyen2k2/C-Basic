/*Nhập 2 mảng (a,N) và (b, M) và số nguyên p (0<=p<M<=N<100). Hãy chèn mảng b vào
vị trí p của mảng a
input: Dòng đầu ghi số bộ test, mỗi bộ test gồm 3 dòng: dòng đầu ghi 3 số N, M, p
       Dòng 2 ghi n số của mảng a. Dòng 3 ghi M số mảng b*/
#include<iostream>
using namespace std;
int main(){
    int T;
    cin >> T;
    while(T--){
        int n, m, p;
        cin>>n>>m>>p;
        int a[n], b[m];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<m;i++){
            cin>>b[i];
        }
        for(int i=0;i<n;i++){
            if(i==p){
                for(int j=0;j<m;j++){
                    cout<<b[j]<<" ";
                }
            }
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
}