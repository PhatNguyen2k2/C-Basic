/*Viết chương trình nhập vào ma trận vuông cấp M (<50). Thực hiện chuyển đổi 2 đường chéo của ma trận
Input: Hàng 1 là cấp m, m hàng tiếp theo là các phần tử của ma trận
Output: Ma trận kết quả*/
#include<iostream>
using namespace std;
int main(){
    int n; cin>>n;
    int a[n][n];
    for(int i=0; i<n;i++){
        for(int j=0; j<n;j++){
            cin>>a[i][j];
        }
    }
    for(int i=0; i<n;i++){
        swap(a[i][i],a[i][n-1-i]);
    }
    for(int i=0; i<n;i++){
        for(int j=0; j<n;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}