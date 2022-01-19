//Nguyen Hoang Phat - 6151071082
#include <iostream>
using namespace std;
class Student{
    private:
        string name;
        float mark1,mark2;
        float average;
    public:
        Student ();
        void input ();
        void output();
        bool operator > (Student a);
};
Student::Student (){
    name = "";
    mark1 = 0;
    mark2 = 0;
    average = 0;
}
void Student::input (){
    fflush(stdin);
    cout <<"Enter name: ";
    getline(cin,name);
    cout <<"Enter mark of semester 1: ";
    cin >> mark1;
    cout <<"Enter mark of semester 2: ";
    cin >> mark2;
    average = (mark1+mark2*2)/3;
}
void Student::output(){
    cout <<"Name: "<<name<<" || Semester 1: "<<mark1<<" || Semester 2: "<<mark2<<" || Average: "<<average<<endl;
}
bool Student:: operator > (Student a){
    return average>a.average;
}
void input(Student a[], int n){
    for(int i=0; i<n; i++){
        cout <<endl<<"Enter student " << i+1 << endl ;
        a[i].input() ;
    } 
}
void output(Student a[], int n){
    for(int i=0; i<n; i++){
        cout <<endl<<"Student " << i+1 << ": " ;
        a[i].output();
    }
}
void compare (Student a,Student b){
    if (a > b){
        cout <<"Average of student 1 is bigger than average of student 2"<<endl;
    }else {
        cout <<"Average of student 1 is smaller than or equal average of student 2"<<endl;
    }
}
void sort(Student a[], int n){
    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            if (a[j] > a[i]){
                swap(a[i], a[j]);
            }
        }
    }
}
int main (){
    Student sv1;
    Student sv2;
    cout <<"Student 1: "<<endl;
    sv1.input(); 
    cout <<"Student 2: "<<endl;
    sv2.input();
    sv1.output();
    sv2.output();
    compare (sv1, sv2);
    Student s[5];
    input(s,5);
    output(s,5);
    cout <<endl<<"After sort"<<endl;
    sort(s,5);
    output(s,5);
    return 0;
}