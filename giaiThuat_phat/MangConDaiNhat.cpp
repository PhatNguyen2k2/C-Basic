#include <bits/stdc++.h>
using namespace std;
int main (){
    int n;
    cin>>n;
    long long a[100];
    long long b[100];
    for (int i=1; i<=n; i++)
        cin>>a[i];
    a[0] = 0;
    b[0] = 0;
    for (int i=1; i<=n; i++)
    {
        b[i] = 1;
        for (int j=i-1; j>=1; j--)
        {
            if (a[i]>a[j])
            {
                b[i]=max(b[i], b[j]+1);
            }
        }
    }
    long long max = 1;
    for (int i=1; i<=n; i++)
        if (b[i]>=max)
            max = b[i];
    cout<<max<<endl;
}