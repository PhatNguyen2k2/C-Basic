/*Viết chương trình cho phép nhập vào mảng A có n phần tử số nguyên (2<n<100)
Đếm các phần tử chỉ xuất hiện một lần và liệt kê
input: dòng đầu nhập số phần tử, dòng 2 nhập các phần tử
ouput: dòng đầu là số các phần tử thỏa mãn, dòng 2 là các phần tử đó*/
#include <iostream>
#include <map>
using namespace std;
int main(){
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        int a[n];
        map<int, int> arr;
        for(int i=0; i<n;i++) cin>>a[i];// nhập 1 -> tiếp tục nhập 1
        for(int i=0; i<n;i++) arr[a[i]]++;/* ở vị trí 1 tăng lên 1, 
                                            nếu a[i] là 1 nữa thì tăng lên 2*/
        int count = 0;
        for(auto i : arr){
            if(i.second==1) count++;
        }
        cout<<count<<endl;
        for(auto i : arr){
            if(i.second==1) cout<<i.first<<" ";
        }
        cout<<endl;
    }
}