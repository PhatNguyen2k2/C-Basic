#include<iostream>
#include<string>
using namespace std;
class Student{
	private:
		string name;
		float math;
        float literature;
	public:
		void input();
		void print();
		string getName();
		float getMath();
		float getLiterature();
		void setName(string name);
		void setMath(float math);
		void setLiterature(float literature);
		float average();
		void classification();	
};
void Student :: input(){
	cout<<"Enter name: ";
	getline(cin, name);
	cout<<"Enter marks of math: ";
	cin>>math;
	cout<<"Enter marks of literature: ";
	cin>>literature;
}
void Student :: print(){
	cout<<"Name: "<<name<<"; Math: "<<math<<", Literature: "<<literature<<endl;
}
string Student :: getName(){
	return this->name;
}
float Student :: getMath(){
	return this->math;
}
float Student :: getLiterature(){
	return this->literature;
}
void Student :: setName(string name){
	this->name=name;
}
void Student :: setMath(float math){
	this->math=math;
}
void Student :: setLiterature(float literature){
	this->literature=literature;
}
float Student :: average(){
	return (float)((math + literature)/2);
}
void Student::classification(){
	if(average() >= 8.0)
		cout<<"Verry good"<<endl;
	else if(average() >= 7.0)
		cout<<"Good"<<endl;
	else if(average() >= 5.0)
		cout<<"Medium"<<endl;
	else cout<<"Weak"<<endl;		
 
}
int main(){
	Student a;
	string name;
	float math, literature;
	a.input();
	a.print();
	cout<<"Average: "<<a.average();
	cout<<endl<<"Classification: ";
	a.classification();
	cout<<"Enter new name: ";
    fflush(stdin);
	getline(cin, name);
	cout<<"Enter new marks of math: ";
	cin>>math;
	cout<<"Enter new marks of literature: ";
	cin>>literature;
	a.setName(name);
	a.setMath(math);
	a.setLiterature(literature);
    cout<<"-->New information:"<<endl;
	a.print();
}