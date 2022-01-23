// I chỉ đứng trước V, X; X chỉ đứng trước L, C; C chỉ đứng trước D, M.
#include<iostream>
#include<string>
using namespace std;
int main(){
    int T;
    cin >> T;
    while(T--){
        string str;
        int num[100];
        cin>>str;
        for(int i=0; i<str.size();i++){
            switch(str[i]){
                case 'I': num[i] = 1; break;
                case 'V': num[i] = 5; break;
                case 'X': num[i] = 10; break;
                case 'L': num[i] = 50; break;
                case 'C': num[i] = 100; break;
                case 'D': num[i] = 500; break;
                case 'M': num[i] = 1000; break;
            }
        }
        int sum = 0;
        for(int i = 0; i < str.size()-1; i++){
            if(num[i]>num[i+1]) sum += num[i];
            else sum -= num[i]; 
        }
        sum += num[str.size()-1];
        cout<<sum<<endl;
    }
}
