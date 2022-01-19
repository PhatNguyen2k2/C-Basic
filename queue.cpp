#include <iostream>
#include <string>
#include <queue>
using namespace std;
void enter(queue<string> &arr);
void add(queue<string> &arr);
void remove(queue<string> &arr);
void find(queue<string> arr);
void print(queue<string> arr);
int main(){
    queue<string> list;
    enter(list);
    print(list);
    add(list);
    print(list);
    remove(list);
    print(list);
    find(list);
}
void enter(queue<string> &arr){
    string name;
    int n;
    cout<<"Enter n: ";
    cin>>n;
    while(n--){
        cout<<"Enter info "<<n<<endl;
        fflush(stdin);
        getline(cin, name);
        arr.push(name);
    }
}
void add(queue<string> &arr){
    string name;
    cout<<"Enter info: ";
    fflush(stdin);
    getline(cin, name);
    arr.push(name);
}
void remove(queue<string> &arr){
    arr.pop();
}
void find(queue<string> arr){
    vector<string> list;
    string name;
    bool check = false;
    while(!arr.empty()){
        list.push_back(arr.front());
        arr.pop();
    }
    cout<<"Enter disc u want to find: ";
    fflush(stdin);
    getline(cin, name);
    for(int i=0; i<list.size(); i++){
        if(list[i] == name){
            check = true;
        }
    }
    if(check){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
}
void print(queue<string> arr){
    while(!arr.empty()){
        cout<<arr.front()<<" ";
        arr.pop();
    }
    cout<<endl;
}//meow