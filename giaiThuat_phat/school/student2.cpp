#include<iostream>
#include<string>
using namespace std;
struct Student{
	string name;
	int ID;
	string date;
	float GPA;
	string Class;
	string major;
};
struct Node{
	Student data;
	Node *next;
};
struct Slist{
	Node* head;
	Node* tail;
	long size;
 
	Slist();
 
	Node* CreateNode(Student s);
	void insertStudent(Student s);
	void findID();
	void findName();
	void findDate();
	void majorStatistics();
	void classStatistics();
	void findhighestGPA();
	void findlowestGPA();
	void countMajor();
	void deleteDuplicate();

	void infoStudent(Student &s);
	void input(int &n);
    void print(Node *p);
	void traverse();
};
Slist::Slist(){
	head=NULL;
	tail=NULL;
	size=0;	
}
Node* Slist::CreateNode(Student s){
	Node* p=new Node;
	p->data=s;
	p->next=NULL;
	return p;
}
void Slist::infoStudent(Student &s){
	fflush(stdin);
	cout<<"Enter name: ";
	getline(cin,s.name);
	fflush(stdin);
	cout<<"Enter ID: ";
	cin>>s.ID;
	cout<<"Enter date of birth: ";
    fflush(stdin);
	getline(cin,s.date);
    cout<<"Enter GPA: ";
    fflush(stdin);
    cin>>s.GPA;
	cout<<"Enter class name: ";
    fflush(stdin);
	getline(cin,s.Class);
	cout<<"Enter major:";
    fflush(stdin);
	getline(cin,s.major);
}
void Slist::insertStudent(Student s){
	Node *temp=CreateNode(s);
    if(size == 0){
        head = tail = temp;
        size++;
    }else{
        tail->next=temp;
        tail=temp;
        size++;
    }
}
void Slist::input(int &n){
	Student a;
	cout<<"Enter number of students:";
	cin>>n;
	for(int i=0;i<n;i++){
		cout<<"-->Information of student "<<i<<endl;
		infoStudent(a);
		insertStudent(a);
	}
}
void Slist::findID(){
    int id_find;
    cout<<"Enter id need to find: ";
    cin>>id_find;
    Node *a = head;
    while(a->data.ID!=id_find){
        if(a->next == NULL){
            cout<<"No such student has been found"<<endl;
            return;
        }
        a=a->next;
    }
    print(a);
}
void Slist::findName(){
    string name_find;
    cout<<"Enter name need to find: ";
    fflush(stdin);
    getline(cin,name_find);
    Node *a = head;
    while(a->data.name != name_find){
        if(a->next == NULL){
            cout<<"No such student has been found"<<endl;
            return;
        }
        a=a->next;
    }
    print(a);
}
void Slist::findDate(){
    string date_find;
    cout<<"Enter birthday need to find: ";
    fflush(stdin);
    getline(cin, date_find);
    Node *a = head;
    while(a->data.date != date_find){
        if(a->next == NULL){
            cout<<"No such student has been found"<<endl;
            return;
        }
        a=a->next;
    }
    print(a);
}
void Slist::majorStatistics(){
    Node *a = head;
    Student c[size];
    int i = 0, count = 0;
    while(a != NULL){
        c[i]=a->data;
        i++;
        a = a->next;
    }
    for(int i=0; i<size-1;i++){
        for(int j=i+1; j<size;j++){
            if(c[i].major>c[j].major){
                swap(c[i],c[j]);
            }
        }
    }
    cout<<"--->Major "<<c[0].major<<endl;
    for(int i = 0; i<size; i++){
        cout<<"name: "<<c[i].name<<endl;
        cout<<"ID: "<<c[i].ID<<endl;
        cout<<"date of birth: "<<c[i].date<<endl;
        cout<<"GPA: "<<c[i].GPA<<endl; 
        cout<<"Class: "<<c[i].Class<<endl;
        cout<<"Major: "<<c[i].major<<endl;
        count++;
        if(c[i+1].major!=c[i].major){
            cout<<"Major "<<c[i].major<<" has "<<count<<" students"<<endl;
            count = 0;
            if(i<size-1){
                cout<<"--->Major "<<c[i+1].major<<endl;
            }
        }
    }
}
void Slist::classStatistics(){
    Node *a = head;
    Student c[size];
    int i = 0, count = 0;
    while(a != NULL){
        c[i]=a->data;
        i++;
        a = a->next;
    }
    for(int i=0; i<size-1;i++){
        for(int j=i+1; j<size;j++){
            if(c[i].Class>c[j].Class){
                swap(c[i],c[j]);
            }
        }
    }
    cout<<"--->Class "<<c[0].Class<<endl;
    for(int i = 0; i<size; i++){
        cout<<"name: "<<c[i].name<<endl;
        cout<<"ID: "<<c[i].ID<<endl;
        cout<<"date of birth: "<<c[i].date<<endl;
        cout<<"GPA: "<<c[i].GPA<<endl; 
        cout<<"Class: "<<c[i].Class<<endl;
        cout<<"Major: "<<c[i].major<<endl;
        count++;
        if(c[i+1].Class!=c[i].Class){
            cout<<"Class "<<c[i].Class<<" has "<<count<<" students"<<endl;
            count = 0;
            if(i<size-1){
                cout<<"--->Class "<<c[i+1].Class<<endl;
            }
        }
    }
}
void Slist::findhighestGPA(){
    Node* a = head;
    Node* cur = head->next;
    while(cur != NULL){
        if(cur->data.GPA > a->data.GPA){
            a = cur;
        }
        cur = cur->next;
    }
    cout<<"==Student has highest GPA:"<<endl;
    print(a);
}
void Slist::findlowestGPA(){
    Node* a = head;
    Node* cur = head->next;
    while(cur != NULL){
        if(cur->data.GPA < a->data.GPA){
            a = cur;
        }
        cur = cur->next;
    }
    cout<<"==Student has lowest GPA:"<<endl;
    print(a);
}
void Slist::countMajor(){
    Node *a = head;
    Student c[size];
    int i = 0, count = 0;
    while(a != NULL){
        c[i]=a->data;
        i++;
        a = a->next;
    }
    for(int i=0; i<size-1;i++){
        for(int j=i+1; j<size;j++){
            if(c[i].major>c[j].major){
                swap(c[i],c[j]);
            }
        }
    }
    cout<<"<--->Major "<<c[0].major;
    for(int i = 0; i<size; i++){
        count++;
        if(c[i+1].major!=c[i].major){
            cout<<" has "<<count<<" students"<<endl;
            count = 0;
            if(i<size-1){
                cout<<"<--->Major "<<c[i+1].major;
            }
        }
    }
}
void Slist::deleteDuplicate(){
    Node* meo = head;
    Node* del;
    while(meo != NULL){
        Node* pre = meo;
        Node* cur = meo->next;
        while(pre != NULL && cur != NULL){
            if(meo->data.name == cur->data.name){
                del = cur;
                cur = cur->next;
                pre->next = cur;
                delete del;
                size--;
            }else{
                pre = pre->next;
                cur = cur->next;
            }
        }
        meo = meo->next;
        if(meo == tail) break;
    }
}
void Slist::print(Node *s){
    cout<<"name: "<<s->data.name<<endl;
    cout<<"ID: "<<s->data.ID<<endl;
    cout<<"date of birth: "<<s->data.date<<endl;
    cout<<"GPA: "<<s->data.GPA<<endl; 
    cout<<"Class: "<<s->data.Class<<endl;
    cout<<"Major: "<<s->data.major<<endl;
}
void Slist::traverse(){
	Node *p=head;
	cout<<"Information of students:"<<endl;
	while(p!=NULL){
		print(p);
		p=p->next;
	}
	delete p;
}
int main(){
	Slist slist;
	int n;
	slist.input(n);
	slist.traverse();
    slist.findID();
    slist.findName();
    slist.findDate();
    slist.majorStatistics();
    slist.classStatistics();
    slist.findhighestGPA();
    slist.findlowestGPA();
    slist.countMajor();
    slist.deleteDuplicate();
    slist.traverse();
	return 0;
}