#include<bits/stdc++.h>
using namespace std;
struct Point{
    float x, y;
};
void enter(Point *a){
    cout<<"Enter x: ";cin>>a->x;
    cout<<"Enter y: ";cin>>a->y;
}
void enterList(Point *a, int n){
    for(int i=0;i<n;i++){
        cout<<"Enter point "<<i+1<<":"<<endl;
        enter(&*(a+i));
    }
}
void print(Point *a){
    cout<<"("<<a->x<<","<<a->y<<")"<<"; ";
}
void printList(Point *a, int n){
    for(int i=0; i<n;i++){
        print((a+i));
    }
    cout<<endl;
}
float length(Point *a){
    return sqrt(pow(a->x,2)+pow(a->y,2));
}
void swap(Point &a, Point &b){
    Point temp;
    temp = a;
    a = b;
    b = temp;
}
void QuickSort(Point *a, int left, int right){
    Point x = *(a+((left + right)/2));
    int i = left, j = right;
    do{
        while(length((a+i)) < length(&x)) 
            i++;
        while (length((a+j)) > length(&x))
            j--;
        if(i <= j){
            swap(*(a+i),*(a+j));
            i++;
            j--;
        }
    }while(i < j);
    if(left < j)
        QuickSort(a,left,j);
    if(right > i)
        QuickSort(a,i,right);
}
void find(Point *a, int n, int R){
    cout<<"Points inside a circle with center O and radius R: "<<endl;
    for(int i=0;i<n;i++){
        if(length((a+i))<R) print(a+i);
    }
    cout<<endl;
}
void findX(Point *a, int n){
    for(int i=0; i<n-1; i++){
        if(((a+i)->x>0 && (a+i)->y>0) || ((a+i)->x<0 && (a+i)->y>0)){
            for(int j=i+1; j<n; j++){
                if(((a+j)->x>0 && (a+j)->y>0) || ((a+j)->x<0 && (a+j)->y>0)){
                    if((a+i)->y == (a+j)->y){
                        cout<<endl;
                        print((a+i));
                        print((a+j));
                    }
                }
            }
        }
    }
}
void findD(Point *a, int n, int d){
    int count=0;
    for(int i=0;i<n;i++){
        if(length(a+i) == d) {
            print(a+i);
            count++;
        }
    }
    if(count==0) cout<<"Not found any point equal "<<d<<endl;
}
int main(){
    int n;
    cout<<"Enter number of points: ";cin>>n;
    Point *a = new Point[n];
    enterList(a,n);
    QuickSort(a,0,n-1);
    printList(a,n);
    float R;
    cout<<"Enter radius: ";   cin>>R;
    find(a,n,R);
    cout<<"Pairs of points lying on either side of the horizontal axis: ";
    findX(a,n);
    float d;
    cout<<endl<<"Enter d: ";    cin>>d;
    cout<<"Points have distance equal d: ";
    findD(a,n,d);
    delete[] a;
    return 0;
}