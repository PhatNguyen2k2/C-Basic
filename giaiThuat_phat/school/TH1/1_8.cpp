//Nguyen Hoang Phat - 6151071082
#include<iostream>
using namespace std;
class vector{
    private:
        int n;
        float *v;
    public:
        vector(int size);
        vector(vector &a);
        ~vector();
        void add();
        void display();
        void operator =(vector &a);
        friend vector operator *(float k,vector &a);
};
vector::vector(int size){
    n = size;
    v = new float[n];
}
vector::vector(vector &a){
    n = a.n;
    v = new float [n];
    for (int i=0; i<n; i++)   v[i]=a.v[i];
}
vector::~vector(){
    delete v;
}
void vector::add(){
    for(int i=0; i<n; i++){
        cout<<"v["<<i<<"]: ";
        cin>>v[i];
    }
}
void vector:: operator =(vector &a){
    n = a.n;
    v = new float[n];
    for (int i=0; i<n; i++)
    v[i]=a.v[i];
}
vector operator *(float k,vector &a){
    vector c = a;
    for (int i=0; i<a.n; i++)
        c.v[i]=k*a.v[i];
    return c;
}
void vector::display(){
    for(int i=0; i<n; i++)    cout<<v[i]<<" ";
    cout<<endl;
}
int main(){
    int n;
    cout<<"Enter number of elements in vector A: "; cin>>n;
    vector a(n);
    a.add();
    a.display();
    float k;
    cout<<"Enter k: "; cin>>k;
    (k*a).display();
}