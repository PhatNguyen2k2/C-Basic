#include<iostream>
using namespace std;
class Person{
    private:
        string name;
        int age;
        string address;
    public:
        void input1();
        void output1();
        string getName();
};
class Student: public Person{
    private:
        string id;
        float score;
    public:
        void input2();
        void output2();
        void rank();
};
class Teacher: public Person{
    public:
        void teach();
};
void Person::input1(){
    cout<<"Name: ";
    fflush(stdin);
    getline(cin, name);
    fflush(stdin);
    cout<<"Age: ";
    cin>>age;
    cout<<"Address: ";
    fflush(stdin);
    getline(cin, address);
}
void Person::output1(){
    cout<<"Name: "<<name<<", Age: "<<age<<", Address: "<<address<<endl;
}
void Student::input2(){
    input1();
    cout<<"Id: ";
    fflush(stdin);
    getline(cin, id);
    cout<<"Score: ";
    fflush(stdin);
    cin>>score;
}
void Student::output2(){
    cout<<"Id: "<<id<<", Score: "<<score<<endl;
    output1();
}
void Student::rank(){
    if(score>= 8.0)   cout<<"Verry Good"<<endl;
    else if(score>=7.0)  cout<<"Good"<<endl;
    else if(score>=5.0) cout<<"Medium"<<endl;
    else cout<<"Weak"<<endl;
}
string Person::getName(){
    return name;
}
void Teacher::teach(){
    if(getName()=="Dung")   cout<<"K62"<<endl;
    else if(getName()=="Mien")  cout<<"K61"<<endl;
    else if(getName()=="Minh")  cout<<"K60"<<endl;
    else    cout<<"K59"<<endl;
}
int main(){
    Student a;
    a.input2();
    a.output2();
    cout<<"Rank: ";
    a.rank();
    Teacher b;
    b.input1();
    b.output1();
    b.teach();
}