/*kiểm tra 1 mảng có gồm phần tử bị lặp lại hay không?
ví dụ:
1 2 2 3 4 5
trả về true vì lặp lại giá trị 2 liên tiếp ở vị trí 1 và 2
1 2 3 4 5 4
trả về true vì 2 phần tử 4 lặp lại
1 2 3 4
trả về false vì không có 2 phần tử lặp lại*/
#include <bits/stdc++.h>
#define faster() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define run() int T; cin>>T; cin.ignore(); while(T--)
using namespace std;
// int main(){
//     faster()
//     vector<int> arr;
//     run(){
//         int n; cin>>n;
//         arr.push_back(n);
//     }
//     sort(arr.begin(), arr.end());
//     bool found = false;
//     for(int i=0; i< arr.size()+1; i++){
//         if(arr[i]==arr[i+1]){
//             found = true;
//             break;
//         }
//     }
//     if(found){
//         cout<<"YES"<<endl;
//     }else cout<<"NO"<<endl;
// }
int main(){
    faster()
    vector<int> arr;
    run(){
        int n; cin>>n;
        arr.push_back(n);
    }
    bool found = false;
    int a = arr.size();
    for(int i=0; i< a; i++){
        int k = arr[a-1];
        arr.pop_back();
        if(binary_search(arr.begin(), arr.end(), k)){
            found = true;
            break;
        }
    }
    if(found){
        cout<<"YES"<<endl;
    }else cout<<"NO"<<endl;
}