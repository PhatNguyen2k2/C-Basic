#include <iostream>
#include <string>
#include <vector>
using namespace std;
void enter(vector<string> &arr);
void add(vector<string> &arr);
void print(vector<string> arr);
int main(){
    vector<string> list;
    enter(list);
    print(list);
    add(list);
    print(list);
}
void enter(vector<string> &arr){
    string a;
    int n;
    cout<<"Enter n: ";
    cin>>n;
    while(n--){
        cout<<"Enter animal "<<n<<endl;
        fflush(stdin);
        getline(cin, a);
        arr.push_back(a);
    }
}
void add(vector<string> &arr){
    string name;
    bool check;
    do{
        check = true;
        cout<<"Enter animal: ";
        fflush(stdin);
        getline(cin, name);
        for(int i=0; i<arr.size(); i++){
            if(arr[i] == name){
                check = false;
            }
        }
        if(!check){
            cout<<"-->Bị trùng ròi, hong thêm vô đâu :))"<<endl;
        }
    }while(!check);
    arr.push_back(name);
}
void print(vector<string> arr){
    vector<string>::iterator it;
    for(it=arr.begin(); it!=arr.end(); it++){
        cout<<*it<<" ";
    }
    cout<<endl;
}