#include <bits/stdc++.h>
using namespace std;

long long Tribon(long n){
   if(n==0||n==1) return 0;
   if(n==2||n==3) return 1;
   long a=0,b=0,c=1;
   long curr;
   for(int i=3;i<n;i++){
      curr=a+b+c;
      a=b;
      b=c;
      c=curr;
   }
   return curr;
}
long long solve(long n){
   int k=1;
   if(n==1||n==2) return n;
   while(Tribon(k)<n){
      k++;
   }
   return Tribon(k);
}
int main() {
   long n;
   int cz=0;
   while(cz<100&&cin>>n){
      cout<<solve(n)<<endl;
      cz++;
   }
}