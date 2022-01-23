#include<iostream>
#include<string>
using namespace std;
class Student{
	private:
		string name;
		float math;
        float literature;
        static int STT;
	public:
        Student();
		Student(string name, float math, float literature);
        Student(string name);
        Student(const Student& other);
        ~Student(){}
        float average();
        friend istream& operator>>(istream& is, Student& student);
        friend ostream& operator<<(ostream& os, Student student);
        void output();
        bool operator >(Student other);
        bool operator <(Student other);
        bool operator <=(Student other);
        bool operator >=(Student other);
        bool operator ==(Student other);
        bool operator !=(Student other);
};
int Student::STT=0;
Student::Student(){
    this->name = "";
    this->math = 0;
    this->literature = 0;
}
Student::Student(string name, float math, float literature){
    this->name = name;
    this->math = math;
    this->literature = literature;
}
Student::Student(string name){
    this->name = name;
    this->math = 0;
    this->literature = 0;
}
Student::Student(const Student& other){
    name = other.name;
    math = other.math;
    literature = other.literature;
}
istream& operator>>(istream& is, Student& student){
    student.STT++;
    cout<<"STT: "<<student.STT;
	cout<<"Enter name: ";
	getline(is, student.name);
	cout<<"Enter marks of math: ";
	is>>student.math;
	cout<<"Enter marks of literature: ";
	is>>student.literature;
    return is;
}
ostream& operator<<(ostream& os, Student student){
    student.STT++;
	os<<"STT: "<<student.STT<<"; Name: "<<student.name<<"; Math: "<<student.math<<", Literature: "<<student.literature<<endl;
    return os;
}
void Student::output(){
    cout<<"STT: "<<STT<<"; Name: "<<name<<"; Math: "<<math<<", Literature: "<<literature<<endl;
}
float Student::average(){
    return (float)((math+literature)/2.0);
}
bool Student::operator >(Student other){
    return this->average() > other.average();
}
bool Student::operator <( Student other){
    return this->average() < other.average();
}
bool Student::operator <=( Student other){
    return ((this->average() < other.average()) || (this->average() == other.average()));
}
bool Student::operator >=( Student other){
    return ((this->average() > other.average()) || (this->average() == other.average()));
}
bool Student::operator ==( Student other){
    return this->average() == other.average();
}
bool Student::operator !=( Student other){
    return this->average() != other.average();
}
int main(){
	Student a("A",6.8,4.9);
    Student b("B",8.3,3.7);
    cout<<a<<b;
    //cin>>a>>b;
	if(a>b) cout<<"Bigger"<<endl;
    if(a<b) cout<<"Smaller"<<endl;
    if(a>=b) cout<<"Bigger or equal"<<endl;
    if(a<=b) cout<<"Smaller or equal"<<endl;
    if(a==b) cout<<"Equal"<<endl;
    if(a!=b) cout<<"Not equal"<<endl;
    a=b;
    cout<<"A=B: ";
    a.output();
}