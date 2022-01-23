//https://scontent-hkg4-2.xx.fbcdn.net/v/t1.15752-9/222640276_196058775828505_4233991861723457722_n.png?_nc_cat=111&ccb=1-3&_nc_sid=ae9488&_nc_ohc=4IJqzJh9GSQAX86uMx5&_nc_ht=scontent-hkg4-2.xx&oh=8b8106fe35c234fd6cfe9556a1c0e157&oe=6121E519
#include <bits/stdc++.h>
using namespace std;
int countNumber(int n){
    int i=0;
    while(n){
        n/=10;
        i++;
    }
    return i;
}
int pagesNumbering(int n){
    int i = countNumber(n);
    int sum=0;
    while(i){
        sum+=(n+1-pow(10,i-1));
        i--;
    }
    return sum;
}
int main(){
  int a;
  cin>>a;
  cout<<pagesNumbering(a)<<endl;
}