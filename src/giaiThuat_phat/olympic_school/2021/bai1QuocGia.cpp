#include<bits/stdc++.h>
using namespace std;

int dd[1001]= {0};
int F1, F2;
struct point{
    int x,y;
};
int distance(point a, point b){
    return sqrt(pow(a.x-b.x, 2) + pow(a.y-b.y, 2));
}
void truyvet(point x[], int n, int d, int f0){
    for(int i=1; i<=n; i++){
        if(dd[i]==0 && distance(x[f0], x[i])<d){
            F1++;
            dd[i] = 1;
        }
    }
    for(int i=1; i<=n; i++){
        if(dd[i]==1)
            for(int j=1; j<=n; j++){
                if(dd[j]==0 && distance(x[i], x[j])<d){
                    F2++;
                    dd[j] = 3;
                }
            }
    }
}
int main(){
    int n, d, f0;
    cin >> n >> f0 >> d;
    point a[n+1];
    for(int i=1; i<=n;i++){
        cin >> a[i].x >> a[i].y;
    }
    dd[f0] = 2;
    truyvet(a, n, d, f0);
    cout<<F1<<" "<<F2;
    return 0;
}