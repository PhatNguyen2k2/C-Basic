/*Một từ trong xâu kí tự được định nghĩa là 1 dãy kí tự liên tiếp không có khoảng trống.
Hãy đếm số từ trong xâu và in kết quả ra màn hình
Ví dụ: Input: Lap trinh   C     va C++
       Output: 5 */
#include<iostream>
#include<string>
using namespace std;
int main(){
    int T;
    cin>>T;
    while(T--){
        string a;
        fflush(stdin);
        getline(cin, a);
        int count = 1; //từ đầu tiên
        for(int i=0; i< a.size()-1;i++){
            if(a[i]==' ' && a[i+1]!=' ') count++;
        }//khoảng trắng tới chữ mới tính là 1 từ
        cout<<count<<endl;
    }
}