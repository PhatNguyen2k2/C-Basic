#include<iostream>
#include<string>
using namespace std;
void enter(string input[], int &n);
void print(string output[], int n);
void add(string input[], int &n);
void remove(string input[], int &n);
void rename(string input[], int n);
void findLanguage(string input[], int n);
int main(){
    string list[20];
    int n;
    enter(list, n);
    print(list, n);
    add(list, n);
    remove(list, n);
    rename(list, n);
    findLanguage(list, n);
    return 0;
}
void enter(string input[], int &n){
    cout<<"Enter n: ";
    cin>>n;
    for(int i=0; i<n;i++){
        cout<<"Enter language "<<i+1<<endl;
        fflush(stdin);
        getline(cin, input[i]);
    }
}
void print(string output[], int n){
    for(int i=0;i<n;i++){
        cout<<output[i]<<" ";
    }
    cout<<endl;
}
void add(string input[], int &n){
    string name;
    cout<<"Enter language: ";
    fflush(stdin);
    getline(cin, name);
    input[n]= name;
    n++;
    print(input, n);
}
void remove(string input[], int &n){
    int pos;
    cout<<"Enter position u want to remove: ";
    cin>>pos;
    for(int i=pos; i<n-1;i++){
        input[i]=input[i+1];
    }
    n--;
    print(input, n);
}
void rename(string input[], int n){
    for(int i=0; i<n;i++){
        if(input[i]=="c#"){
            input[i] = "c-sharp";
        }
    }
    print(input, n);
}
void findLanguage(string input[], int n){
    string name;
    int temp = 0;
    cout<<"Enter language u want to find: ";
    fflush(stdin);
    getline(cin, name);
    for(int i=0; i<n;i++){
        if(input[i]==name){
            temp++;
        }
    }
    if(temp==0){
        cout<<"Dont have "<<name<<" in list :<";
    }else{
        cout<<"Yes, we have "<<temp<<" "<<name<< " in list :>";
    }
}