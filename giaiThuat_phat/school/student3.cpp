// Nguyen Hoang Phat
// 6151071082
#include<iostream>
#include<string>
using namespace std;
class Student{
    private:
        string id; //ma sinh vien
        string name; 
        int year;
        string Class;
        float average;
    public:
        float getAverage(){
            return average;
        }
        friend istream& operator>>(istream &is, Student &student);
        friend ostream& operator<<(ostream &os, const Student &student);
        bool operator < (Student s);
        bool operator > (Student s);
};
istream& operator>>(istream &is, Student &student){
    cout<<"Enter id: ";
    fflush(stdin);
    getline(is,student.id);
    cout<<"Enter name: ";
    fflush(stdin);
    getline(is,student.name);
    cout<<"Enter year: ";
    fflush(stdin);
    is>>student.year;
    cout<<"Enter class: ";
    fflush(stdin);
    getline(is,student.Class);
    cout<<"Enter average: ";
    is>>student.average;
    return is;
}
ostream& operator <<(ostream& os, const Student &student){
    os<<"Id: "<<student.id<<endl;
    os<<"Name: "<<student.name<<endl;
    os<<"Class: "<<student.Class<<endl;
    os<<"Year: "<<student.year<<endl;
    os<<"Average: "<<student.average<<endl;
    return os;
}
bool Student::operator<(Student s){
    return average < s.average;
}
bool Student::operator>(Student s){
    return year > s.year;
}
void input(Student s[], int n){
    for(int i=0; i<n; i++){
        cout<<"Enter infomation of student "<<i+1<<endl;
        cin>>s[i];
    }
}
void print(Student s[], int n){
    for(int i=0; i<n; i++){
        cout<<"Number "<<i+1<<endl;
        cout<<s[i]<<endl;
    }
}
void sortByAverage(Student s[], int n){
    Student temp;
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n;j++){
            if(s[i] < s[j]){
                temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }
}
void sortByYear(Student s[], int n){
    Student temp;
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n;j++){
            if(s[i] > s[j]){
                temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }
}
int lowAverage(Student s[], int n){
    int count = 0;
    for(int i=0; i<n;i++){
        if(s[i].getAverage()<1.0){
            count++;
        }
    }
    return count;
}
int main(){
    int n;
    cout<<"Enter n: ";  cin>>n;
    Student a[n+1];
    input(a,n);
    print(a,n);
    sortByAverage(a,n);
    cout<<"Sort by average:"<<endl;
    print(a,n);
    sortByYear(a,n);
    cout<<"Sort by year:"<<endl;
    print(a,n);
    cout<<"Number of student get warning: "<<lowAverage(a,n)<<endl;
}